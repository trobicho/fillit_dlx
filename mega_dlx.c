/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_dlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:10:36 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 03:13:50 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "qlist.h"
#include "fifo.h"
#include "dlx.h"

static void	ft_cover_row(t_qlist *row)
{
	t_qlist	*row_r;

	row_r = row;
	row->d->u = row->u;
	row->u->d = row->d;
	while ((row_r = row_r->r) != row)
	{
		row_r->d->u = row_r->u;
		row_r->u->d = row_r->d;
	}
}

static void	ft_uncover_row(t_qlist *row)
{
	t_qlist	*row_l;

	row_l = row;
	while ((row_l = row_l->l) != row)
	{
		row_l->u->d = row_l;
		row_l->d->u = row_l;
	}
	row->u->d = row;
	row->d->u = row;
}

static void	ft_cover_header_row(t_qlist *h, int max_name)
{
	t_qlist	*row;

	h->name = max_name;
	while (h->name > 0)
	{
		row = h;
		while ((row = row->d) != h)
		{
			if (row->name == h->name)
				ft_cover_row(row->r);
		}
		h->name--;
	}
	h->name = 0;
}

static int	ft_uncover_header_row(t_qlist *h)
{
	t_qlist	*row;
	int		uncov;

	uncov = 0;
	row = h;
	while ((row = row->u) != h)
	{
		if (row->name == h->name)
		{
			row->u->d = row->d;
			row->d->u = row->u;
			ft_uncover_row(row->r);
			uncov++;
		}
	}
	return (uncov);
}

int			ft_mega_dlx(t_qlist *h, int stopsol, void (*p_sol)(t_fifo *)
						, int max_name)
{
	int		r;

	ft_cover_header_row(h, max_name);
	h->name = 0;
	while ((r = ft_dlx(h, 0, stopsol, p_sol)) == 0 || !stopsol)
	{
		printf("test\n");
		if (r == -1)
			return (-1);
		h->name++;
		if (!ft_uncover_header_row(h))
			break ;
	}
	return (r);
}
