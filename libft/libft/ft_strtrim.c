/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:08 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 15:22:29 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_in_str(char const c, char const *str)
{
	size_t	j;

	j = -1;
	while (str[++j])
		if (str[j] == c)
			return (1);
	return (0);
}

static size_t	get_length(char const *s1, char const *set)
{
	size_t	res;
	size_t	last;
	size_t	i;

	res = 0;
	last = 0;
	i = -1;
	while (s1[++i])
	{
		last++;
		if (!c_in_str(s1[i], set))
			res = last;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*dest;

	i = 0;
	while (s1[i] && c_in_str(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	size = get_length((char *)s1 + i, set);
	dest = malloc((size + 1) * sizeof(char));
	if (!dest)
		return (dest);
	j = -1;
	while (++j < size)
		dest[j] = s1[i + j];
	dest[j] = 0;
	return (dest);
}
