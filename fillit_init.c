/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:09:04 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/16 21:34:51 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_init.h"
#include "qlist.h"
#include <stdlib.h>

t_point		*fillit_init_info(int nb_piece, int piece_lenmax, 
							t_fill_info *info)
{
	info->min = 10;
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
	int		nb_hidden;
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
