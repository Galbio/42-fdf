/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:10:35 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 15:23:43 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*buff;
	size_t	i;

	buff = (char *)s;
	i = -1;
	while (++i < n)
		buff[i] = c;
	return (s);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (!n)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = -1;
	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (++i < len)
		if (str[i] == c)
			return ((void *)s + i);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int long		i;

	if (!dest && !src)
		return (NULL);
	if (src >= dest)
		return (ft_memcpy(dest, src, n));
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = n;
	while (--i >= 0)
		d[i] = s[i];
	return (dest);
}
