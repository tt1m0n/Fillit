/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:44:17 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/23 23:44:19 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*write_one_tetr(t_figure *tetramino, char *str)
{
	int i;
	int tmpx;
	int tmpy;
	int k;
	int first;

	i = 0;
	k = 0;
	first = 0;
	while (i != 20)
	{
		if (str[i] == '#')
		{
			if (first == 0)
			{
				tmpx = i / 5;
				tmpy = i % 5;
			}
			tetramino->x[k] = i / 5 - tmpx;
			tetramino->y[k++] = i % 5 - tmpy;
			first++;
		}
		i++;
	}
	return (tetramino);
}

t_figure	**write_figures(t_figure **tetramino, char *str)
{
	size_t i;
	size_t j;
	size_t count;

	i = 0;
	j = 0;
	count = (ft_strlen(str) + 1) / 21;
	tetramino = (t_figure**)malloc(sizeof(t_figure*) * count);
	while (j < count && str[i])
	{
		tetramino[j] = (t_figure*)malloc(sizeof(t_figure));
		tetramino[j] = write_one_tetr(tetramino[j], &str[i]);
		j++;
		i = i + 21;
	}
	return (tetramino);
}
