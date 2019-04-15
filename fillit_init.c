/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:09:04 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/15 19:46:27 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_init.h"
#include "qlist.h"
#include <stdlib.h>

t_point		*fillit_init_info(int nb_piece, int piece_lenmax, 
							t_fill_info *info)
{
	info->min = 6;
	info->max = info->min + 2;
	info->nb_piece = nb_piece;
	return ((t_point *)malloc(sizeof(t_point) * piece_lenmax));
}

int			fillit_alloc_piece(t_fill_info *info, t_point *piece, int len, int p)
{
	int		i;
	int		j;
	int		k;
	int		col;
	t_point	size;
	t_qlist *row;

	size.x = 0;
	size.y = 0;
	i = 0;
	while (i < len)
	{
		if (size.x < piece[i].x)
			size.x = piece[i].x;
		if (size.y < piece[i].y)
			size.y = piece[i].y;
		i++;
	}
	row = (t_qlist*)malloc(sizeof(t_qlist) * ((len + 1) * ((info->max - size.x) * (info->max - size.y))));
	if (row == NULL)
		return (-1);
	i = 0;
	while (i < info->max - size.y)
	{
		j = 0;
		while (j < info->max - size.x)
		{
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
