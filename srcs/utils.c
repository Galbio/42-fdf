/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:24 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/30 00:55:25 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpx(t_mlx *ds, float x, float y, int color)
{
	char	*pixel;
	int		int_x;
	int		int_y;

	y += ds->cam.off_y;
	x += ds->cam.off_x;
	if (x < 0 || y < 0)
		return ;
	else if (x >= 1000 || y >= 1000)
		return ;
	int_x = (int)x;
	int_y = (int)y;
	pixel = ds->img->addr + (int_y * ds->img->size_line
			+ int_x * (ds->img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

double	fcos(int angle)
{
	return (cos(angle * (M_PI / 180)));
}

double	fsin(int angle)
{
	return (sin(angle * (M_PI / 180)));
}

void	free_array(t_mlx *ds)
{
	int	i;

	free(ds->array.done);
	i = -1;
	while (++i < ds->array.j)
		free(ds->array.map[i]);
	free(ds->array.map);
}

void	swap_points(t_line *p)
{
	double	temp;

	temp = p->x0;
	p->x0 = p->x1;
	p->x1 = temp;
	temp = p->y0;
	p->y0 = p->y1;
	p->y1 = temp;
}
