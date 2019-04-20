/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:19:01 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 17:37:25 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "matrix_create.h"
#include "qlist.h"
#include "mega_dlx.h"
#include "fillit_init.h"
#include "freeit.h"
#include "parser.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

static int	lunch_it(int fd, int nb_piece)
{
	t_fill_info	info;

	fillit_init_info(nb_piece, 4, &info, 0);
	if (!(info.lst = ft_alloc_clst(nb_piece + info.max * info.max)))
		return (-1);
	get_tetriminos(fd, &info);
	close(fd);
	ft_relink_secondary(info.lst, nb_piece);
	ft_mega_dlx(&info, &p_sol);
	freeit(info.lst);
	return (0);
}

int			main(int ac, char **av)
{
	int			fd;
	int			nb_piece;

	if (ac != 2)
		ft_putendl_fd("usage: fillit file", 1);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd >= 0)
			nb_piece = check_tetriminos(fd);
		else
		{
			ft_putendl_fd("error", 1);
			return (-1);
		}
		close(fd);
		if (nb_piece)
		{
			fd = open(av[1], O_RDONLY);
			return (lunch_it(fd, nb_piece) == -1);
		}
		else
		{
			ft_putendl_fd("error", 1);
			return (-1);
		}
	}
	return (0);
}
