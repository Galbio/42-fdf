/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:21:36 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/30 00:21:39 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlx *ds, t_line p, char incr_x, char incr_y)
{
	double	dx;
	double	dy;
	double	error;
	double	error2;

	dx = ft_abs(p.x0 - p.x1);
	dy = ft_abs(p.y0 - p.y1) * -1;
	error = dx + dy;
	while (1)
	{
		putpx(ds, p.x0, p.y0, 0xFFFFFF);
		if ((p.x0 == p.x1) && (p.y0 == p.y1))
			break ;
		error2 = error * 2;
		if (error2 >= dy)
		{
			error += dy;
			p.x0 += incr_x;
		}
		if (error2 <= dx)
		{
			error += dx;
			p.y0 += incr_y;
		}
	}
}

void	draw_line_init(t_mlx *ds, t_line p)
{
	char	incr_x;
	char	incr_y;

	incr_x = 1;
	if (p.x1 < p.x0)
		incr_x = -1;
	incr_y = -1;
	if (p.y1 > p.y0)
		incr_y = 1;
	draw_line(ds, p, incr_x, incr_y);
}

void	draw_array(t_mlx *ds, int x, int y)
{
	t_line	p;

	if (ds->array.done[(y * ds->array.i) + x])
		return ;
	ds->array.done[(y * ds->array.i) + x] = 1;
	p.x0 = ds->array.map[y][x].x;
	p.y0 = ds->array.map[y][x].y;
	if (x < (ds->array.i - 1))
	{
		p.x1 = ds->array.map[y][x + 1].x;
		p.y1 = ds->array.map[y][x + 1].y;
		draw_line_init(ds, p);
		draw_array(ds, x + 1, y);
	}
	if (y < (ds->array.j - 1))
	{
		p.x1 = ds->array.map[y + 1][x].x;
		p.y1 = ds->array.map[y + 1][x].y;
		draw_line_init(ds, p);
		draw_array(ds, x, y + 1);
	}
}
