/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:04:24 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/20 22:04:38 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_points(t_line_points *p)
{
	int	temp;

	temp = p->x0;
	p->x0 = p->x1;
	p->x1 = temp;
	temp = p->y0;
	p->y0 = p->y1;
	p->y1 = temp;
}

double	get_line_x_coor(int dist, int angle)
{
	return (dist * cos(angle * (M_PI / 180)));
}

double	get_line_y_coor(int dist, int angle)
{
	return (dist * sin(angle * (M_PI / 180)));
}
