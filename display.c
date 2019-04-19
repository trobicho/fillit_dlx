/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:48:43 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 13:53:51 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fifo.h"

static void	p_tab(char **tab, int w, int h)
{
	int i; 
	int	j;

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

static void	put_intab(t_fifo *fifo, char **tab, int nb_piece, int w, int h)
{
	char	name;
	int		name_h;
	t_qlist	*list;

	while (fifo != NULL)
	{
		if (fifo->lst != NULL)
		{
			name = (char)(fifo->lst->clh->name + 'A');
			list = fifo->lst->r;
			while (list != fifo->lst)
			{
				name_h = list->clh->name;
				tab[(name_h - nb_piece) / h][(name_h - nb_piece) % w] = name;
				list = list->r;
			}
		}
		fifo = fifo->next;
	}
}

void		p_sol(t_fifo *fifo)
{
	int i; 
	int	j;
	int w = 10, h = 10, nb_piece = 13;
	char **tab; 

	if ((tab = (char **)malloc(sizeof(char*) * h)) == NULL)
		return ;
	i = 0;
	while (i < h)
	{
		if ((tab[i] = (char *)malloc(sizeof(char) * w)) == NULL)
			return ;
		j = 0;
		while (j < w)
			tab[i][j++] = '.';
		i++;
	}
	put_intab(fifo, tab, nb_piece, w, h);
	p_tab(tab, w, h);
	i = 0;
	while (i < h)
	{
		free(tab[i++]);
	}
	free(tab);
}
