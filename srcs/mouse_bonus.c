/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:41:49 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/30 14:54:50 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(t_mlx *ds)
{
	if (ds->img)
	{
		mlx_destroy_image(ds->mlx_ptr, ds->img->ptr);
		free(ds->img);
	}
	mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
	return (0);
}

int	check_mouse(int button, int x, int y, t_mlx *ds)
{
	if (button == 4)
	{
		ft_printf("Zoom = %d\n", ds->cam.zoom);
		if (ds->cam.zoom == 0)
			ds->cam.zoom = 1;
		else if (ds->cam.zoom < 9)
			ds->cam.zoom *= 2;
		else
			ds->cam.zoom *= 1.1;
		ds->cam.off_x += -x;
		ds->cam.off_y += -y;
	}
	else if (button == 5)
	{
		ds->cam.zoom /= 1.1;
	}
	else
		return (0);
	fdf(32, ds);
}
