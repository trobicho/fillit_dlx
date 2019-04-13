/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:23:06 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/13 17:49:55 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "qlist.h"
#include <string.h>

t_qlist	*ft_alloc_clst(int nb_col)
{
	int		i;
	t_qlist	*clst;

	if ((clst = malloc(sizeof(t_qlist) * (nb_col + 1))) == NULL)
		return (NULL);
	i = 0;
	while(i < nb_col + 1)
	{
		clst[i].l = &clst[(i == 0 ? nb_col : i - 1)];
		clst[i].r = &clst[(i + 1) % (nb_col + 1)];
		clst[i].u = &clst[i];
		clst[i].d = &clst[i];
		clst[i].clh = &clst[i];
		clst[i].name = i - 1;
		clst[i].size = 0;
		i++;
	}
	return (clst);
}

int		ft_alloc_col(t_qlist *clst, int n_constrain)
{
	int		j;
	t_qlist	*qlst;
	
	if (n_constrain)
	{
		if ((qlst = malloc(sizeof(t_qlist) * n_constrain)) == NULL)
			return (-1);
		j = 0;
		clst->d = qlst;
		while (j < n_constrain)
		{
			qlst[j].r = NULL;
			qlst[j].l = NULL;
			qlst[j].u = (j == 0 ? clst : &qlst[j - 1]);
			qlst[j].d = (j + 1 == n_constrain ? clst : &qlst[j + 1]);
			qlst[j].clh = clst;
			j++;
		}
		clst->u = &qlst[n_constrain - 1];
	}
	return (0);
}

t_qlist	*ft_chrnewrow(t_qlist *clst, t_qlist *l, t_qlist *r)
{
	t_qlist		*row_lst;

	row_lst = clst->d;
	while (row_lst->r != NULL && row_lst != clst)
		row_lst = row_lst->d;
	if (row_lst == clst)
		return (NULL);
	row_lst->l = (l ? l : row_lst);
	row_lst->r = (r ? r : row_lst);
	row_lst->l->r = row_lst;
	return (row_lst);
}

#include <stdio.h>
void	printLst(t_qlist *h)
{
	t_qlist *c, *i, *j;

	c = h->r;
	while(c != h)
	{
		j = c;
		printf("(%0x):", c);
		do
		{
			i = j;
			do
			{
				printf("(%0x)->", i->l);
				i = i->l;
			}while(i != j);
			printf("DOWN(%0x)\n", j->d);
			j = j->d;
		}while(j != c);
		printf("------------------\n");
		c = c->r;
	}
}
