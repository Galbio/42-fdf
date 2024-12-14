/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:29:29 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/06 15:46:43 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*ft_strcdup(char const *s, char c, int i)
{
	char	*dest;
	int		j;

	j = 0;
	while (s[i + j] && s[i + j] != c)
		j++;
	dest = malloc((j + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[j] = 0;
	while (--j >= 0)
		dest[j] = s[i + j];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = -1;
	dest = malloc((1 + count_words(s, c)) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			dest[++j] = ft_strcdup(s, c, i);
		while (s[i] && s[i] != c)
			i++;
	}
	dest[++j] = 0;
	return (dest);
}
