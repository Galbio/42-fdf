/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:04 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/07 01:43:41 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_x(t_mlx *ds, int x, int y, int z)
{
	int		i;
	int		j;
	double	temp[3];

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			temp[1] = (j - (ds->array.j / 2)) * ds->cam.zoom;
			temp[2] = ds->array.height[(j * ds->array.i) + i] * ((ds->cam.zoom
						+ (ds->cam.height * 1)) / 1);
			ds->array.map[j][i].y = round((temp[1] * fcos(x))
					+ (-temp[2] * fsin(x)));
			ds->array.map[j][i].z = round((temp[1] * fsin(x)) + (temp[2] * fcos(x)));
			temp[0] = (i - (ds->array.i / 2)) * ds->cam.zoom;
			temp[2] = ds->array.map[j][i].z;
			ds->array.map[j][i].x = round((temp[0] * fcos(y)) + (temp[2] * fsin(y)));
			ds->array.map[j][i].z = round((-temp[0] * fsin(y))
					+ (temp[2] * fcos(y)));
			temp[0] = ds->array.map[j][i].x;
			temp[1] = ds->array.map[j][i].y;
			ds->array.map[j][i].x = round((temp[0] * fcos(z))
					+ (temp[1] * fsin(z) * -1));
			ds->array.map[j][i].y = round((temp[0] * fsin(z)) + (temp[1] * fcos(z)));
		}
	}
}

void	change_y(t_mlx *ds, int y)
{
	int		i;
	int		j;
	double	temp;
	double	temp2;

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			temp = (i - (ds->array.i / 2)) * ds->cam.zoom;
			temp2 = ds->array.map[j][i].z;
			ds->array.map[j][i].x = round((temp * fcos(y)) + (temp2 * fsin(y)));
			ds->array.map[j][i].z = round((-temp * fsin(y))
					+ (temp2 * fcos(y)));
		}
	}
}

void	change_z(t_mlx *ds, int z)
{
	int		i;
	int		j;
	double	temp;
	double	temp2;

	j = -1;
	while (++j < ds->array.j)
	{
		i = -1;
		while (++i < ds->array.i)
		{
			temp = ds->array.map[j][i].x;
			temp2 = ds->array.map[j][i].y;
			ds->array.map[j][i].x = round((temp * fcos(z))
					+ (temp2 * fsin(z) * -1));
			ds->array.map[j][i].y = round((temp * fsin(z)) + (temp2 * fcos(z)));
		}
	}
}
