/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:25 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/21 17:21:54 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// проуверить освобождвет ли память memdel

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

static	int *ft_pull_checking(int *checking, int i, char *mas, int j)
{
			while (i < 4)
			{
				if (mas[i] == '.')
					checking[j++] = 0;
				else if (mas[i] == '#')
					checking[j++] = 1;
				i++;
			}
			return (checking);
}

static	int ft_check_val(int *mas)
{
	int i;
	int count;
	int res;

	i = -1;
	count = 0;
	res = 0;
	while (++i < 16)
	{
		if (mas[i] == 1)
		{
			if ((i + 1) < 16 && (i % 4) != 3 && mas[i + 1] == 1)
				count++;
			if ((i - 1) >= 0 && (i % 4) != 0 && mas[i - 1] == 1)
				count++;
			if ((i + 4) < 16 && mas[i + 4] == 1)
				count++;
			if ((i - 4) >= 0 && mas[i - 4] == 1)
				count++;
			res++;
		}
	}
	if ((count != 6 && count != 8) || res != 4)
		return (0);
	return (1);
}

static int ft_intdel(int *mas)
{
	if (mas && *mas)
	{
		free(mas);
		mas = NULL;
	}
	return (0);
}

static void ft_intdeldel(int *mas)
{
	if (mas && *mas)
	{
		free(mas);
		mas = NULL;
	}
}

int		check_validation(int fd) 
{
	int count;
	char *line;
	int *checking;
	int j;
	int figures;

	j = 0;
	count = 0;
	figures = 0;
	checking = (int *)malloc(sizeof(int) * 16);
	while (get_next_line(fd, &line) == 1 && figures < 26) // <= OR < ? NNED CHECK
	{
		if (ft_strcmp((const char *)line, "\n") && count < 4 && ft_check_dlina(line))
		{
			if (ft_check_dots(line) || line[4] != '\0')
					return (ft_intdel(checking));
			checking = ft_pull_checking(checking, 0, line, j);
			j += 4;
			count++;
			continue;
		}
		printf("%d\n", count);
		if (count == 4)
		{
			if (ft_check_val(checking) == 0)
				return(ft_intdel(checking));
			j = 0;
			count = 0;
			figures++;
		}
		else
			return (ft_intdel(checking));
	}
	if (count != 4 || ft_check_val(checking) == 0)
			return (ft_intdel(checking));
	ft_intdeldel(checking);
	return (1);
}
