/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_dlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:10:10 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 19:43:38 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGA_DLX_H
# define MEGA_DLX_H

# include "qlist.h"
# include "fifo.h"

int	ft_mega_dlx(t_fill_info *info, void (*p_sol)(t_fill_info *));
#endif
