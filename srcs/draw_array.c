/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:21:36 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/02 15:20:10 by gakarbou         ###   ########.fr       */
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
		putpx(ds, p);
		if ((p.x0 == p.x1) && (p.y0 == p.y1))
			break ;
		error2 = error * 2;
		if (error2 >= dy)
		{
			error += dy;
			p.x0 += incr_x;
		}
		if (error2 <= dx)
			error += dx;
		if (error2 <= dx)
			p.y0 += incr_y;
		p.color += p.avg_color;
	}
}

t_line	fill_values(t_mlx *ds, t_line p, t_line save)
{
	int		height[2];

	p.color = ds->array.map[(int)p.y0][(int)p.x0].color;
	p.color2 = ds->array.map[(int)p.y1][(int)p.x1].color;
	height[0] = ds->array.height[((int)p.y0 * ds->array.i) + (int)p.x0];
	height[1] = ds->array.height[((int)p.y1 * ds->array.i) + (int)p.x1];
	p.x0 = ds->cam.off_x + ds->array.map[(int)p.y0][(int)p.x0].x;
	p.x1 = ds->cam.off_x + ds->array.map[(int)p.y1][(int)p.x1].x;
	p.y0 = ds->cam.off_y + ds->array.map[(int)p.y0][(int)save.x0].y;
	p.y1 = ds->cam.off_y + ds->array.map[(int)p.y1][(int)save.x1].y;
	if (height[0] >= 0 && height[1] >= 0)
	{
		p.avg_color = ft_abs(p.color - p.color2);
		p.color -= 0xFF0000;
		p.color2 -= 0xFF0000;
	}
	else
	{
		p.avg_color = ft_abs((p.color / 256) - (p.color2 / 256));
		p.color /= 256;
		p.color2 /= 256;
		p.is_negative = 1;
	}
	return (p);
}

void	draw_line_init(t_mlx *ds, t_line p)
{
	char	incr_x;
	char	incr_y;

	p.is_negative = 0;
	p = fill_values(ds, p, p);
	if ((p.x0 < 0 && p.x1 < 0) || (p.x0 > 1000 && p.x1 > 1000))
		return ;
	if ((p.y0 < 0 && p.y1 < 0) || (p.y0 > 1000 && p.y1 > 1000))
		return ;
	incr_x = 1;
	if (p.x1 < p.x0)
		incr_x = -1;
	incr_y = -1;
	if (p.y1 > p.y0)
		incr_y = 1;
	if (ft_abs(p.x0 - p.x1) > ft_abs(p.y0 - p.y1) && ft_abs(p.x0 - p.x1))
		p.avg_color /= ft_abs(p.x0 - p.x1);
	else if (ft_abs(p.y0 - p.y1))
		p.avg_color /= ft_abs(p.y0 - p.y1);
	if (p.color > p.color2)
		p.avg_color *= -1;
	draw_line(ds, p, incr_x, incr_y);
}

void	draw_array(t_mlx *ds, int x, int y)
{
	t_line	p;

	if (ds->array.done[(y * ds->array.i) + x])
		return ;
	ds->array.done[(y * ds->array.i) + x] = 1;
	p.x0 = x + 0.2;
	p.y0 = y + 0.2;
	p.color = ds->array.map[y][x].color;
	if (x < (ds->array.i - 1))
	{
		p.x1 = x + 1.2;
		p.y1 = y + 0.2;
		draw_line_init(ds, p);
		draw_array(ds, x + 1, y);
	}
	if (y < (ds->array.j - 1))
	{
		p.x1 = x + 0.2;
		p.y1 = y + 1.2;
		draw_line_init(ds, p);
		draw_array(ds, x, y + 1);
	}
}
