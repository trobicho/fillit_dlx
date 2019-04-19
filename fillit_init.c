/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:09:04 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 21:27:44 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_init.h"
#include "qlist.h"
#include <stdlib.h>

static int		sqrt_exess(int n)
{
	int	r;

	r = n / 2;
	if (r <= 1)
		return (2);
	while (r * r > n)
	{
		r--;
	}
	if (r * r == n)
		return (r);
	return (r + 1);
}

t_point			*fillit_init_info(int nb_piece, int piece_lenmax
	, t_fill_info *info, int alloc)
{
	info->min = sqrt_exess(nb_piece * piece_lenmax);
	info->max = info->min + 2;
	info->nb_piece = nb_piece;
	info->fifo = NULL;
	if (alloc)
		return ((t_point *)malloc(sizeof(t_point) * piece_lenmax));
	else
		return (NULL);
}

static t_point	size_center_piece(t_point *piece, int len)
{
	int		i;
	t_point	size;
	t_point	size_min;

	size_min.x = piece[0].x;
	size_min.y = piece[0].y;
	size.x = 0;
	size.y = 0;
	i = -1;
	while (++i < len)
	{
		size_min.x = (size_min.x > piece[i].x ? piece[i].x : size_min.x);
		size_min.y = (size_min.y > piece[i].y ? piece[i].y : size_min.y);
		size.x = (size.x < piece[i].x ? piece[i].x : size.x);
		size.y = (size.y < piece[i].y ? piece[i].y : size.y);
	}
	size.x -= size_min.x;
	size.y -= size_min.y;
	i = -1;
	while (++i < len)
	{
		piece[i].x -= size_min.x;
		piece[i].y -= size_min.y;
	}
	return (size);
}

static t_qlist	*fillit_alloc_inter(t_fill_info *info, t_curp cp, t_qlist *row
	, t_point *piece)
{
	int	min;

	min = info->min;
	if (cp.i >= info->min - cp.size.y || cp.j >= info->min - cp.size.x)
	{
		ft_add_tocol(info->lst, &row[0], -1);
		row[0].name = ((cp.i - (min - cp.size.y)) > (cp.j - (min - cp.size.x))
				? cp.i - (min - cp.size.y) + 1 : cp.j - (min - cp.size.x) + 1);
		row[0].r = &row[1];
		row[0].l = row;
		row = &row[1];
	}
	ft_add_tocol(info->lst, &row[0], cp.p);
	cp.k = -1;
	while (++cp.k < cp.len)
	{
		cp.col = info->nb_piece
			+ info->max * (cp.i + piece[cp.k].y) + cp.j + piece[cp.k].x;
		ft_add_tocol(info->lst, &row[cp.k + 1], cp.col);
		row[cp.k + 1].l = &row[cp.k];
		row[cp.k].r = &row[cp.k + 1];
	}
	row[cp.k].r = &row[0];
	row[0].l = &row[cp.k];
	return (&row[cp.len + 1]);
}

int				fillit_alloc_piece(t_fill_info *info, t_point *piece, int len
	, int p)
{
	int		nb_hidden;
	t_qlist	*row;
	t_curp	cp;

	cp.size = size_center_piece(piece, len);
	if ((info->min - cp.size.x) * (info->min - cp.size.y) <= 0)
		info->min = cp.size.x > cp.size.y ? cp.size.x + 1 : cp.size.y + 1;
	nb_hidden = (info->max - cp.size.x) * (info->max - cp.size.y)
		- (info->min - cp.size.x) * (info->min - cp.size.y);
	row = (t_qlist*)malloc(sizeof(t_qlist) * ((len + 1)
				* ((info->max - cp.size.x) * (info->max - cp.size.y))
					+ nb_hidden));
	if (row == NULL)
		return (-1);
	cp.i = 0;
	cp.p = p;
	cp.len = len;
	while (cp.i < info->max - cp.size.y)
	{
		cp.j = -1;
		while (++cp.j < info->max - cp.size.x)
			row = fillit_alloc_inter(info, cp, row, piece);
		cp.i++;
	}
	return (1);
}
