/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:55:24 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/01 23:30:19 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (p.is_negative)
		p.color = (p.color * 256) + 255;
	else
		p.color = (p.color + 0xFF0000);
	pixel = ds->img->addr + (y * ds->img->size_line
			+ x * (ds->img->bits_per_pixel / 8));
	*(int *)pixel = p.color;
}

double	fcos(int angle)
{
	return (cos(angle * (M_PI / 180)));
}

double	fsin(int angle)
{
	return (sin(angle * (M_PI / 180)));
}

void	free_array(t_mlx *ds)
{
	int	i;

	free(ds->array.done);
	i = -1;
	while (++i < ds->array.j)
		free(ds->array.map[i]);
	free(ds->array.map);
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
