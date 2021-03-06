/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:13:07 by ahusk             #+#    #+#             */
/*   Updated: 2021/02/28 18:49:30 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		ft_kost(int mult)
{
	if (mult < 0)
		return (0);
	return (-1);
}

int				ft_atoip(const char *str)
{
	long long	mult;
	long long	nb;

	mult = 1;
	nb = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\v') || (*str == '\f')\
			|| (*str == '\r') || (*str == '\n') || (((*str < '0') || (*str > '9')) && (*str != '-')))
		str++;
	if (*str == '-')
	{
		str++;
		mult = -1;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if ((*str < '0') || (*str > '9'))
			return (nb * mult);
		if (nb > nb * 10 + (*str - '0') && nb != 214748364)
			return (ft_kost(mult));
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return ((int)(nb * mult));
}

void			check_name(char *l, int *i, char *name)
{
	char		tmp[21];

	while (l[++(*i)] != ';' && *i != 21)
		tmp[*i] = l[*i];
	tmp[*i] = '\0';
	if (ft_strcmp(tmp, name))
		ft_error(l);
}

void			check_arg(char *l, int *i, int num)
{
	int			tz;

	tz = 0;
	while (tz != num && l[++(*i)])
	{
		if (l[*i] == ';')
			tz++;
		else if ((l[*i] < '0' || l[*i] > '9') && l[*i] != '-' && l[*i] != ' ')
			ft_error(l);
	}
	if (tz < num)
		ft_error(l);
}

void			check_line(char *l, char *name, int num)
{
	int			i;

	i = -1;
	check_name(l, &i, name);
	check_arg(l, &i, num);
}

void			parser(char *l)
{
	if (l[0] == 's')
		check_line(l, "sphere", 9);
	else if (l[0] == 'c' && l[1] == 'o')
		check_line(l, "cone", 10);
	else if (l[0] == 'c' && l[1] == 'y')
		check_line(l, "cylinder", 9);
	else if (l[0] == 'h' && l[1] == 'y')
		check_line(l, "hyperboloid", 10);
	else if (l[0] == 'd')
		check_line(l, "dot_source", 4);
	else if (l[0] == 'p')
		check_line(l, "plane", 9);
	else
		ft_error(l);
}

void			validation(char *fname)
{
	char		*l;
	int			fd;

	l = NULL;
	fd = open(fname, O_RDWR);
	if (fd < 0)
		ft_error(l);
	while (get_next_line(fd, &l))
	{
		parser(l);
		free(l);
	}
	close(fd);
}
