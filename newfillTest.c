/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfillTest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:14:13 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/15 20:25:35 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_create.h"
#include "qlist.h"
#include "dlx.h"
#include "fifo.h"
#include "fillit_init.h"
#include <stdlib.h>
#include <stdio.h>

t_qlist *init_test();
static int nb_sol = 0;

void	p_sol(t_fifo *fifo)
{
	t_qlist *list;
	int i = 0, j;
	int w = 8, h = 8, nbPiece = 6;
	char **tab = malloc(sizeof(char*) * h);
	char name;

	while (i < h)
	{
		tab[i] = malloc(sizeof(char) * w);
		j = 0;
		while (j < w)
			tab[i][j++] = '.';
		i++;
	}

	while (fifo != NULL)
	{
		name = (char)(fifo->lst->clh->name + 'A');
		list = fifo->lst->r;
		while (list != fifo->lst)
		{
			tab[(list->clh->name-nbPiece) / h][(list->clh->name-nbPiece) % w] = name;
			list = list->r;
			i++;
		}
		fifo = fifo->next;
	}

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
			printf("%c", tab[i][j++]);
		printf("\n");
		i++;
	}
	nb_sol++;
	printf("\n");
}

int	main(int ac, char **av)
{
	t_qlist *qlist;

	if ((qlist = init_test()) == NULL)
		return (-1);
	ft_dlx(qlist, 0, 0, &p_sol);
	print_nb_sol();
	return (0);
}
	
t_qlist *init_test()
{
	t_qlist *qlist;
	t_point *piece;
	t_fill_info info;
	int nb_piece = 6;
	int min = 6, max = 8; 

	if ((qlist = ft_alloc_clst(nb_piece + max * max)) == NULL)
		return (NULL);
	piece = fillit_init_info(nb_piece, 4, &info);
	info.lst = qlist;
	piece = (t_point[]){{0, 0}, {1, 0}, {2, 0}, {2, 1}};
	fillit_alloc_piece(&info, piece, 4, 0);
	piece = (t_point[]){{0, 0}, {1, 0}, {2, 0}, {3, 0}};
	fillit_alloc_piece(&info, piece, 4, 1);
	piece = (t_point[]){{0, 0}, {1, 0}, {1, 1}, {0, 1}};
	fillit_alloc_piece(&info, piece, 4, 2);
	piece = (t_point[]){{0, 0}, {0, 1}, {0, 2}, {0, 3}};
	fillit_alloc_piece(&info, piece, 4, 3);
	piece = (t_point[]){{0, 0}, {1, 0}, {2, 0}, {2, 1}};
	fillit_alloc_piece(&info, piece, 4, 4);
	piece = (t_point[]){{0, 0}, {0, 1}, {0, 2}, {1, 1}};
	fillit_alloc_piece(&info, piece, 4, 5);
	ft_relink_secondary(qlist, 6);
	return (qlist);
}
