/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:08:24 by ckatelin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/19 18:03:45 by ckatelin         ###   ########.fr       */
=======
/*   Updated: 2019/04/19 17:59:47 by smorty           ###   ########.fr       */
>>>>>>> 5ce33c7deee45578b34f87bd36ba05142013fdb1
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line/get_next_line.h"

typedef struct	s_piece
{
	char	fig[4][4];
	int		rows;
	int		cols;
	struct s_piece	*next;
}				t_piece;

typedef	struct	s_position
{
	int x;
	int y;
}		t_position;

void	print_error(void);
int		check_validation(int fd);
t_piece	*store_pieces(int fd);
void	fillit(t_piece **list);

#endif
