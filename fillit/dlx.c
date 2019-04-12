/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:23:01 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/12 11:26:51 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	dlx(t_qlist *h)
{
	t_qlist *col;
	t_qlist *row;
	t_qlist *col_j;

	if (h->r == h)
		return (1);
	col = h->r;
	//cover column col
	row = col;
	while ((row = row->d) != col)
	{
		//Ok <- row pour disp soluce
		col_j = row;
		while ((col_j = col_j->r) != row)
			printf("test\n"); //cover column col_j
	}
}
