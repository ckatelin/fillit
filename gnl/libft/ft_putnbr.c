/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:36:54 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/06 13:36:56 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int nbr;
	int pwd;
	int k;

	pwd = 1;
	nbr = n;
	if (n < 0)
		ft_putchar('-');
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
		ft_putchar(k + '0');
		pwd /= 10;
	}
}
