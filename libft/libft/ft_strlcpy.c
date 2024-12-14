/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:03:29 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 12:05:34 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = -1;
	while (++i < (size - 1) && src[i])
		dst[i] = src[i];
	dst[i] = 0;
	return (ft_strlen(src));
}
