/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:31:23 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/26 03:03:12 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_stash(char *stash, int fd)
{
	char	*dest;
	char	*temp;
	int		readed;

	dest = ft_securejoin(stash, NULL, 0);
	if (stash)
		free(stash);
	readed = 1;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (readed > 0 && !ft_strchr(dest, '\n'))
	{
		readed = read(fd, temp, BUFFER_SIZE);
		if (readed < 0)
			return (free(temp), free(dest), NULL);
		temp[readed] = 0;
		dest = ft_securejoin(dest, temp, 1);
	}
	free(temp);
	return (dest);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	if (str[i])
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = 0;
	while (--i >= 0)
		line[i] = str[i];
	return (line);
}

char	*move_stash(char *stash)
{
	size_t	i;
	size_t	pos;

	i = -1;
	pos = -1;
	while (stash[++pos])
		if (stash[pos] == '\n')
			break ;
	if (stash[pos])
		pos++;
	while (stash[(++i) + pos])
		stash[i] = stash[i + pos];
	while (pos)
	{
		stash[pos + i - 1] = 0;
		pos--;
	}
	if (!stash[0])
	{
		free(stash);
		stash = NULL;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash[fd] = ft_fill_stash(stash[fd], fd);
	if (!(stash[fd]))
		return (NULL);
	else if (!stash[fd][0])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(stash[fd]);
	if (!line)
		return (NULL);
	stash[fd] = move_stash(stash[fd]);
	return (line);
}
