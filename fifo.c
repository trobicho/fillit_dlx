/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:58:05 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 02:14:41 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fifo.h"

t_fifo	*ft_fifo_new(t_qlist *lst, t_fifo *next)
{
	t_fifo *fifo;

	if ((fifo = malloc(sizeof(t_fifo))) == NULL)
		return (NULL);
	fifo->lst = lst;
	fifo->next = next;
	return (fifo);
}

int		ft_fifo_push(t_fifo *fifo, t_qlist *lst, int k)
{
	int	i;

	if (k == 0)
	{
		fifo->lst = lst;
		return (0);
	}
	i = 0;
	while (i < k - 1)
	{
		i++;
		fifo = fifo->next;
	}
	if (fifo->next == NULL)
	{
		if ((fifo->next = ft_fifo_new(lst, NULL)) == NULL)
			return (-1);
	}
	else
		fifo->next->lst = lst;
	return (0);
}
