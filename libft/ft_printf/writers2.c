/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:53:33 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/02 17:03:52 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(int c, int *flags)
{
	int	res;

	res = 0;
	while (!flags[4] && res < (flags[7] - 1))
		res += write(1, " ", 1);
	write(1, &c, 1);
	while (flags[4] && res < (flags[7] - 1))
		res += write(1, " ", 1);
	return (res + 1);
}

void	ft_manage_addr_flags(int *flags, unsigned long addr, int *len)
{
	if (flags[6])
		*len = ft_max(*len, flags[8]);
	if (flags[6] && !flags[8] && !addr)
		*len = 0;
	if (flags[1] || flags[2])
		flags[2] = 0;
	if ((flags[6] || (flags[4] && flags[5])))
		flags[5] = 0;
}

int	ft_write_addr(unsigned long addr, int *flags)
{
	int	res;
	int	len;

	if (!addr)
	{
		flags[6] = 0;
		return (ft_write_string("(nil)", flags));
	}
	ft_manage_addr_flags(flags, addr, &len);
	res = 0;
	len = ft_unsigned_log(addr);
	while (!flags[4] && flags[7] && !flags[5]
		&& (((flags[1] || flags[2]) + res + len + 2) < flags[7]))
		res += write(1, " ", 1);
	if (flags[2])
		res += write(1, " ", 1);
	else if (flags[1])
		res += write(1, "+", 1);
	if (flags[5])
		len = ft_max(flags[7] - res, len);
	write(1, "0x", 2);
	ft_putaddr_times(addr, len, "0123456789abcdef");
	while (flags[4] && ((len + res + 2) < flags[7]))
		res += write(1, " ", 1);
	return (res + len + 2);
}

char	return_x_base(char c)
{
	if (c == 'A')
		write(1, "X", 1);
	else
		write(1, "x", 1);
	return (0);
}

int	ft_hex(unsigned int hex, int *flags, char *base)
{
	int	res;
	int	len;

	len = ft_log(hex, 16);
	res = ((hex != 0) * flags[3] * 2);
	if (flags[6])
		len = ft_max(len, flags[8]);
	if (flags[6] && !flags[8] && !hex)
		len = 0;
	if ((flags[4] || flags[6]) && flags[5])
		flags[5] = 0;
	while (!flags[4] && flags[7] && !flags[5]
		&& (res + len) < flags[7])
		res += write(1, " ", 1);
	if (hex && flags[3])
		write(1, "0", 1);
	if (hex && flags[3])
		return_x_base(base[10]);
	if (flags[5])
		len = ft_max(flags[7] - res, len);
	ft_putaddr_times(hex, len, base);
	while (flags[4] && ((len + res) < flags[7]))
		write(1, " ", 1);
	return (res + len);
}
