/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:06:14 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/17 15:08:07 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(void)
{
	char *error;
	int i;

	i = 0;
	error = "error";
	while (error[i])
	{
		ft_putchar(error[i]);
		i++;
	}
}
