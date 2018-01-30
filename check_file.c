/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:06:50 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/27 13:30:45 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *str)
{
	char	buf[BUF_SIZE];
	char	*p;
	int		fd;
	int		len;
	int		i;

	i = -1;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(0);
	}
	len = read(fd, buf, BUF_SIZE);
	buf[len] = '\0';
	close(fd);
	p = (char*)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (++i < len)
		p[i] = buf[i];
	p[i] = '\0';
	return (p);
}

int		check_contacts_figure(char *s, int j, int i)
{
	int	contact;

	contact = 0;
	while (s[i])
	{
		if ((s[i] == '\n') && ((s[i + 1] == '\n') || s[i + 1] == '\0'))
		{
			if (contact < 5)
				return (0);
			j = -2;
			contact = 0;
		}
		if (s[i] == '#' && s[i - 1] == '#')
			contact++;
		if (s[i] == '#' && s[i + 1] == '#')
			contact++;
		if (s[i] == '#' && j % 19 <= 13 && s[i + 5] == '#')
			contact++;
		if (s[i] == '#' && j % 19 >= 3 && s[i - 5] == '#')
			contact++;
		i++;
		j++;
	}
	return (1);
}

int		check_if_figures_are_valid(char *s)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 0;
	tmp = 0;
	while (s[i])
	{
		if ((s[i] == '\n') && ((s[i + 1] == '\n') || s[i + 1] == '\0'))
			j = -2;
		if ((j % 19 >= 0 && j % 19 <= 3 && s[i] == '#') &&
			(s[i - 1] != '#' && s[i + 1] != '#' && s[i + 5] != '#'))
			return (0);
		else if ((j % 19 >= 15 && j % 19 <= 18 && s[i] == '#') &&
			(s[i - 1] != '#' && s[i + 1] != '#' && s[i - 5] != '#'))
			return (0);
		else if ((s[i] == '#') && (s[i - 1] != '#' && s[i + 1] != '#' &&
			s[i + 5] != '#' && s[i - 5] != '#'))
			return (0);
		i++;
		j++;
	}
	return (1);
}

int		check_if_file_is_valid(char *str)
{
	int		i;
	int		sharp;
	int		dots;

	i = -1;
	sharp = 0;
	dots = 0;
	while (str[++i])
	{
		if ((str[i] == '\n') && ((str[i + 1] == '\n') || str[i + 1] == 0))
		{
			if (dots != 12 || sharp != 4)
				return (0);
			dots = 0;
			sharp = 0;
		}
		if (str[i] == '#')
			sharp++;
		else if (str[i] == '.')
			dots++;
		else if (str[i] != '\n')
			return (0);
	}
	return (check_if_figures_are_valid(str) == 0) ||
	(check_contacts_figure(str, 0, 0) == 0) || i == 0 ? 0 : 1;
}
