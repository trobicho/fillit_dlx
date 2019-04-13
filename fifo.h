/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:54:17 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/13 13:29:20 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_H
# define FIFO_H

#include "qlist.h"

typedef struct	s_fifo
{
	t_qlist			*lst;
	struct s_fifo	*next;
}				t_fifo;

t_fifo	*ft_fifo_new(t_qlist *lst, t_fifo *next);
int		ft_fifo_push(t_fifo *fifo, t_qlist *lst, int k);
#endif
