/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:41:49 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/13 21:51:47 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(t_mlx *ds)
{
	fdf(65307, ds);
	return (0);
}

void	do_zoom(t_mlx *ds, int x, int y)
{
	if (ds->cam.zoom == 0)
		ds->cam.zoom = 1;
	else if (ds->cam.zoom < 9)
		ds->cam.zoom *= 2;
	else
		ds->cam.zoom *= 1.1;
	if (x > ds->cam.off_x)
		ds->cam.off_x += 10;
	else if (x < ds->cam.off_x)
		ds->cam.off_x -= 10;
	if (y > ds->cam.off_y)
		ds->cam.off_y += 10;
	else if (y < ds->cam.off_y)
		ds->cam.off_y -= 10;
}

int	check_mouse(int button, int x, int y, t_mlx *ds)
{
	if (x < 0 || x > 1000 || y < 0 || y < 0)
		return (1);
	if (button == 4)
		do_zoom(ds, x, y);
	else if (button == 5)
		ds->cam.zoom /= 1.1;
	else if (button == 1)
	{
		ds->cam.off_x = x;
		ds->cam.off_y = y;
	}
	else
		return (0);
	fdf(32, ds);
	return (0);
}
