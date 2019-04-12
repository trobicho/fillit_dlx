/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:23:01 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/12 19:54:10 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "qlist.h"

static int maxk = -1;

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

int			ft_dlx(t_qlist *h, int k)
{
	t_qlist *col;
	t_qlist *row;
	t_qlist *col_j;

	if (h->r == h)
		return (1);
	col = h->r;
	ft_cover(col);
	row = col;
	if (k > maxk)
	{
		printf("deep = %d\n", k);
		maxk = k;
	}
	while ((row = row->d) != col)
	{
		//Ok <- row pour disp soluce
		col_j = row;
		while ((col_j = col_j->r) != row)
		{
			//printf("cover j: %d\n", k);
			//printLst(h);
			ft_cover(col_j->clh);
		}
		ft_dlx(h, k + 1);
		while ((col_j = col_j->l) != row)
		{
			//printf("uncover j: %d\n", k);
			ft_uncover(col_j->clh);
		}
	}
	//printf("uncover c: %d\n", k);
	ft_uncover(col);
	return (1);
}
