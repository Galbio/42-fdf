/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:44:49 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/02 15:05:59 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_base(char *base)
{
	int	i;

	if (!base[0] || !base[1])
		return (1);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (1);
		else if (*base == 32 || (*base >= 9 && *base <= 13))
			return (1);
		i = 1;
		while (base[i])
			if (base[i++] == *base)
				return (1);
		base++;
	}
	return (0);
}

int	get_index(char c, char *base)
{
	int	res;

	res = 0;
	while (base[res])
	{
		if (base[res] == c)
			break ;
		res++;
	}
	if (!base[res])
		return (-1);
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	len;
	int	index;

	if (ft_check_base(base))
		return (0);
	res = 0;
	sign = 1;
	len = 0;
	while (base[len])
		len++;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	index = get_index(*str, base);
	while (index >= 0)
	{
		res = res * len + (index);
		str++;
		index = get_index(*str, base);
	}
	return (res * sign);
}
