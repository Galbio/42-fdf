/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:24 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/06 14:02:00 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update_color(t_line p)
{
	int	res;

	p.cur_color = (float)p.cur_color / 100;
	res = p.colors[0].red + ((p.colors[1].red - p.colors[0].red) * p.cur_color);
	res = res * 256;
	res += p.colors[0].green + ((p.colors[1].green - p.colors[0].green) * p.cur_color);
	res = res * 256;
	res += p.colors[0].blue + ((p.colors[1].blue - p.colors[0].blue) * p.cur_color);
	return (res);
}

void	putpx(t_mlx *ds, t_line p)
{
	char	*pixel;
	int		x;
	int		y;

	x = (int)p.x0;
	y = (int)p.y0;
	if (x < 0 || y < 0)
		return ;
	else if (x >= 1000 || y >= 1000)
		return ;
	pixel = ds->img->addr + (y * ds->img->size_line
			+ x * (ds->img->bits_per_pixel / 8));
	*(int *)pixel = update_color(p);
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
