/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:09:04 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 16:57:09 by trobicho         ###   ########.fr       */
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

t_point			*fillit_init_info(int nb_piece, int piece_lenmax,
							t_fill_info *info, int alloc)
{
	info->min = sqrt_exess(nb_piece * piece_lenmax);
	info->max = info->min+2;
	info->nb_piece = nb_piece;
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

int				fillit_alloc_piece(t_fill_info *info, t_point *piece, int len, int p)
{
	int		i;
	int		j;
	int		k;
	int		col;
	int		nb_hidden;
	t_point	size;
	t_qlist *row;

	size = size_center_piece(piece, len);
	nb_hidden = (info->max - size.x) * (info->max - size.y) - (info->min - size.x) * (info->min - size.y);
	row = (t_qlist*)malloc(sizeof(t_qlist) * ((len + 1) * ((info->max - size.x) * (info->max - size.y)) + nb_hidden));
	nb_hidden = 0;
	if (row == NULL)
		return (-1);
	i = 0;
	while (i < info->max - size.y)
	{
		j = 0;
		while (j < info->max - size.x)
		{
			if (i >= info->min - size.y || j >= info->min - size.x)
			{
				ft_add_tocol(info->lst, &row[0], -1);
				row[0].name = ((i - (info->min - size.y)) > (j - (info->min - size.x)) ? i - (info->min - size.y) + 1 : j - (info->min - size.x) + 1);
				row[0].r = &row[1];
				row[0].l = row;
				row = &row[1];
			}
			k = 0;
			ft_add_tocol(info->lst, &row[0], p);
			while (k < len)
			{
				col = info->nb_piece + info->max * (i + piece[k].y) + j + piece[k].x;
				ft_add_tocol(info->lst, &row[k + 1], col);
				row[k + 1].l = &row[k];
				row[k].r = &row[k + 1];
				k++;
			}
			row[k].r = &row[0];
			row[0].l = &row[k];
			row = &row[len + 1];
			j++;
		}
		i++;
	}
	return (1);
}
