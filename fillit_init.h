/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_init.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:08:28 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 20:47:54 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_INIT_H
# define FILLIT_INIT_H

# include "qlist.h"
# include "fifo.h"

typedef struct	s_fill_info
{
	int		min;
	int		max;
	int		nb_piece;
	t_qlist	*lst;
	t_fifo	*fifo;
}				t_fill_info;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_curp
{
	int		i;
	int		j;
	int		p;
	int		len;
	t_point	size;
}				t_curp;

int				fillit_alloc_piece(t_fill_info *info, t_point *piece, int len
	, int p);
t_point			*fillit_init_info(int nb_piece, int piece_lenmax
	, t_fill_info *info, int alloc);
#endif
