/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:00:57 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/21 01:52:07 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ppat(t_img *img, int x, int y, int color)
{
	img->data[(1920 * y) + x] = color;
}

void	draw_line_high_desc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	x;
	int	d;

	dx = points.x1 - points.x0;
	dy = points.y0 - points.y1;
	d = (2 * dx) - dy;
	x = 0;
	while (points.y0 != points.y1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0 + x,
			points.y0++, 0xffffff);
		if (d >= 0)
		{
			x++;
			d -= ft_abs(2 * dy);
		}
		d += ft_abs(2 * dx);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	draw_line_high_asc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	x;
	int	d;

	dx = points.x1 - points.x0;
	dy = points.y0 - points.y1;
	d = (2 * dx) - dy;
	x = 0;
	while (points.y0 != points.y1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0 + x,
			points.y0--, 0xffffff);
		if (d >= 0)
		{
			x++;
			d -= ft_abs(2 * dy);
		}
		d += ft_abs(2 * dx);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	draw_line_low_desc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	y;
	int	d;

	dx = points.x1 - points.x0;
	dy = points.y1 - points.y0;
	d = (2 * dy) - dx;
	y = 0;
	while (points.x0 != points.x1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr,
			points.x0++, points.y0 + y, 0xffffff);
		if (d >= 0)
		{
			y++;
			d -= (2 * dx);
		}
		d += (2 * dy);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	draw_line_low_asc(t_line_points points, t_mlx_data *ds)
{
	int	dx;
	int	dy;
	int	y;
	int	d;

	dx = points.x1 - points.x0;
	dy = points.y0 - points.y1;
	d = (2 * dy) - dx;
	y = 0;
	while (points.x0 != points.x1)
	{
		mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x0++,
			points.y0 - y, 0xffffff);
		if (d >= 0)
		{
			y++;
			d -= (2 * dx);
		}
		d += (2 * dy);
	}
	mlx_pixel_put(ds->mlx_ptr, ds->win_ptr, points.x1, points.y1, 0xffffff);
}

void	draw_line_init(t_line_points p, t_mlx_data *ds)
{
	int	ret;
	int	ret2;

	ret = p.x0 - p.x1;
	if (ret > 0)
		swap_points(&p);
	ret2 = p.y0 - p.y1;
	if ((ft_abs(p.y0 - p.y1) > ft_abs(p.x0 - p.x1)) && (ret2 >= 0))
		draw_line_high_asc(p, ds);
	else if (ret2 >= 0)
		draw_line_low_asc(p, ds);
	else if (ft_abs(p.y0 - p.y1) > ft_abs(p.x0 - p.x1))
		draw_line_high_desc(p, ds);
	else
		draw_line_low_desc(p, ds);
}
