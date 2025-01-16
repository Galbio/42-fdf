/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:24 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/16 15:33:17 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update_color(t_line p, t_mlx *ds)
{
	int	res;

	if (!ds->bon.colors)
		return (0xFFFFFF);
	p.cur_color = (float)p.cur_color / 100;
	res = p.colors[0].red + ((p.colors[1].red - p.colors[0].red) * p.cur_color);
	res = res * 256;
	res += p.colors[0].green + ((p.colors[1].green - p.colors[0].green)
			* p.cur_color);
	res = res * 256;
	res += p.colors[0].blue + ((p.colors[1].blue - p.colors[0].blue)
			* p.cur_color);
	if (!res)
		return (1);
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
	if (*(int *)pixel == 0)
		*(int *)pixel = update_color(p, ds);
}

double	fcos(int angle)
{
	return (cos(angle * (M_PI / 180)));
}

double	fsin(int angle)
{
	return (sin(angle * (M_PI / 180)));
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
