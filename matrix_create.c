/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:11:30 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 19:24:15 by trobicho         ###   ########.fr       */
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
