/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfillTest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:14:13 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 03:24:37 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_create.h"
#include "qlist.h"
#include "mega_dlx.h"
#include "fifo.h"
#include "fillit_init.h"
#include "freeit.h"
#include <stdlib.h>
#include <stdio.h>

t_qlist *init_test();
t_qlist *init_test2();
static int nb_sol = 0;

void	p_sol(t_fifo *fifo)
{
	t_qlist *list;
	int i = 0, j;
	int w = 10, h = 10, nbPiece = 13;
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
		if (fifo->lst != NULL)
		{
			name = (char)(fifo->lst->clh->name + 'A');
			list = fifo->lst->r;
			while (list != fifo->lst)
			{
				tab[(list->clh->name-nbPiece) / h][(list->clh->name-nbPiece) % w] = name;
				list = list->r;
				i++;
			}
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
	ft_mega_dlx(qlist, 1, &p_sol, 6);
	freeit(qlist);
	return (0);
}
	
t_qlist *init_test()
{
	t_qlist *qlist;
	t_point *piece;
	t_fill_info info;
	int nb_piece = 13;
	int min = 4, max = 10; 

	if ((qlist = ft_alloc_clst(nb_piece + max * max)) == NULL)
		return (NULL);
	piece = fillit_init_info(nb_piece, 13, &info);
	info.lst = qlist;
	
	piece = (t_point[]){{0, 1}, {1, 1}, {1, 0}, {2, 0}};
	fillit_alloc_piece(&info, piece, 4, 0);

	piece = (t_point[]){{0, 0}, {1, 0}, {1, 1}, {1, 2}};
	fillit_alloc_piece(&info, piece, 4, 1);

	piece = (t_point[]){{3, 2}, {4, 2}, {4, 1}, {5, 1}};
	fillit_alloc_piece(&info, piece, 4, 2);
	fillit_alloc_piece(&info, piece, 4, 3);
	fillit_alloc_piece(&info, piece, 4, 4);
	fillit_alloc_piece(&info, piece, 4, 5);
	fillit_alloc_piece(&info, piece, 4, 6);
	fillit_alloc_piece(&info, piece, 4, 7);

	piece = (t_point[]){{0, 0}, {1, 0}, {2, 0}, {1, 1}};
	fillit_alloc_piece(&info, piece, 4, 8);

	piece = (t_point[]){{0, 1}, {1, 1}, {1, 0}, {2, 0}};
	fillit_alloc_piece(&info, piece, 4, 9);
	fillit_alloc_piece(&info, piece, 4, 10);
	fillit_alloc_piece(&info, piece, 4, 11);
	fillit_alloc_piece(&info, piece, 4, 12);
	
	/*
	piece = (t_point[]){{0, 0}, {1, 0}, {2, 0}, {1, 1}};
	fillit_alloc_piece(&info, piece, 4, 13);
	
	piece = (t_point[]){{0, 1}, {1, 1}, {1, 0}, {2, 0}};
	fillit_alloc_piece(&info, piece, 4, 14);
	fillit_alloc_piece(&info, piece, 4, 15);

	piece = (t_point[]){{0, 0}, {0, 1}, {0, 2}, {0, 3}};
	fillit_alloc_piece(&info, piece, 4, 16);
	
	piece = (t_point[]){{0, 1}, {1, 1}, {1, 0}, {2, 0}};
	fillit_alloc_piece(&info, piece, 4, 17);
	fillit_alloc_piece(&info, piece, 4, 18);
	
	piece = (t_point[]){{0, 0}, {0, 1}, {0, 2}, {2, 1}};
	fillit_alloc_piece(&info, piece, 4, 19);
	
	piece = (t_point[]){{0, 1}, {1, 1}, {1, 0}, {2, 0}};
	fillit_alloc_piece(&info, piece, 4, 20);
	*/
	free(piece);

	ft_relink_secondary(qlist, nb_piece);
	return (qlist);
}
