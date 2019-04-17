/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:05:28 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/06 14:55:32 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mas;

	i = 0;
	mas = (unsigned char *)b;
	while (i < len)
	{
		mas[i] = c;
		i++;
	}
	return ((void *)mas);
}
