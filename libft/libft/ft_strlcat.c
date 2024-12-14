/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:06:05 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 14:08:16 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!size)
		return (ft_strlen(src));
	j = 0;
	while (dst[j] && j < size)
		j++;
	i = -1;
	while (src[++i] && ((j + i) < (size - 1)))
		dst[i + j] = src[i];
	if ((j + i) < size)
		dst[i + j] = 0;
	return (j + ft_strlen(src));
}
