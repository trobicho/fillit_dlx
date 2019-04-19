/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:23:03 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 19:43:53 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLX_H
# define DLX_H

# include "qlist.h"
# include "fifo.h"
# include "fillit_init.h"

int	ft_dlx(t_fill_info *info, int k, void (*p_sol)(t_fill_info *));
#endif
