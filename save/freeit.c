/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 02:52:45 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 02:57:59 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "qlist.h"

void	freeit(t_qlist *h)
{
	t_qlist	*col;

	col = h;
	while ((col = col->r) != h)
	{
		if (col->d != col)
			free(col->d);
	}
	free(h);
}
