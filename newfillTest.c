/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newfillTest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:14:13 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/14 22:28:35 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_create.h"
#include "dlx.h"
#include "fifo.h"
#include <stdlib.h>
#include <stdio.h>

void	p_sol(t_fifo *fifo)
{
	t_qlist *list;
	int i = 0, j;
	int w = 6, h = 6, nbPiece = 4;
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
	printf("\n");
}

int	main(int ac, char **av)
{
	int nb_piece = 14;
	int min = 8, max = 10; 
	t_qlist *qlist;

	if ((*qlist = ft_alloc_clst(nbPiece + max*max)) == NULL)
		return (-1);
	fillit_alloc_row(qlist, nb_piece, min, max);
	ft_dlx(qlist, 0, 0, &p_sol);
	return (0);
}
