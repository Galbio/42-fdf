/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:39:50 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/02 16:48:03 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_return_flag(const char c)
{
	const char	*flags = "cspdiuxX%";
	size_t		i;
	int			res;

	i = -1;
	res = 0;
	while (flags[++i])
		if (flags[i] == c)
			res = flags[i];
	return (res);
}

int	ft_start_writers(va_list args, int *flags)
{
	if (flags[0] == 'c')
		return (ft_write_char(va_arg(args, int), flags));
	else if (flags[0] == '%')
		return (write(1, "%", 1));
	else if (flags[0] == 's')
		return (ft_write_string(va_arg(args, char *), flags));
	else if (flags[0] == 'd' || flags[0] == 'i')
		return (ft_write_integer(va_arg(args, int), flags, 0));
	else if (flags[0] == 'u')
		return (ft_write_unsigned(va_arg(args, unsigned int), flags));
	else if (flags[0] == 'p')
		return (ft_write_addr(va_arg(args, unsigned long), flags));
	else if (flags[0] == 'x')
		return (ft_hex(va_arg(args, unsigned int), flags, "0123456789abcdef"));
	else if (flags[0] == 'X')
		return (ft_hex(va_arg(args, unsigned int), flags, "0123456789ABCDEF"));
	return (0);
}

//flags = {char, +, ' ', #, -, 0, ., padding, delim}
int	ft_write_arg(const char *str, va_list args)
{
	int	flags[9];
	int	i;

	init_flags(flags);
	i = -1;
	while (!flags[0] && str[++i])
	{
		flags[0] = ft_return_flag(str[i]);
		ft_get_bonus_flags(str + i, flags, args);
	}
	return (ft_start_writers(args, flags));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		length;

	length = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			length += ft_write_arg(format + i + 1, args);
			i++;
			while (!ft_return_flag(format[i]))
				i++;
		}
		else
			length += write(1, format + i, 1);
	}
	va_end(args);
	return (length);
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;
	char	*str = "wwerre";

	a = printf("%00*X\n", -76, 2873118869u);
	b = ft_printf("%00*X\n", -76, 2873118869u);
	printf("%d - %d\n", a, b);
}
*/
