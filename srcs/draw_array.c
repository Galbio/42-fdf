/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:21:36 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/16 15:59:18 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlx *ds, t_line p, char incr_x, char incr_y)
{
	double	dx;
	double	dy;
	double	error[2];

	dx = ft_abs(p.x0 - p.x1);
	dy = ft_abs(p.y0 - p.y1) * -1;
	error[0] = dx + dy;
	while (1 && ds->bon.draw_lines)
	{
		putpx(ds, p);
		if ((p.x0 == p.x1) && (p.y0 == p.y1))
			break ;
		error[1] = error[0] * 2;
		if (error[1] >= dy)
			error[0] += dy;
		if (error[1] >= dy)
			p.x0 += incr_x;
		if (error[1] <= dx)
			error[0] += dx;
		if (error[1] <= dx)
			p.y0 += incr_y;
		p.cur_color += p.avg_color;
	}
	putpx(ds, p);
}

t_line	fill_values(t_mlx *ds, t_line p, t_line save)
{
	p.colors[0] = (ds->array.colors[((int)p.y0 * ds->array.i) + (int)p.x0]);
	p.colors[1] = (ds->array.colors[((int)p.y1 * ds->array.i) + (int)p.x1]);
	p.x0 = round(ds->cam.off_x + ds->array.map[(int)p.y0][(int)p.x0].x);
	p.x1 = round(ds->cam.off_x + ds->array.map[(int)p.y1][(int)p.x1].x);
	p.y0 = round(ds->cam.off_y + ds->array.map[(int)p.y0][(int)save.x0].y);
	p.y1 = round(ds->cam.off_y + ds->array.map[(int)p.y1][(int)save.x1].y);
	p.cur_color = 0;
	p.avg_color = (double)100 / ft_max(ft_abs(p.x0 - p.x1),
			ft_abs(p.y0 - p.y1));
	if (!ds->bon.draw_lines)
	{
		putpx(ds, p);
		swap_points(&p);
		p.colors[0] = p.colors[1];
		putpx(ds, p);
	}
	return (p);
}

void	draw_line_init(t_mlx *ds, t_line p)
{
	char	incr_x;
	char	incr_y;

	p = fill_values(ds, p, p);
	if (!ds->bon.draw_lines)
		return ;
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
