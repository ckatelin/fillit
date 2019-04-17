/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:01:23 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/05 17:35:58 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*mas;

	mas = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(mas) == (unsigned char)c)
			return ((void *)mas);
		mas++;
		i++;
	}
	return (0);
}
