/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:22:56 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/15 17:13:20 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	QLIST_H
# define QLIST_H

typedef struct	s_qlist
{
	struct s_qlist	*u;
	struct s_qlist	*d;
	struct s_qlist	*l;
	struct s_qlist	*r;
	struct s_qlist	*clh;
	int				name;
	int				size;
}				t_qlist;

t_qlist			*ft_alloc_clst(int nb_col);
int				ft_alloc_col(t_qlist *clst, int n_constrain);
t_qlist			*ft_chrnewrow(t_qlist *clist, t_qlist *l, t_qlist *r);
void			ft_add_tocol(t_qlist *header, t_qlist *elem, int c);

void	printLst(t_qlist *h);
#endif
