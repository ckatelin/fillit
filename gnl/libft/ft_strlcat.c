/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:57:21 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/05 17:42:03 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst, const char *restrict src,
						size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	j = 0;
	i = 0;
	res = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (size <= i)
		res = j + size;
	else
		res = j + i;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (res);
}
