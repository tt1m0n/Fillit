/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:41:08 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/23 23:41:10 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	int		i;

	if (s == NULL)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t			i;
	unsigned char	*st;

	st = (unsigned char*)s;
	i = 0;
	while (st[i])
		i++;
	return (i);
}
