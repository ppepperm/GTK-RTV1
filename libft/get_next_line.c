/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:26:03 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/27 00:51:02 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_read(char **descr, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		rd;

	ft_bzero(buff, BUFF_SIZE + 1);
	if ((rd = read(fd, buff, BUFF_SIZE)) == 0)
		return (0);
	tmp = descr[fd];
	descr[fd] = ft_strjoin(descr[fd], buff);
	free(tmp);
	return (1);
}

static int	line_ret(char **line, char **descr, const int fd)
{
	*line = ft_strdup(descr[fd]);
	ft_strclr(descr[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *descr[10240];
	char		buff[BUFF_SIZE];
	char		*ptr;
	char		*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!descr[fd])
		descr[fd] = ft_strnew(0);
	while (!(ptr = ft_strchr(descr[fd], '\n')))
		if ((ft_read(descr, fd)) == 0)
			break ;
	if (ft_strlen(descr[fd]) != 0)
	{
		if (!(ft_strchr(descr[fd], '\n')))
			return (line_ret(line, descr, fd));
		*ptr = 0;
		tmp = ft_strdup(ptr + 1);
		*line = ft_strdup(descr[fd]);
		free(descr[fd]);
		descr[fd] = tmp;
	}
	else
		return (0);
	return (1);
}
