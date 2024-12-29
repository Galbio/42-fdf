/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:44:01 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 16:56:49 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = -1;
	c = (unsigned char)c;
	while (s[++i])
		if (s[i] == c)
			return ((char *)s + i);
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
