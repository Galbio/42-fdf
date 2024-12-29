/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:23:48 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/26 03:08:13 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_return_dest(int long nb, char *base)
{
	int		size;
	int		len;
	char	*dest;

	len = ft_strlen(base);
	size = ft_log(nb, len) + 1;
	dest = malloc(size * sizeof(char));
	if (!dest)
		return (NULL);
	dest[--size] = 0;
	if (nb < 0)
		nb = -nb;
	while (1)
	{
		dest[--size] = base[nb % len];
		nb /= len;
		if (nb == 0)
			break ;
	}
	if (size != 0)
		dest[0] = '-';
	return (dest);
}

char	*ft_itoa(int n)
{
	return (ft_return_dest(n, "0123456789"));
}
