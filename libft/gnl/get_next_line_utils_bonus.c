/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:30:41 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/13 01:51:06 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	stash_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int fre)
{
	size_t	i;
	size_t	j;
	char	*dest;

	dest = malloc((1 + stash_len(s1) + stash_len(s2)) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	if (fre && s1)
		free(s1);
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;

	i = -1;
	c = (unsigned int)c;
	while (s[++i])
		if (s[i] == c)
			return (1);
	if (s[i] == c)
		return (1);
	return (0);
}

void	*ft_free_stuff(void *p1, void *p2, void *p3)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	return (p3);
}
