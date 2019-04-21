/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:25 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/19 16:22:31 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// нужна ли последняя строка пустая? если пробелы после 4 символов, что должно выводить?
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

static	int ft_count_hesh(int *mas)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 16)
	{
		if (mas[i] == 1)
			count++;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

static	int ft_check_val(int *mas)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 16)
	{
		if (mas[i] == 1)
		{
			if ((i + 1) < 16 && (i % 4) != 3 && mas[i + 1] == 1)
				count++;
			if ((i - 1) >= 0 && (i % 4) != 0&& mas[i - 1] == 1)
				count++;
			if ((i + 4) < 16 && mas[i + 4] == 1)
				count++;
			if ((i - 4) >= 0 && mas[i - 4] == 1)
				count++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (0);
	return (1);
}

int		check_validation(int fd) 
{
	int count;
	char **line;
	int i;
	int *checking;
	char *mas;
	int j;
	int k;

	k = 0;
	j = 0;
	count = 0;
	i = 0;
	checking = (int *)malloc(sizeof(int) * 5);
	while (get_next_line(fd, line) == 1)
	{
		mas = *line;
//		printf("%s\n", mas);
//		printf("%d\n", ft_strcmp((const char *)line, "\n"));
//		printf("%d\n", j);
		if (ft_strcmp((const char *)line, "\n") && count < 4 && ft_check_dlina(*line)) //I AM NOT SURE ABOUT STRCMP AND NEED TO CHECK EOF
		{
			while (i < 4)
			{
				if (mas[i] == '.')
					checking[j++] = 0;
				else if (mas[i] == '#')
					checking[j++] = 1;
				else
				{
					ft_memdel((void **)checking);
					return (0);
				}
				i++;
			}
			i = 0;
			count++;
			continue ;
		}
//		while (k <= 12)
//		{
//			printf("%d%d%d%d\n", checking[k], checking [k+1], checking[k+2], checking[k+3]);
//			k += 4;
//		}
//		printf("\n");
//		k = 0;
//		printf("%d\n", count);
		if (count == 4)
		{
			if (ft_check_val(checking) == 0 || ft_count_hesh(checking) == 0)
			{
				ft_memdel((void **)checking);
				return (0);
			}
			j = 0;
			count = 0;
		}
		else
		{
			ft_memdel((void **)checking);
			return (0);
		}
	}
//	while (k <= 12)
///	{
///		printf("%d%d%d%d\n", checking[k], checking [k+1], checking[k+2], checking[k+3]);
//		k += 4;
//	}
	if (count == 4)
	{
		if (ft_check_val(checking) == 0 || ft_count_hesh(checking) == 0)
		{
			ft_memdel((void **)checking);
			return (0);
		}
		j = 0;
		count = 0;
	}
	else
	{
		ft_memdel((void **)checking);
		return (0);
	}
//	printf("\n");
//	k = 0;
//	printf("%d\n", count);
	ft_memdel((void **)checking);
	return (1);
}
