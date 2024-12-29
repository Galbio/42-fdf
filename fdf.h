/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:06:03 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/29 18:27:15 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_line
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
}	t_line;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_array
{
	int		i;
	int		j;
	char	**array;
	char	*done;
	t_point	**map;
}	t_array;

typedef struct s_cam
{
	int		off_y;
	int		off_x;
	int		rotation[3];
	int		height;
	int		zoom;
}	t_cam;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_cam	cam;
	t_array	array;
}	t_mlx;

void	create_cpy(t_mlx *ds);
void	init_points(t_mlx *ds);

#endif
