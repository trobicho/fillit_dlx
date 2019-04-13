/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:11:28 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/13 17:32:06 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_CREATE_H
# define MATRIX_CREATE_H

#include <string.h>
#include "qlist.h"

t_qlist	*ft_alloc_matrix(char **m, size_t w, size_t h, nb_second);
#endif
