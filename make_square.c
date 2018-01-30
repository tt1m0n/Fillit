/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:22:01 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/23 23:23:32 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			size_of_side(char *str)
{
	int size_side;
	int count;

	size_side = 2;
	count = (ft_strlen(str) + 1) / 21;
	if (count == 0 || (ft_strlen(str) + 1) % 21 != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	while (size_side * size_side < count * 4)
	{
		size_side++;
	}
	return (size_side);
}

void		str_allocate(t_square *m_sq, int size_side)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < size_side)
	{
		m_sq->s[i] = (char*)malloc(sizeof(char) * size_side);
		if (m_sq->s[i] == NULL)
		{
			while (i-- > 0)
				free(m_sq->s[i]);
			free(m_sq->s);
			free(m_sq);
			return ;
		}
		while (tmp < size_side)
		{
			m_sq->s[i][tmp] = '.';
			tmp++;
		}
		i++;
		tmp = 0;
	}
}

t_square	*make_square(int size_side)
{
	int			i;
	int			tmp;
	t_square	*m_sq;

	m_sq = (t_square*)malloc(sizeof(t_square));
	if (!m_sq)
		return (NULL);
	m_sq->x = 0;
	m_sq->y = 0;
	i = m_sq->x;
	tmp = m_sq->y;
	m_sq->s = (char**)malloc(sizeof(char*) * size_side);
	if (!m_sq->s)
		return (NULL);
	str_allocate(m_sq, size_side);
	if (!m_sq)
		return (NULL);
	m_sq->xt = (int*)malloc(sizeof(int) * size_side);
	if (!m_sq->xt)
		return (NULL);
	m_sq->yt = (int*)malloc(sizeof(int) * size_side);
	if (!m_sq->yt)
		return (NULL);
	m_sq->size = size_side;
	return (m_sq);
}
