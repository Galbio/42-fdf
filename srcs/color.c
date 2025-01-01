/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:06:44 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/02 00:52:29 by gakarbou         ###   ########.fr       */
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

void	get_color(t_mlx *ds, int y, int x)
{
	char	*to_convert;
	int		height;
	double	temp;

	to_convert = ft_strchr(ds->array.array[(ds->array.i * y) + x], ',');
	if (0 && !to_convert)
		return ;
	height = ds->array.height[(ds->array.i * y) + x];
	if (!height)
		ds->array.map[y][x].color = 0xFFFFFF;
	else if (height > 0)
	{
		temp = (double)0xffff / ft_abs(ds->array.extr[1]);
		ds->array.map[y][x].color = round(0xFFFFFF - (temp * height));
	}
	else
	{
		temp = (double)0xffff / ft_abs(ds->array.extr[0]);
		ds->array.map[y][x].color = round(0x0000FF + (temp
					* (ds->array.extr[0] - height)));
	}
}
