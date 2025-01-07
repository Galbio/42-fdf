/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:06:44 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/07 00:11:51 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_height(t_mlx *ds)
{
	int	i;
	int	max;
	int	min;

	ds->array.height = malloc((ds->array.j * ds->array.i) * sizeof(int));
	i = -1;
	max = ft_atoi(ds->array.array[0]);
	min = max;
	while (++i < ds->array.j * ds->array.i)
	{
		ds->array.height[i] = ft_atoi(ds->array.array[i]);
		if (ds->array.height[i] > max)
			max = ds->array.height[i];
		else if (ds->array.height[i] < min)
			min = ds->array.height[i];
	}
	ds->array.extr[0] = min;
	ds->array.extr[1] = max;
}

t_col	nb_to_rgb(int color)
{
	t_col	dest;

	dest.blue = color % 256;
	color /= 256;
	dest.green = color % 256;
	color /= 256;
	dest.red = color;
	return (dest);
}

t_col	convert_col(char *str)
{
	if (str[1] == 'x')
		return (nb_to_rgb(ft_atoi_base(str + 2, "0123456789abcdef")));
	else if (str[1] == 'X')
		return (nb_to_rgb(ft_atoi_base(str + 2, "0123456789ABCDEF")));
	return (nb_to_rgb(0xFFFFFF));
}

t_col	get_color(char *convert, t_mlx *ds, int i)
{
	int		height;
	double	temp;
	char	*hard_colored;

	hard_colored = ft_strchr(convert, ',');
	if (hard_colored)
		return (convert_col(hard_colored + 1));
	height = ds->array.height[i];
	if (height > 0)
	{
		temp = (double)0xffff / ft_abs(ds->array.extr[1]);
		return (nb_to_rgb(round(0xFFFFFF - (temp * height))));
	}
	else if (height < 0)
	{
		temp = (double)0xffff / ft_abs(ds->array.extr[0]);
		return (nb_to_rgb(round(0x0000FF + ((temp * (ft_abs(ds->array.extr[0]
									- height))) * 256))));
	}
	return (nb_to_rgb(0xffffff));
}

void	fill_colors(t_mlx *ds)
{
	t_col	*colors;
	int		i;

	colors = malloc(sizeof(t_col) * (ds->array.i * ds->array.j));
	i = -1;
	while (++i < (ds->array.j * ds->array.i))
		colors[i] = get_color(ds->array.array[i], ds, i);
	ds->array.colors = colors;
}
