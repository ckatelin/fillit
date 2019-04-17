/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:41:44 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/06 13:41:45 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int nbr;
	int pwd;
	int k;

	pwd = 1;
	nbr = n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (nbr > 9 || nbr < -9)
	{
		pwd *= 10;
		nbr /= 10;
	}
	while (pwd > 0)
	{
		k = (n / pwd) % 10;
		if (k < 0)
			k = k * (-1);
		ft_putchar_fd(k + '0', fd);
		pwd /= 10;
	}
}
