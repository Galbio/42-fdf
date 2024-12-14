/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:46 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 15:56:24 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memmove(dest, s, len);
	dest[len] = 0;
	return (dest);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;
	size_t	len;

	len = ft_min(n, ft_strlen(s));
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (dest);
	ft_memmove(dest, s, len);
	dest[len] = 0;
	return (dest);
}
