/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:19:01 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/19 16:57:04 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "matrix_create.h"
#include "qlist.h"
#include "mega_dlx.h"
#include "fillit_init.h"
#include "freeit.h"
#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int			fd;
	int			nb_piece;
	t_fill_info	info;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 2)
			nb_piece = check_tetriminos(fd);
		else
			return (-1);
		printf("%d\n", nb_piece);
		printf("--------------\n");
		close(fd);
		if (nb_piece)
		{
			fd = open(av[1], O_RDONLY);
			fillit_init_info(nb_piece, 4, &info, 0);
			if (!(info.lst = ft_alloc_clst(nb_piece + info.max * info.max)))
				return (-1);
			get_tetriminos(fd, &info);
			ft_relink_secondary(info.lst, nb_piece);
			ft_mega_dlx(info.lst, 1, &p_sol, 2);
			freeit(info.lst);
			close(fd);
		}
		else
			return (-1);
	}
	return (0);
}
