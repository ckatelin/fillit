/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:13:57 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/05 17:48:39 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*n;
	char	*h;

	i = 0;
	n = (char *)needle;
	h = (char *)haystack;
	if (n[0] == '\0')
		return (h);
	while (h[i] && i < len)
	{
		k = i;
		j = 0;
		while (h[k] == n[j] && n[j] && h[k] && k < len)
		{
			k++;
			j++;
		}
		if (n[j] == '\0')
			return (h + i);
		i++;
	}
	return (NULL);
}
