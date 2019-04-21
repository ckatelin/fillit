/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:06:14 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/21 15:13:24 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	print_error(int res)
{
	char *error;
	int i;

	if (res == 0)
	{
		i = 0;
		error = "error\n";
		while (error[i])
		{
			ft_putchar(error[i]);
			i++;
		}
		return (0);
	}
	return (1);
}
