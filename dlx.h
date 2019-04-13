/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:23:03 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/13 13:47:33 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLX_H
# define DLX_H

#include "qlist.h"
#include "fifo.h"

int	ft_dlx(t_qlist *h, int k, int stopsol, void (*print_sol)(t_fifo *));
#endif
