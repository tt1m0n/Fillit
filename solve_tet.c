/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:29:33 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/05 13:58:29 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(t_square *sq, int size)
{
	int dot;
	int str;

	dot = 0;
	str = 0;
	while (str < size)
	{
		while (dot < size)
		{
			ft_putchar(sq->s[str][dot]);
			dot++;
		}
		ft_putchar('\n');
		dot = 0;
		str++;
	}
}

int		issafe(t_square *ms, t_figure **t, int num)
{
	int j;
	int i;
	int a;

	j = ms->x;
	i = ms->y;
	a = 0;
	if (ms->s[j][i] == '.')
	{
		while (a < 4 && (j + t[num]->x[a] < ms->size) &&
		(i + t[num]->y[a] < ms->size) && (j + t[num]->x[a] >= 0) &&
		(ms->s[j + t[num]->x[a]][i + t[num]->y[a]] == '.') &&
		(i + t[num]->y[a] >= 0))
		{
			ms->s[j + t[num]->x[a]][i + t[num]->y[a]] = 'A' + num;
			a++;
		}
		if (a == 4)
			return (1);
		while (--a >= 0)
			ms->s[j + t[num]->x[a]][i + t[num]->y[a]] = '.';
	}
	return (0);
}

int		backtrack(t_square *ms, t_figure **t, int num, int count)
{
	int a;

	if (issafe(ms, t, num))
	{
		ms->xt[num] = ms->x;
		ms->yt[num] = ms->y;
		num++;
		if (s_t(ms, t, num, count))
			return (1);
		num--;
		a = 3;
		while (a >= 0)
		{
			ms->s[ms->xt[num] + t[num]->x[a]][ms->yt[num] + t[num]->y[a]] = '.';
			a--;
		}
	}
	return (0);
}

int		s_t(t_square *ms, t_figure **t, int num, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (num == count)
	{
		print_solution(ms, ms->size);
		return (1);
	}
	while (j < ms->size)
	{
		while (i < ms->size)
		{
			ms->x = j;
			ms->y = i;
			if (backtrack(ms, t, num, count) == 1)
				return (1);
			i++;
		}
		i = 0;
		j++;	
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char		*str;
	t_figure	**tet;
	int			size;

	tet = NULL;
	if (argc == 2)
	{
		str = read_file(argv[1]);
		size = size_of_side(str) - 1;
		if (size == -1)
			return (0);
		tet = write_figures(tet, str);
		if (ft_strlen(str) > 545 || !check_if_file_is_valid(str))
		{
			ft_putstr("error\n");
			return (0);
		}
		while (1)
			if (s_t(make_square(++size), tet, 0, (ft_strlen(str) + 1) / 21))
				break ;
	}
	else
		ft_putstr("usage: ./fillit filename\n");
	return (0);
}
