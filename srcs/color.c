/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:06:44 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/02 15:23:24 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_height(t_mlx *ds)
{
	int	i;
	int	max;
	int	min;

	ds->array.height = malloc((ds->array.j * ds->array.i) * sizeof(int));
	i = -1;
	max = ft_atoi(ds->array.array[0]);
	min = max;
	while (++i < ds->array.j * ds->array.i)
	{
		ds->array.height[i] = ft_atoi(ds->array.array[i]);
		if (ds->array.height[i] > max)
			max = ds->array.height[i];
		else if (ds->array.height[i] < min)
			min = ds->array.height[i];
	}
	ds->array.extr[0] = min;
	ds->array.extr[1] = max;
}

int	get_color(t_mlx *ds, int y, int x)
{
	int		height;
	double	temp;

	height = ds->array.height[(ds->array.i * y) + x];
	if (height > 0)
	{
		temp = (double)0xffff / ft_abs(ds->array.extr[1]);
		return (round(0xFFFFFF - (temp * height)));
	}
	else if (height < 0)
	{
		temp = (double)0xffff / ft_abs(ds->array.extr[0]);
		return (round(0x0000FF + (temp	* (ds->array.extr[0] - height))));
	}
	return (0xFFFFFF);
}
