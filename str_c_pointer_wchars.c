/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_c_pointer_wchars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:58:17 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/24 14:58:21 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_str(va_list ap, t_struc *struc)
{
	int		i;
	int		counter;
	char	*str;
	int		j;

	i = 0;
	counter = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	j = ft_strlen(str);
	if (struc->precision || struc->flag_precision)
	{
		if (struc->precision > j)
			struc->precision = j;
		else
			j = struc->precision;
	}
	else
		struc->precision = j;
	if (struc->minus)
	{
		if (struc->width || struc->width == 0)
		{
			struc->calc_width = struc->width - j;
			if (struc->calc_width < 0)
				struc->calc_width = 0;
			while (str[i] && i < struc->precision)
			{
				write(1, &str[i], 1);
				i++;
			}
			while (struc->calc_width && ++struc->i)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += i + struc->i;
		}
	}
	else if (struc->minus == 0)
	{
		if (struc->width)
		{
			struc->calc_width = struc->width - j;
			if (struc->calc_width < 0)
				struc->calc_width = 0;
			while (struc->calc_width && ++struc->i)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += struc->i;
		}
		if (struc->precision == 0 && struc->flag_precision)
			write(1, "", 0);
		else if (struc->precision)
		{
			while (str[i] && i < struc->precision)
			{
				write(1, &str[i], 1);
				i++;
			}
			struc->count += i;
		}
		else
		{
			ft_putstr(str);
			struc->count += ft_strlen(str);
		}
	}
}

void	ft_char(va_list ap, t_struc *struc)
{
	char	c;
	int		i;

	i = 0;
	i++;
	c = va_arg(ap, int);
	if (!c)
		c = '\0';
	if (struc->minus)
	{
		write(1, &c, 1);
		if (struc->width)
		{
			struc->width -= 1;
			while (struc->width && ++struc->i)
			{
				write(1, " ", 1);
				struc->width--;
			}
		}
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
		write(1, &c, 1);
		struc->count += struc->i;
	}
	else
	{
		write(1, &c, 1);
		struc->count += struc->i;
	}
	struc->count += i;
}

void	ft_pointer(va_list ap, t_struc *struc)
{
	int					i;
	char				*str;
	unsigned long int	j;

	i = 0;
	j = va_arg(ap, unsigned long int);
	str = ft_itoa_base(va_arg(ap, unsigned long int), 16, 1);
	if (!str)

	while (str[i] != '%')
		i++;
	ft_putstr("0x");
	if (j == 0)
	{
		write(1, "", 0);
		struc->count += 2;
	}
	else
	{
		ft_putstr(str);
		struc->count += ft_strlen(str) + 2;
	}
}

void	ft_wchar_s(va_list ap, t_struc *struc)
{
	int		i;
	int		j;
	wchar_t	*str;

	i = 0;
	j = 0;
	str = va_arg(ap, wchar_t*);
	// if (!str)
	// 	str = ft_strdup("(null)");
	while (str[j])
		j++;
	if (struc->precision || struc->flag_precision)
	{
		if (struc->precision > j)
			struc->precision = j;
		else
			j = struc->precision;
	}
	else
		struc->precision = j;
	if (struc->minus)
	{
		if (struc->width || struc->width == 0)
		{
			struc->calc_width = struc->width - j;
			if (struc->calc_width < 0)
				struc->calc_width = 0;
			while (str[i] && i < struc->precision)
			{
				ft_wchar_c(str[i], struc);
				i++;
			}
			while (struc->calc_width && ++struc->i)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += i + struc->i;
		}
	}
	else if (struc->minus == 0)
	{
		if (struc->width)
		{
			struc->calc_width = struc->width - j;
			if (struc->calc_width < 0)
				struc->calc_width = 0;
			while (struc->calc_width && ++struc->i)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += struc->i;
		}
		if (struc->precision == 0 && struc->flag_precision)
			write(1, "", 0);
		else if (struc->precision)
		{
			while (str[i] && i < struc->precision)
			{
				ft_wchar_c(str[i], struc);
				i++;
			}
			struc->count += i;
		}
		else
		{
			while (str[i])
			{
				ft_wchar_c(str[i], struc);
				i++;
			}
			struc->count += i;
		}
	}

	// while (str[i])
	// {
	// 	ft_wchar_c(str[i], struc);
	// 	i++;
	// }
}
