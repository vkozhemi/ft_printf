/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:14:44 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/24 18:14:54 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>

typedef struct	s_struc
{
	int			minus;
	int			plus;
	int			noll;
	int			hash;
	int			space;
	int			width;
	int			calc_width;
	int			precision;
	int			calc_precision;
	int			flag_precision;
	int			flag_int;
	int			flag_uns_int;
	char		modifier;
	char		conversions;
	char		str;
	int			i;
	size_t		count;
}				t_struc;

int		ft_printf(char *fmt, ...);
void	ft_call_pars(char *fmt, va_list ap, t_struc *struc);
void	ft_conversions(char *p, int *i, va_list ap, t_struc *struc);
void	ft_get_conversions(char *p, int *i, t_struc *struc);
void	ft_get_conversions_str(char *p, int *i, t_struc *struc);
void	ft_flags(char *p, int *i, t_struc *struc);
void	ft_field_width(char *p, int *i, t_struc *struc);
void	ft_precision(char *p, int *i, t_struc *struc);
void	ft_size_modifier(char *p, int *i, t_struc *struc);
void	ft_int(intmax_t d, t_struc *struc);
void	ft_uns_int(uintmax_t d, t_struc *struc, char *p, int *i);
void	ft_long_int(va_list ap, t_struc *struc);
void	ft_uns_long_int(va_list ap, t_struc *struc);
void	ft_uns_long_oct(va_list ap, t_struc *struc);
void	ft_uns_oct(uintmax_t d, t_struc *struc);
void	ft_uns_hex(uintmax_t d, t_struc *struc);
void	ft_uns_hexb(va_list ap, t_struc *struc);
void	ft_pointer(va_list ap, t_struc *struc);
void	ft_char(va_list ap, t_struc *struc);
void	ft_str(va_list ap, t_struc *struc);
int		ft_size_bin(wchar_t value);
void	ft_wchar_c(wchar_t value, t_struc *struc);
void	ft_wchar_c11(unsigned int v, unsigned char octet, t_struc *struc);
void	ft_wchar_c16(unsigned int v, unsigned char octet, t_struc *struc);
void	ft_wchar_c32(unsigned int v, unsigned char octet, t_struc *struc);
void	ft_wchar_s(va_list ap, t_struc *struc);
char	ft_plus_minus_int(intmax_t d, char **str);
void	ft_find_precision_int(t_struc *struc, char *str);
void	ft_width_int(t_struc *struc, char *str, int d);
void	ft_flag_minus_int_0(t_struc *struc, int d);
void	ft_flag_minus_int(t_struc *struc, char *str, int d);
void	ft_flag_no_minus_int_0(t_struc *struc, int d);
void	ft_flag_no_minus_int_1(t_struc *struc, int d);
void	ft_flag_no_minus_int_2(t_struc *struc, int d);
void	ft_flag_no_minus_int_3(t_struc *struc, int d);
void	ft_flag_no_minus_int(t_struc *struc, char *str, int d);
void	ft_count_int(t_struc *struc, char *str, int d);
void	ft_flag_minus_uns_int(t_struc *struc, char *str, int d,
		char *p, int *i);
void	ft_flag_no_minus_uns_int(t_struc *struc, char *str, int d,
		char *p, int *i);

#endif
