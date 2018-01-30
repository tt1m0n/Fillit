/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:09:43 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/23 23:09:50 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUF_SIZE 4096

typedef struct	s_figure
{
	int			x[4];
	int			y[4];
}				t_figure;

typedef	struct	s_square
{
	char		**s;
	int			x;
	int			y;
	int			*xt;
	int			*yt;
	int			size;
}				t_square;

void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
void			ft_putstr(const char *s);
int				check_if_figures_are_valid(char *s);
int				check_if_file_is_valid(char *str);
char			*read_file(char *str);
int				size_of_side(char *str);
t_square		*make_square(int size_side);
size_t			ft_strlen(const char *s);
int				s_t(t_square *ms, t_figure **t, int num, int count);
t_figure		**write_figures(t_figure **tetramino, char *str);

#endif
