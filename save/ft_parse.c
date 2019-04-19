/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:13:10 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 18:18:44 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	re_center(t_point *point, int len)
{
	t_point	min;

	min = point[0];
	while (i < len)
	{
		if (min.x > point.x)
			min.x = point.x;
		if (min.y > point.y)
			min.y = point.y;
		i++;
	}
}
static int	verif_piece_contig(t_point *point, int len)
{
	int		i;

	i = 0;
}

int			parsing_nmino_contig(t_point *point, char bufftest[], int len)
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (i < (len + 1) * len)
	{
		if (i % (len + 1) == len && bufftest[i] != '\n')
			return (-1);
		if (bufftest[i] == '#')
		{
			point[nbr].x = i % (len + 1);
			point[nbr].y = i / (len + 1);
			nbr++;
		}
		else if (i % (len + 1) != len && bufftest[i] != '.')
			return (-1);
		i++;
	}
	if (nbr != len)
		return (-1);
	return (verif_piece_contig);
}

int			parsing_nmino(t_point *point, char bufftest[], int len)
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (i < (len + 1) * len)
	{
		if (i % (len + 1) == len && bufftest[i] != '\n')
			return (-1);
		if (bufftest[i] == '#')
		{
			point[nbr].x = i % (len + 1);
			point[nbr].y = i / (len + 1);
			nbr++;
		}
		else if (i % (len + 1) != len && bufftest[i] != '.')
			return (-1);
		i++;
	}
	if (nbr != len)
		return (-1);
	return (0);
}
