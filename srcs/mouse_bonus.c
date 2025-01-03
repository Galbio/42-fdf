/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:41:49 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/03 16:19:51 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(t_mlx *ds)
{
	fdf(65307, ds);
	return (0);
}

int	check_mouse(int button, int x, int y, t_mlx *ds)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		ft_printf("Zoom = %d\n", ds->cam.zoom);
		if (ds->cam.zoom == 0)
			ds->cam.zoom = 1;
		else if (ds->cam.zoom < 9)
			ds->cam.zoom *= 2;
		else
			ds->cam.zoom *= 1.1;
	}
	else if (button == 5)
		ds->cam.zoom /= 1.1;
	else
		return (0);
	fdf(32, ds);
	return (0);
}
