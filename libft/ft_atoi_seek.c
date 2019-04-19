/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_seek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 23:23:04 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 23:36:48 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_atoi_seek(const char *str, int *ret)
{
	int				i;
	unsigned int	r;
	int				neg;

	i = 0;
	r = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = (str[i] == '-' ? -1 : 1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	*ret = ((int)(neg * (int)r));
	return ((char*)&str[i]);
}
