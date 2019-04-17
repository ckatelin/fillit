/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:30:05 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/04 15:55:56 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*mas;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	mas = (char *)malloc(sizeof(char) * (i + 1));
	if (!mas)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		mas[i] = s1[i];
		i++;
	}
	mas[i] = '\0';
	return (mas);
}
