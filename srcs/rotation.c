/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:04 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/12 23:32:27 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_part_two(t_mlx *ds, int i, int j, int rotation[3])
{
	double	temp[3];

	temp[1] = (j - (ds->array.j / 2)) * ds->cam.zoom;
	temp[2] = ds->array.height[(j * ds->array.i) + i]
		* (((float)ds->cam.zoom / 10) + ds->cam.height);
	ds->array.map[j][i].y = round((temp[1] * fcos(rotation[0]))
			+ (-temp[2] * fsin(rotation[0])));
	ds->array.map[j][i].z = round((temp[1] * fsin(rotation[0]))
			+ (temp[2] * fcos(rotation[0])));
	temp[0] = (i - (ds->array.i / 2)) * ds->cam.zoom;
	temp[2] = ds->array.map[j][i].z;
	ds->array.map[j][i].x = round((temp[0] * fcos(rotation[1]))
			+ (temp[2] * fsin(rotation[1])));
	ds->array.map[j][i].z = round((-temp[0] * fsin(rotation[1]))
			+ (temp[2] * fcos(rotation[1])));
	temp[0] = ds->array.map[j][i].x;
	temp[1] = ds->array.map[j][i].y;
	ds->array.map[j][i].x = round((temp[0] * fcos(rotation[2]))
			+ (temp[1] * fsin(rotation[2]) * -1));
	ds->array.map[j][i].y = round((temp[0] * fsin(rotation[2]))
			+ (temp[1] * fcos(rotation[2])));
}

void	change_x(t_mlx *ds, int rotation[3])
{
	int		i;
	int		j;

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
			rotate_part_two(ds, i, j, rotation);
	}
}
