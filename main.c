/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:24:37 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/11 20:49:29 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_create.h"

int	main(int ac, char **av)
{
	char *matrix[] = {"0010110",
					"1001001",
					"0110010",
					"1001000",
					"0100001",
					"0001101",};
	ft_alloc_matrix(matrix, 7, 6);
	return (0);
}