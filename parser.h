/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:35:06 by tefourge          #+#    #+#             */
/*   Updated: 2019/04/19 15:10:16 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
#include "fillit_init.h"

#define BUFF_SIZE 21

typedef struct	s_tete
{
    char    *tmp;
    char    buf[BUFF_SIZE + 1];
    int     i;
    int     j;
    int     x;
    int     ret;
    int     size;
}				t_tete;


int				check_tetriminos(int fd);
int				get_tetriminos(int fd, t_fill_info *info);
#endif
