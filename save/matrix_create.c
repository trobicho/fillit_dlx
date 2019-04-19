/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:11:30 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 02:04:12 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "qlist.h"

void			ft_relink_secondary(t_qlist *clst, int nb_primary)
{
	t_qlist	*lst;
	t_qlist	*lst_r;
	int		h;

	lst = clst->r;
	h = 0;
	while (h++ < nb_primary)
		lst = lst->r;
	lst->l->r = clst;
	clst->l = lst->l;
	while (lst != clst)
	{
		lst_r = lst->r;
		lst->r = lst;
		lst->l = lst;
		lst = lst_r;
	}
}

static int		ft_linkit(t_qlist *clst, char **m, int w, int h)
{
	t_qlist		*col_lst;
	t_qlist		*r_lst;
	t_qlist		*l_lst;
	int			i;
	int			j;

	j = -1;
	while (++j < h)
	{
		col_lst = clst->r;
		r_lst = NULL;
		l_lst = NULL;
		i = -1;
		while (++i < w)
		{
			if (m[j][i] && m[j][i] != '0')
			{
				if ((l_lst = ft_chrnewrow(col_lst, l_lst, r_lst)) == NULL)
					return (-1);
				if (!r_lst)
					r_lst = l_lst;
				r_lst->l = l_lst;
			}
			col_lst = col_lst->r;
		}
	}
	return (0);
}

t_qlist			*ft_alloc_matrix(char **m, int w, int h, int nb_second)
{
	t_qlist		*clst;
	t_qlist		*col_lst;
	int			i;
	int			j;
	int			n;

	if ((clst = ft_alloc_clst(w)) == NULL)
		return (NULL);
	col_lst = clst->r;
	i = -1;
	while (++i < w)
	{
		j = 0;
		n = 0;
		while (j < h)
			n += ((m[j][i] && m[j++][i] != '0') ? 1 : 0);
		if (ft_alloc_col(col_lst, n) == -1)
			return (NULL);
		col_lst = col_lst->r;
	}
	if ((ft_linkit(clst, m, w, h)) == -1)
		return (NULL);
	if (nb_second > 0)
		ft_relink_secondary(clst, w - nb_second);
	return (clst);
}
