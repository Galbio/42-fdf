/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:02:34 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/20 23:19:21 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	norm_in_a_nutshell(t_mlx_data *ds, int x, int y, t_line_points p)
{
	p.x1 = p.x0 - get_line_x_coor(ds->cam.cam_zoom,
			ds->cam.z_rotation - 90);
	p.y1 = p.y0 - get_line_y_coor(ds->cam.cam_zoom,
			ds->cam.z_rotation - 90);
	if (ft_atoi(ds->array.array[(ds->array.array_i * (y + 1)) + x]))
		p.color = 0xFF0000;
	else
		p.color = 0xFFFFFF;
	draw_line_init(p, ds);
	swap_points(&p);
	draw_grid(ds, x, y + 1, p);
}

char	draw_grid(t_mlx_data *ds, int x, int y, t_line_points p)
{
	if (ds->array.done[(y * ds->array.array_i) + x])
		return (0);
	ds->array.done[(y * ds->array.array_i) + x] = 1;
	if (y < (ds->array.array_j - 1))
		norm_in_a_nutshell(ds, x, y, p);
	if (x < (ds->array.array_i - 1))
	{
		p.x1 = p.x0 + get_line_x_coor(ds->cam.cam_zoom, ds->cam.z_rotation);
		p.y1 = p.y0 + get_line_y_coor(ds->cam.cam_zoom, ds->cam.z_rotation);
		if (ft_atoi(ds->array.array[(ds->array.array_i * y) + x + 1]))
			p.color = 0xFF0000;
		else
			p.color = 0xFFFFFF;
		draw_line_init(p, ds);
		swap_points(&p);
		draw_grid(ds, x + 1, y, p);
	}
	return (0);
}

void	draw_array_x(t_mlx_data *ds, int x, int y, t_line_points p)
{
	int	up_factor;
	int	up_factor_other;

	up_factor = ft_atoi(ds->array.array[(ds->array.array_i * y) + x])
		* (ds->cam.height);
	p.y1 = p.y0 + get_line_y_coor(ds->cam.cam_zoom, ds->cam.x_rotation
			+ p.angle + ds->cam.z_rotation);
	if (x < (ds->array.array_i - 1))
	{
		p.x1 = p.x0 + get_line_x_coor(ds->cam.cam_zoom, ds->cam.x_rotation
				+ p.angle + ds->cam.z_rotation);
		up_factor_other = ft_atoi(ds->array.array[(ds->array.array_i * y) + x
				+ 1]) * (ds->cam.height);
		p.y0 -= up_factor;
		p.y1 -= up_factor_other;
		if (up_factor || up_factor_other)
			p.color = 0xFF0000;
		else
			p.color = 0xFFFFFF;
		draw_line_init(p, ds);
		p.y1 += up_factor_other;
		p.y0 += up_factor;
		swap_points(&p);
		draw_array(ds, x + 1, y, p);
	}
}

void	draw_array_y(t_mlx_data *ds, int x, int y, t_line_points p)
{
	int	up_factor;
	int	up_factor_other;

	up_factor = ft_atoi(ds->array.array[(ds->array.array_i * y) + x])
		* (ds->cam.height);
	p.y1 = p.y0 + get_line_y_coor(ds->cam.cam_zoom, ds->cam.y_rotation
			+ p.angle - ds->cam.z_rotation);
	if (y < (ds->array.array_j - 1))
	{
		p.x1 = p.x0 - get_line_x_coor(ds->cam.cam_zoom, ds->cam.y_rotation
				+ p.angle - ds->cam.z_rotation);
		up_factor_other = ft_atoi(ds->array.array[(ds->array.array_i * (y + 1))
				+ x]) * (ds->cam.height);
		p.y0 -= up_factor;
		p.y1 -= up_factor_other;
		if (up_factor || up_factor_other)
			p.color = 0xFF0000;
		else
			p.color = 0xFFFFFF;
		draw_line_init(p, ds);
		p.y1 += up_factor_other;
		p.y0 += up_factor;
		swap_points(&p);
		draw_array(ds, x, y + 1, p);
	}
}

char	draw_array(t_mlx_data *ds, int x, int y, t_line_points p)
{
	t_line_points	save;

	if (ds->array.done[(y * ds->array.array_i) + x])
		return (0);
	else if (p.angle < 0)
		return (draw_grid(ds, 0, 0, p));
	ds->array.done[(y * ds->array.array_i) + x] = 1;
	save = p;
	draw_array_x(ds, x, y, save);
	draw_array_y(ds, x, y, save);
	return (0);
}
