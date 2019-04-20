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
			if ((i + 1) <= 16 && mas[i + 1] == 1)
				count++;
			if ((i - 1) >= 0 && mas[i - 1] == 1)
				count++;
			if ((i + 4) <= 16 && mas[i + 4] == 1)
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

static	int	ft_check_pos(char *file, char **line, int figures)
{
	int *checking;
	int i;
	int fd;

	fd = open(file, O_RDONLY);
	i = 0;
	checking = (int *)malloc(sizeof(int) * 5);
	while (get_next_line(fd, line) == 1)
	{
		if (*line[0] != '\n')
		{
			while (*line[i] != '\n' || *line[i] != '\0')
			{
				if (*line[i] == '.')
					checking[i++] = 0;
				else if (*line[i] == '#')
					checking[i++] = 1;
				else
				{
					close(fd);
					return (0);
				}
			}
		}
		else
		{
			if (ft_check_val(checking) == 0)
				return (0);
			i = 0;
		}
	}
	close(fd);
	return (1);
}

int		check_validation(int fd) //BETTER PUT TO ARGUMENTS 
{
	int count;
	int red;
	char **line;
	int i;
//	int fd;
	int *checking;
	char *mas;
	int j;
	int k;

	j = 0;
	red = 0;
	count = 0;
//	fd = open(file, O_RDONLY);
	printf("fd = %d\n", fd);
	i = 0;
	checking = (int *)malloc(sizeof(int) * 5);
	while (get_next_line(fd, line) == 1)
	{
		printf("%s\n", *line);
		mas = *line;
		if (ft_strcmp((const char *)line, "\n") && count < 4 && ft_check_dlina(*line)) //I AM NOT SURE ABOUT STRCMP
		{
			while (i < 4)
			{
//				printf("%c", mas[i]);
				if (mas[i] == '.')
					checking[j++] = 0;
				else if (mas[i] == '#')
					checking[j++] = 1;
//				printf("%d", checking[j - 1]);
				else
					return (0);
				i++;
			}
//			while (j >= 0)
//				printf("%d, ", mas[j--]);
			i = 0;
			count++;
			continue ;
		}
		printf("%d\n", count);
		printf("%s", *line);
		if (count == 4) //I AM NOT SURE ABOIT "\n"
		{
			k = 0;
			while (k <= 12)
			{
				printf("%d%d%d%d\n", checking[k], checking[k + 1], checking[k + 2], checking[k + 3]);
				k += 4;
			}
			if (ft_check_val(checking) == 0)
				return (0);
			j = 0;
			count = 0;
		}

		else
			red = 1;
		if (red)
			return (0);
	}
//	close(fd);
	printf("red = %d\n", red);
/*	if (!red && ft_check_pos(file, line, (i / 4))) //NEED NEW FD BECAUSE MAY BE READ IS ALREADY 0
	{
		print_error();
		return (0);
	}

	return (1);
}*/
/*int check_validation(int fd)
{
	char **line;

	while (get_next_line(fd, line) == 1)
		printf("%s", *line);
	//return (fd);
	return (0);
}*/
