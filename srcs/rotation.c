/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:04 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/30 00:55:14 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_x(t_mlx *ds, int x)
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
			temp = ds->array.map[j][i].y;
			temp2 = ds->array.map[j][i].z;
			ds->array.map[j][i].y = round((temp * fcos(x))
					+ (-temp2 * fsin(x)));
			ds->array.map[j][i].z = round((temp * fsin(x)) + (temp2 * fcos(x)));
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
			temp = ds->array.map[j][i].x;
			temp2 = ft_atoi(ds->array.array[(j * ds->array.i) + i])
				* (ds->cam.zoom + ds->cam.height);
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
