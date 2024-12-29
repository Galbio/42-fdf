/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:46 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/26 03:00:02 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

void			init_flags(int *flags);
void			ft_get_bonus_flags(const char *str, int *flags, va_list args);

int				ft_atoi_f(const char *str);
unsigned int	ft_unsigned_log(unsigned int long nb);

void			ft_putnbr_times(int long nb, int len);
void			ft_putaddr_times(unsigned long nb, int len, char *base);

int				ft_printf(const char *format, ...);
int				ft_write_integer(int nb, int *flags, int res);
int				ft_write_unsigned(unsigned int nb, int *flags);
int				ft_write_addr(unsigned long addr, int *flags);
int				ft_write_char(int c, int *flags);
int				ft_hex(unsigned int hex, int *flags, char *base);
int				ft_write_string(char *str, int *flags);

#endif
