/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:52:19 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/08 14:25:30 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count(int n)
{
	int				i;

	i = 0;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int			ft_power(int n)
{
	int				pwd;

	pwd = 1;
	while (n > 9 || n < -9)
	{
		pwd *= 10;
		n /= 10;
	}
	return (pwd);
}

char				*ft_itoa(int n)
{
	int				i;
	char			*mas;
	int				pwd;
	int				k;

	pwd = ft_power(n);
	mas = (char *)malloc(sizeof(char) * (ft_count(n) + 1));
	if (!mas)
		return (NULL);
	i = 0;
	if (n < 0)
		mas[i++] = '-';
	while (pwd > 0)
	{
		k = (n / pwd) % 10;
		if (k < 0)
			k = k * (-1);
		mas[i] = k + '0';
		pwd /= 10;
		i++;
	}
	mas[i] = '\0';
	return (mas);
}
