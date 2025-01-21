/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:52:46 by gakarbou          #+#    #+#             */
/*   Updated: 2025/01/20 20:11:58 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int long	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

int long	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int long	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int long	ft_log(int long nb, unsigned int len)
{
	if (nb < 0)
		return (1 + ft_log(-nb, len));
	if ((nb / len) == 0)
		return (1);
	return (1 + ft_log(nb / len, len));
}
