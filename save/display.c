/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:48:43 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 16:47:09 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "fifo.h"

static void	p_tab(char *tab, int w, int h)
{
	int i; 
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		write(1, &tab[i * w], (size_t)w);
		write(1, "\n", 1);
		i++;
	}
}

static void	put_intab(t_fifo *fifo, char *tab, int nb_piece, int w, int h)
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
				name_h = list->clh->name - nb_piece;
				tab[(name_h / h) * w + name_h % w] = name;
				list = list->r;
			}
		}
		fifo = fifo->next;
	}
}

void		p_sol(t_fifo *fifo)
{
	int i; 
	int w = 10, h = 10, nb_piece = 13;
	char *tab; 

	if ((tab = (char *)malloc(sizeof(char) * w * h)) == NULL)
		return ;
	i = 0;
	while (i < w * h)
		tab[i++] = '.';
	put_intab(fifo, tab, nb_piece, w, h);
	p_tab(tab, w, h);
	i = 0;
	free(tab);
}
