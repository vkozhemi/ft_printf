/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:04:40 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/24 17:04:43 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c(va_list ap, t_struc *struc, wchar_t value)
{
	char c;
	
	if (struc->modifier == 'l')
	{
		value = va_arg(ap, wchar_t);
		ft_wchar_c(value, struc);
	}
	else
	{
		c = va_arg(ap, int);
		ft_char(c, struc);
	}
}

void	ft_s(va_list ap, t_struc *struc)
{
	if (struc->modifier == 'l')
		ft_wchar_s(ap, struc);
	else
		ft_str(ap, struc);
}

void	ft_d_i_d(char *p, int *i, va_list ap, t_struc *struc)
{
	if (struc->modifier == 'l' || p[*i] == 'D')
		ft_int(va_arg(ap, long int), struc);
	else if (struc->modifier == 'L')
		ft_int(va_arg(ap, long long int), struc);
	else if (struc->modifier == 'h')
		ft_int((short)va_arg(ap, int), struc);
	else if (struc->modifier == 'H')
		ft_int((char)va_arg(ap, int), struc);
	else if (struc->modifier == 'j')
		ft_int(va_arg(ap, intmax_t), struc);
	else if (struc->modifier == 'z')
		ft_int(va_arg(ap, size_t), struc);
	else
		ft_int(va_arg(ap, int), struc);
}

void	ft_u_x_o(char *p, int *i, va_list ap, t_struc *struc)
{
	if (struc->modifier == 'l')
		ft_uns_int(va_arg(ap, unsigned long int), struc, p, i);
	else if (struc->modifier == 'L')
		ft_uns_int(va_arg(ap, unsigned long long int), struc, p, i);
	else if (struc->modifier == 'h' && p[*i] != 'U')
		ft_uns_int((unsigned short)va_arg(ap, unsigned int), struc, p, i);
	else if (struc->modifier == 'H' && (p[*i] == 'O' || p[*i] == 'U'))
		ft_uns_int((unsigned int)va_arg(ap, unsigned int), struc, p, i);
	else if (struc->modifier == 'H')
		ft_uns_int((unsigned char)va_arg(ap, unsigned int), struc, p, i);
	else if (struc->modifier == 'j')
		ft_uns_int(va_arg(ap, uintmax_t), struc, p, i);
	else if (struc->modifier == 'z')
		ft_uns_int(va_arg(ap, size_t), struc, p, i);
	else if (p[*i] == 'U' || p[*i] == 'O')
		ft_uns_int(va_arg(ap, unsigned long int), struc, p, i);
	else
		ft_uns_int(va_arg(ap, unsigned int), struc, p, i);
}

void	ft_percent(t_struc *struc)
{
	if (struc->minus)
	{
		write(1, "%", 1);
		if (struc->width)
		{
			struc->width -= 1;
			while (struc->width && ++struc->i)
			{
				write(1, " ", 1);
				struc->width--;
			}
		}
		struc->i += 1;
		struc->count += struc->i;
	}
	else if (struc->minus == 0)
	{
		if (struc->width)
		{
			struc->width -= 1;
			while (struc->width && ++struc->i)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->width--;
			}
		}
		write(1, "%", 1);
		struc->i += 1;
		struc->count += struc->i;
	}
	ft_bzero(struc, sizeof(int) * 22 + sizeof(char) * 3);
}

void	ft_conversions(char *p, int *i, va_list ap, t_struc *struc)
{
	wchar_t value;

	ft_get_conversions(p, i, struc);
	ft_get_conversions_str(p, i, struc);
	if (p[*i] == 'c')
		ft_c(ap, struc, value);
	else if (p[*i] == 's')
		ft_s(ap, struc);
	else if (p[*i] == 'd' || p[*i] == 'i' || p[*i] == 'D')
		ft_d_i_d(p, i, ap, struc);
	else if (p[*i] == 'u' || p[*i] == 'U' || p[*i] == 'o' || p[*i] == 'O'
			|| p[*i] == 'x' || p[*i] == 'X')
		ft_u_x_o(p, i, ap, struc);
	else if (p[*i] == 'C')
	{
		value = va_arg(ap, wchar_t);
		ft_wchar_c(value, struc);
	}
	else if (p[*i] == 'S')
		ft_wchar_s(ap, struc);
	else if (p[*i] == 'p')
		ft_pointer(ap, struc);
	else if (p[*i] == '%')
		ft_percent(struc);
}
