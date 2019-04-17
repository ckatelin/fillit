/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:42:06 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/08 21:24:54 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_countstr(char *s, char c)
{
	int				i;
	int				countstr;

	i = 0;
	countstr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i - 1] != c)
			countstr++;
		if (s[i] != '\0')
			i++;
	}
	return (countstr);
}

static size_t		len(const char *s, size_t i, char c)
{
	size_t	count;

	count = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static	size_t		count(char const *s, size_t i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**mas;
	size_t			i;
	size_t			j;
	size_t			k;
	size_t			all;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(mas = (char **)malloc(sizeof(char *) *
				(ft_countstr((char *)s, c) + 1))))
		return (NULL);
	while (k < (all = ft_countstr((char *)s, c)))
	{
		j = 0;
		i = count(s, i, c);
		if (!(mas[k] = ft_strnew(len(s, i, c))))
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			mas[k][j++] = s[i++];
		mas[k++][j] = '\0';
	}
	mas[k] = 0;
	return (mas);
}
