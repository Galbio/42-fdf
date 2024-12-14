/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:34:21 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/05 11:08:38 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	dest = ft_strdup(s);
	if (!dest)
		return (NULL);
	i = -1;
	while (s[++i])
		dest[i] = (*f)(i, dest[i]);
	return (dest);
}
