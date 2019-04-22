/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:58:37 by smorty            #+#    #+#             */
/*   Updated: 2019/04/22 16:30:15 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*static void print_figures(t_tetris **list)
{
	int i;

	i = 0;
	if (*list)
	{
		while ((*list)->figure[i])
		{
			ft_putendl((*list)->figure[i]);
			i++;
		}
		ft_putchar('\n');
		print_figures(&(*list)->next);
	}
}
*/
int		main(int argc, char **argv)
{
	int fd;
	t_tetris *new;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (print_error(check_validation(fd, 0, 0, 0)) == 0)
		{
			close(fd);
			return (0);
		}
		close(fd);
		fd = open(argv[1], O_RDONLY);
		new = store_tetris(fd);
//		print_figures(&new);
		fillit(&new);
	}
	return (0);
}
