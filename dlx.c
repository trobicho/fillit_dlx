/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:23:01 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 20:10:41 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "qlist.h"
#include "fifo.h"
#include "fillit_init.h"
#include "dlx.h"
#include <string.h>

static void	ft_cover(t_qlist *c)
{
	t_qlist	*row_i;
	t_qlist	*col_j;

	c->r->l = c->l;
	c->l->r = c->r;
	row_i = c;
	while ((row_i = row_i->d) != c)
	{
		col_j = row_i;
		while ((col_j = col_j->r) != row_i)
		{
			col_j->d->u = col_j->u;
			col_j->u->d = col_j->d;
		}
	}
}

static void	ft_uncover(t_qlist *c)
{
	t_qlist	*row_i;
	t_qlist	*col_j;

	row_i = c;
	while ((row_i = row_i->u) != c)
	{
		col_j = row_i;
		while ((col_j = col_j->l) != row_i)
		{
			col_j->d->u = col_j;
			col_j->u->d = col_j;
		}
	}
	c->r->l = c;
	c->l->r = c;
}

static int	dlx_loop(t_fill_info *info, int k, void (*p_sol)(t_fill_info *)
	, t_qlist *row)
{
	int			r;
	t_qlist		*col_j;

	col_j = row;
	if (ft_fifo_push(info->fifo, row, k) == -1)
		return (-1);
	while ((col_j = col_j->r) != row)
		ft_cover(col_j->clh);
	if ((r = ft_dlx(info, k + 1, p_sol)) == -1)
		return (r);
	while ((col_j = col_j->l) != row)
		ft_uncover(col_j->clh);
	return (r);
}

int			ft_dlx(t_fill_info *info, int k, void (*p_sol)(t_fill_info *))
{
	int				r;
	t_qlist			*col;
	t_qlist			*row;

	if (info->fifo == NULL && (info->fifo = ft_fifo_new(NULL, NULL)) == NULL)
		return (-1);
	if (info->lst->r == info->lst)
	{
		p_sol(info);
		return (1);
	}
	col = info->lst->r;
	ft_cover(col);
	row = col;
	r = 0;
	while (r == 0 && (row = row->d) != col)
	{
		if ((r = dlx_loop(info, k, p_sol, row)) == -1)
			return (r);
	}
	ft_uncover(col);
	ft_fifo_push(info->fifo, NULL, k);
	return (r);
}
