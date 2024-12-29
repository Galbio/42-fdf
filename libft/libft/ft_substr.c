/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:53 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 17:29:29 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*dest;

	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	size -= start;
	if (len > size)
		len = size;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = s[i + start];
	dest[i] = 0;
	return (dest);
}
