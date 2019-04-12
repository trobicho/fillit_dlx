/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:11:30 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/12 11:10:46 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "qlist.h"

static int		ft_linkit(t_qlist *clst, char **m, size_t w, size_t h)
{
	t_qlist		*col_lst;
	t_qlist		*r_lst;
	t_qlist		*l_lst;
	int			i;
	int			j;

	while (j < h)
	{
		col_lst = clst->r;
		r_lst = NULL;
		while (i < w)
		{
			if (!r_lst && m[i][j] && m[i][j] != '0')
			{
				if ((r_lst = ft_chrnewrow(col_lst, r_lst, r_lst)) == NULL)
					return (-1);
				l_lst = r_lst;
			}
			else if(m[i][j] && m[i][j] != '0')
			{
				if ((l_lst = ft_chrnewrow(col_lst, l_lst, r_lst)) == NULL)
					return (-1);
			}
			col_lst = col_lst->r;
			i++;
		}
		j++;
	}
}

t_qlist			*ft_alloc_matrix(char **m, size_t w, size_t h)
{
	t_qlist		*clst;
	t_qlist		*col_lst;
	int			i;
	int			j;
	int			n;

	if ((clst = ft_alloc_clst(w)) == NULL)
		return (NULL);
	col_lst = clst->r;
	i = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
			n += ((m[i][j] && m[i][j++] != '0')? 1 : 0);
		if (ft_alloc_col(col_lst, n) == -1)
			return (NULL);
		col_lst = col_lst->r;
		i++;
	}
	return (clst);
}
