/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:24:37 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/14 22:32:16 by trobicho         ###   ########.fr       */
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
	int i;

	while (fifo->next != NULL)
	{
		list = fifo->lst;
		while (list->r != fifo->lst)
		{
			printf("%c ", list->clh->name + 'A'); 
			list = list->r;
			i++;
		}
		printf("%c\n", list->clh->name + 'A'); 
		fifo = fifo->next;
	}
	list = fifo->lst;
	while (list->r != fifo->lst)
	{
		printf("%c ", list->clh->name + 'A'); 
		list = list->r;
		i++;
	}
	printf("%c\n", list->clh->name + 'A'); 
	fifo = fifo->next;
}

int	main(int ac, char **av)
{
	char *matrix[] = {"0010110",
		"1001001",
		"0110010",
		"1001000",
		"0100001",
		"0001101",};
	
	//t_qlist *qlist = ft_alloc_matrix(matrix, 324, 729, 2);
	t_qlist *qlist = ft_alloc_matrix(matrix, 7, 6, 9);
	if (qlist == NULL)
		return (-1);
	ft_dlx(qlist, 0, 1, &p_sol);
	return (0);
}
