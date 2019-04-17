/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:01:55 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/05 17:45:45 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strchr(const char *s, int c)
{
	char	*ss;

	ss = (char *)s;
	while (*ss)
	{
		if (*ss == c)
			return (ss);
		ss++;
	}
	if (c == '\0')
		return (ss);
	return (0);
}