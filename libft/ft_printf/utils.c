/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:58:18 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/26 03:06:11 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_unsigned_log(unsigned int long nb)
{
	if (nb < 16)
		return (1);
	return (1 + ft_unsigned_log(nb / 16));
}

int	ft_atoi_f(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res);
}

void	ft_putnbr_times(int long nb, int len)
{
	if (!len)
		return ;
	if (nb < 0)
		nb = -nb;
	ft_putnbr_times(nb / 10, len - 1);
	write(1, &("0123456789"[nb % 10]), 1);
}

void	ft_putaddr_times(unsigned long addr, int len, char *base)
{
	if (!len)
		return ;
	ft_putaddr_times(addr / 16, len - 1, base);
	write(1, &(base[addr % 16]), 1);
}
