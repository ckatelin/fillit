/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:20:42 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/08 17:14:36 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = NULL;
	if (alst && (*del) && *alst)
	{
		tmp = *alst;
		(*del)(tmp->content, tmp->content_size);
		tmp->next = NULL;
		free(tmp);
		*alst = NULL;
	}
}
