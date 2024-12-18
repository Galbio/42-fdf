/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:30:07 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/18 17:35:55 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "../libft/includes/libft.h"

# ifndef DIST
# define DIST 42
# endif

typedef struct s_pixel
{
	int	value;
	int	color;
}	t_pixel;

typedef struct s_array_info
{
	char	**array;
	int		array_i;
	int		array_j;
}	t_array_info;

typedef struct s_cam_control
{
	int	x_offset;
	int	y_offset;
	int	cam_zoom;
}	t_cam_control;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_array_info	array;
	t_cam_control	cam;
}	t_mlx_data;

typedef struct s_line_points
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	angle;
}	t_line_points;

char	*get_next_line(int fd);

#endif
