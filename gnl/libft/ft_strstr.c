/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:07:18 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/05 17:47:26 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	char	*h;
	char	*n;

	n = (char *)needle;
	h = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (h);
	while (h[i])
	{
		k = i;
		j = 0;
		while (h[k] == n[j] && n[j] && h[k])
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
