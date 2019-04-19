/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:35:06 by tefourge          #+#    #+#             */
/*   Updated: 2019/04/19 19:06:29 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft/libft.h" //a changer
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "fillit_init.h"

static int	nb_sigle(char *buf)
{
	t_tete t;

	ft_bzero(&t, sizeof(t_tete));
	while (t.i <= BUFF_SIZE)
	{
		if (buf[t.i] == '#')
		{
			t.j++;
		}
		if (buf[t.i] == '.')
		{
			t.x++;
		}
		t.i++;
	}
	if (t.x == 12 && t.j == 4)
	{
		printf("%s\n", "There is 12 . and 4 #, tetriminos is valid");
		return (1);
	}
	printf("%s\n", "Invalid number of # and/or . : abort");
	return (0);
}

static int	nb_line(char *buf)
{
	t_tete t;

	ft_bzero(&t, sizeof(t_tete));
	while (t.i <= BUFF_SIZE)
	{
		if (buf[t.i] == '\n' && ((t.i % 5) == 4))
		{
			printf("Ligne %d successfully readed !\n", t.x);
			t.x++;
		}
		t.i++;
	}
	if (t.x == 4)
		return (1);
	return (0);
}

static int	valid_form(char *buf)
{
	t_tete t;

	ft_bzero(&t, sizeof(t_tete));
	t.tmp = NULL;
	t.tmp = ft_strnew(BUFF_SIZE);
	while (t.i <= BUFF_SIZE)
	{
		if (buf[t.i] == '#')
		{
			if (buf[t.i + 1] == '#')
				t.j++;
			if (t.i <= 14 && buf[t.i + 5] == '#')
				t.j++;
			if (t.i > 1 && buf[t.i - 1] == '#')
				t.j++;
			if (t.i >= 5 && buf[t.i - 5] == '#')
				t.j++;
		}
		t.i++;
	}
	if (t.j > 4)
	{
		printf("Final value of t.j : %d\n", t.j);
		printf("%s\n", "Tetriminos is valid");
		return (1);
	}
	printf("Final value of t.j : %d\n", t.j);
	printf("%s\n", "Tetriminos is invalid for some reason : abort");
	return (0);
}

int	check_tetriminos(int fd)
{
	t_tete	t;
	int		nb_piece;

	nb_piece = 0;
	ft_bzero(&t, sizeof(t_tete));
	while ((t.ret = read(fd, t.buf, BUFF_SIZE)) > 0)
	{
		if ((nb_line(t.buf) + nb_sigle(t.buf)) == 2)
		{
			if (t.ret != 21 && !(t.ret == 20))
			{
				printf("%s\n", "Invalid tetriminos's lenght : abort");
				return (0);
			}
		}
		else
		{
			printf("%s\n", "Invalid return from length & char check : abort");
			return (0);
		}
		t.size = t.ret;
		if (!(valid_form(t.buf)))
		{
			return (0);
		}
		nb_piece++;
	}
	if (t.size != 20)
	{
		printf("%s\n", "Invalid tetriminos : last tetriminos should have a length of 20");
		return (0);
	}
	return (nb_piece);
}

int get_tetriminos(int fd, t_fill_info *info)
{
	int 	i;
	int		p;
	int		piece;
	char	buff[BUFF_SIZE];
	int		ret;
	t_point	point[4];

	p = 0;
	piece = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && piece < info->nb_piece)
	{
		p = 0;
		i = 0;
		while (i < BUFF_SIZE && p < 4)
		{
			if (buff[i] == '#')
			{
				point[p].x = i % 5;
				point[p].y = i / 5;
				p++;
			}
			i++;
		}
		if (p == 4)
		{
			if (fillit_alloc_piece(info, point, 4, piece) == -1)
				return (0);
		}
		else
			return (0);
		piece++;
	}
	return (1);
}
