/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:08:24 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/22 16:30:02 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line/get_next_line.h"

typedef struct	s_tetris
{
	char	**figure;
	int		rows;
	int		cols;
	struct s_tetris	*next;
}				t_tetris;

typedef	struct	s_position
{
	int x;
	int y;
}		t_position;

int 	print_error(int res);
int		check_validation(int fd, int figures, int count, int j);
t_tetris *store_tetris(int fd);
void	fillit(t_tetris **list);

#endif
