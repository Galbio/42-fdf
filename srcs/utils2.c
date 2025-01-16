/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:09:53 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/16 16:00:14 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_ds(t_mlx *ds)
{
	int	i;

	i = -1;
	mlx_destroy_window(ds->mlx_ptr, ds->win_ptr);
	mlx_destroy_display(ds->mlx_ptr);
	free(ds->mlx_ptr);
	while (++i < (ds->array.j * ds->array.i))
		free(ds->array.array[i]);
	free(ds->array.height);
	free(ds->array.array);
	free(ds->array.colors);
	i = -1;
	while (++i < ds->array.j)
		free(ds->array.map[i]);
	free(ds->array.map);
}

void	fill_array(char *filename, t_mlx *ds, size_t size)
{
	char	*buffer;
	int		fd;

	buffer = malloc((size + 1) * sizeof(char));
	fd = open(filename, O_RDONLY);
	read(fd, buffer, size);
	buffer[size] = 0;
	ds->array.j = ft_count_char(buffer, '\n');
	ds->array.array = ft_split(ft_str_replace_char(buffer, '\n', ' '), ' ');
	ds->array.i = array_len(ds->array.array) / ds->array.j;
	free(buffer);
}

void	parse_map(char *filename, t_mlx *ds)
{
	size_t	size[2];
	int		fd;
	char	buffer[2048];

	size[1] = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (1)
	{
		size[0] = read(fd, buffer, sizeof(buffer));
		if (!size[0])
			break ;
		size[1] += size[0];
	}
	close(fd);
	fill_array(filename, ds, size[1]);
	init_height(ds);
}
