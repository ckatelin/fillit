/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/19 17:58:03 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incliude "fillit.h"

static int solve(char ***square, char **pieces)
{
	int i;
	int j;

	i = 0;
	while (*square[i])
	{
		j = 0;
		while (*square[i][j])
		{
			if ((*square[i][j] == '0' && (*pieces)->fig[i][j] != '0'))
			{
				*square[i][j] == (*pieces)->fig[i][j];
				(*pieces)->rows -= 1;
			}
			j++;
		}
		(*pieces)->cols -= 1;
		i++;
	}
	if (!(*pieces)->rows && !(*pieces)->cols)
	{
		if ((*pieces)->next)
			return (add_piece(&*square, &(*pieces)->next));
		return (0);
	return (1);
}

static char **create_square(int size)
{
	char **square;
	int i;

	square = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		square[i] = (char *)malloc(sizeof(char) * (size + 1));
		i++;
	}
	square[size] = NULL;
	return (square);
}

void fillit(t_piece **list)
{
	int size;

	size = 2;
	while (solve(&create_square(size), &*list))
		size++;
}
