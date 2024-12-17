/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:30:07 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/17 16:25:00 by gakarbou         ###   ########.fr       */
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
# include "../libft/includes/libft.h"

typedef struct s_pixel
{
	int	value;
	int	color;
}	t_pixel;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**array;
	int		array_i;
	int		array_j;
}	t_mlx_data;

typedef struct s_line_points
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_line_points;

char	*get_next_line(int fd);

#endif
