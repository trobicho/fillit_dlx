/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_dlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:10:10 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 01:42:06 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEFA_DLX_H
# define MEFA_DLX_H

#include "qlist.h"
#include "fifo.h"

int	ft_mega_dlx(t_qlist *h, int stopsol, void (*p_sol)(t_fifo *), int max_name);
#endif
