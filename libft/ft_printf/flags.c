/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:57:02 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/02 16:44:40 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(int *flags)
{
	int	i;

	i = -1;
	while (++i < 9)
		flags[i] = 0;
}

void	ft_fix_flags(int *flags)
{
	if (flags[7] < 0)
		flags[4] = 1;
	if (flags[7] < 0)
		flags[7] *= -1;
	if (flags[8] < 0)
		flags[6] = 0;
}

void	ft_get_bonus_flags(const char *c, int *flags, va_list args)
{
	if (*c == '+')
		flags[1] = 1;
	else if (*c == ' ')
		flags[2] = 1;
	else if (*c == '#')
		flags[3] = 1;
	else if (*c == '-')
		flags[4] = 1;
	else if (*c == '0' && !flags[7] && c[-1] != '.')
		flags[5] = 1;
	else if (*c == '.')
		flags[6] = 1;
	else if (*c == '*' && !flags[6] && !flags[7])
		flags[7] = va_arg(args, int);
	else if (*c >= '0' && *c <= '9' && !flags[6] && !flags[7])
		flags[7] = ft_atoi_f(c);
	else if (*c >= '0' && *c <= '9' && flags[6] && !flags[8])
		flags[8] = ft_atoi_f(c);
	else if (*c == 42 && flags[6] && !flags[8])
		flags[8] = va_arg(args, int);
	ft_fix_flags(flags);
}
