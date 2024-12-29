/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:10:04 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/06 13:37:11 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;

	len_little = ft_strlen(little);
	if (!little[0])
		return ((char *)big);
	if (!big[0])
		return (NULL);
	i = -1;
	while ((++i + len_little) <= len && big[i])
		if (!ft_strncmp((char *)big + i, little, len_little))
			return ((char *)big + i);
	return (NULL);
}
