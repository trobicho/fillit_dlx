/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:23:01 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 15:23:27 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "qlist.h"
#include "fifo.h"
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
			//size
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
			//size
			col_j->d->u = col_j;
			col_j->u->d = col_j;
		}
	}
	c->r->l = c;
	c->l->r = c;
}

int			ft_dlx(t_qlist *h, int k, int stopsol, void (*p_sol)(t_fifo *))
{
	t_qlist			*col;
	t_qlist			*row;
	t_qlist			*col_j;
	static t_fifo	*fifo = NULL;
	int				r;

	if (fifo == NULL && (fifo = ft_fifo_new(NULL, NULL)) == NULL)
		return (-1);
	if (h->r == h)
	{
		p_sol(fifo);
		return (1);
	}
	col = h->r;
	ft_cover(col);
	row = col;
	r = 0;
	while ((stopsol && r == 0) && (row = row->d) != col)
	{
		if (ft_fifo_push(fifo, row, k) == -1)
			return (-1);
		col_j = row;
		while ((col_j = col_j->r) != row)
			ft_cover(col_j->clh);
		if ((r = ft_dlx(h, k + 1, stopsol, p_sol)) == -1)
			return (r);
		while ((col_j = col_j->l) != row)
			ft_uncover(col_j->clh);
	}
	ft_uncover(col);
	ft_fifo_push(fifo, NULL, k);
	return (r);
}
