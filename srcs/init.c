/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:52:55 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/21 01:52:25 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_points	prepare_points(int x0, int y0, int x1, int y1)
{
	t_line_points	dest;

	dest.x0 = x0;
	dest.x1 = x1;
	dest.y0 = y0;
	dest.y1 = y1;
	return (dest);
}

t_line_points	init_p(int angle, t_cam_control cam, t_mlx_data *ds)
{
	t_line_points	dest;

	(void)ds;
	dest.x0 = 650 + cam.x_offset;
	dest.y0 = 650 + cam.y_offset;
	dest.angle = angle;
	dest.color = 0xFFFFFF;
	return (dest);
}

void	init_ds(t_mlx_data *ds)
{
	ds->cam.x_offset = 0;
	ds->cam.y_offset = 0;
	ds->cam.x_rotation = 0;
	ds->cam.y_rotation = 0;
	ds->cam.z_rotation = 0;
	ds->cam.cam_zoom = 30;
	ds->cam.height = 30;
}

int	close_mlx(t_mlx_data *ds)
{
	if (ds->img_ptr)
		mlx_destroy_image(ds->mlx_ptr, ds->img_ptr);
	mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
	ds->win_ptr = NULL;
	return (0);
}
