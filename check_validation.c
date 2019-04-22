/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:25 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/22 17:16:47 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_check_dlina(char *str)
{
	int i;

	i = 0;
	while ((str[i] != '\n' || str[i] != '\0') && i < 5)
		i++;
	if (i == 5)
		return (1);
	return (0);
}

static int ft_check_dots(char *mas)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (mas[i] != '.' && mas[i] != '#')
			return (1);
		i++;
	}
	return (0);
}

static	int ft_check_val(char *mas)
{
	int i;
	int count;
	int res;

	i = -1;
	count = 0;
	res = 0;
	while (++i < 16)
	{
		if (mas[i] == '#')
		{
			if ((i + 1) < 16 && (i % 4) != 3 && mas[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && (i % 4) != 0 && mas[i - 1] == '#')
				count++;
			if ((i + 4) < 16 && mas[i + 4] == '#')
				count++;
			if ((i - 4) >= 0 && mas[i - 4] == '#')
				count++;
			res++;
		}
	}
	if ((count != 6 && count != 8) || res != 4)
		return (0);
	return (1);
}

static int ft_strdeldel(char *str, int i)
{
	ft_strdel(&str);
	return (i);
}

int		check_validation(int fd, int figures, int count, int j) 
{
	char *line;
	char *checking;

	if (count == 0)
		checking = ft_strnew(0);
	while (get_next_line(fd, &line) == 1 && figures < 26)
	{
		if (count < 4 && ft_check_dlina(line))
		{
			if (ft_check_dots(line) || line[4] != '\0')
					return (ft_strdeldel(checking, 0));
			if (!(checking = ft_strjoin(checking, line)))
				return (0);
			j += 4;
			check_validation(fd, figures, ++count, j);
		}
		if (count == 4)
		{
			if (ft_check_val(checking) == 0)
				return(ft_strdeldel(checking, 0));
			ft_strdel(&checking);
			check_validation(fd, ++figures, 0, 0);
		}
		else
			return (ft_strdeldel(checking, 0));
	}
	if (count != 4 || ft_check_val(checking) == 0)
			return (ft_strdeldel(checking, 0));
//	return (ft_strdeldel(checking, 1));
	return (1);
}
