/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:58:02 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/14 16:12:21 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_find(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static int		ft_changes(char **mas, char **line, const int fd)
{
	int			i;
	char		*tmp;

	i = 0;
	while (mas[fd][i] != '\n' && mas[fd][i] != '\0')
		i++;
	if (mas[fd][i] == '\n')
	{
		*line = ft_strsub(mas[fd], 0, i);
		tmp = ft_strdup(mas[fd] + i + 1);
		ft_strdel(&mas[fd]);
		mas[fd] = tmp;
	}
	else if (mas[fd][i] == '\0')
	{
		*line = ft_strdup(mas[fd]);
		ft_strdel(&mas[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			res;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*mas[12000];

	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!mas[fd])
		mas[fd] = ft_strnew(1);
	if (ft_find(mas[fd], '\n'))
		return (ft_changes(mas, line, fd));
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[res] = '\0';
		tmp = ft_strjoin(mas[fd], buf);
		ft_strdel(&mas[fd]);
		mas[fd] = tmp;
		if (ft_find(buf, '\n'))
			break ;
	}
	if (res == 0 && (!mas[fd] || mas[fd][0] == '\0'))
		return (0);
	else if (res < 0)
		return (-1);
	return (ft_changes(mas, line, fd));
}
