/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_dlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:10:10 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 17:28:08 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEFA_DLX_H
# define MEFA_DLX_H

#include "qlist.h"
#include "fifo.h"

int	ft_mega_dlx(t_fill_info *info, void (*p_sol)(t_fill_info *));
#endif
