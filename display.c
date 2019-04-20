/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:48:43 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 17:41:46 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "fillit_init.h"

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

static void	put_intab(t_fill_info *info, char *tab, int w)
{
	char	name;
	int		name_h;
	t_qlist	*list;
	t_fifo	*fifo;

	fifo = info->fifo;
	while (fifo != NULL)
	{
		if (fifo->lst != NULL)
		{
			name = (char)(fifo->lst->clh->name + 'A');
			list = fifo->lst->r;
			while (list != fifo->lst)
			{
				name_h = list->clh->name - info->nb_piece;
				tab[(name_h / info->max) * w + name_h % info->max] = name;
				list = list->r;
			}
		}
		fifo = fifo->next;
	}
}

void		p_sol(t_fill_info *info)
{
	int		i;
	int		w;
	char	*tab;

	w = info->min + info->lst->name;
	if ((tab = (char *)malloc(sizeof(char) * w * w)) == NULL)
		return ;
	i = 0;
	while (i < w * w)
		tab[i++] = '.';
	put_intab(info, tab, w);
	p_tab(tab, w, w);
	i = 0;
	free(tab);
}
