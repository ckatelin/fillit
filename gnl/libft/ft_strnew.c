/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:53:35 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/05 18:58:26 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	unsigned char	*mas;

	mas = (unsigned char *)malloc(size + 1);
	if (!mas)
		return (NULL);
	ft_bzero(mas, size + 1);
	return ((char *)mas);
}
