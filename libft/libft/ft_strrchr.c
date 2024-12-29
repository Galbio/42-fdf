/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:51:17 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 17:12:53 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		last;

	c = (unsigned char)c;
	i = -1;
	last = -1;
	while (s[++i])
		if (s[i] == c)
			last = i;
	if (s[i] == c)
		return ((char *)s + i);
	if (last == -1)
		return (NULL);
	return ((char *)s + last);
}
