/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:25 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/17 17:02:05 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	check_dline(char **str)
{
	int i;

	i = 0;
	while ((*str[i] != '\n' || *str[i] != '\0') && i < 5)
		i++;
	if (i == 5)
		return (1);
	return (0);
}

static	int	check_pos(int fd)
{
	
}

int		check_validation(int fd)
{
	int count;
	int red;
	int *line;

	red = 0;
	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line != "\n" && count < 4 && check_dlina(&line) 
			count++;
		if (count == 4 && *line == "\n") //need one check for EOF
			count = 0;
		else 
			red = 1;
		if (red)
			break ;
	}
	if (red && check_pos())
	{
		print_error;
		return (0);
	}
	return (1);
}
