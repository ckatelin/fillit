/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:35:59 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/08 21:19:30 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mas;

	mas = ft_memalloc(len + 1);
	if (mas && s)
		mas = ft_strncpy(mas, (char *)s + start, len);
	else
		return (NULL);
	return (mas);
}
