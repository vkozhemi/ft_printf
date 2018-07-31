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
	ft_bzero(struc, sizeof(int) * 14 + sizeof(char) * 3);
}

void	ft_char(char c, t_struc *struc)
{
	// int		i;

	// i = 0;
	// i++;
	if (!c)
		c = '\0';
	if (struc->width)
	{
		if (struc->minus)
		{
			write(1, &c, 1);
			struc->count++;
			struc->width -= 1;
			while (struc->width && ++struc->count)
			{
				write(1, " ", 1);
				struc->width--;
			}
			struc->count += struc->i;
		}
		else if (struc->minus == 0)
		{
			struc->width -= 1;
			while (struc->width && ++struc->count)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->width--;
			}
			write(1, &c, 1);
			struc->count++;
		}
	}
	else
	{
		write(1, &c, 1);
		struc->count++;
	}
	ft_bzero(struc, sizeof(int) * 14 + sizeof(char) * 3);
}

void	ft_pointer(va_list ap, t_struc *struc)
{
	int					i;
	char				*str;
	unsigned long int	d;

	i = 0;
	d = va_arg(ap, unsigned long int);
	str = ft_itoa_base(d, 16, 1);
	if (struc->precision)
	{
		if (d == 0)
			struc->calc_precision = struc->precision;
		else
			struc->calc_precision = struc->precision - ft_strlen(str);
		if (struc->calc_precision < 0)
			struc->calc_precision = 0;
	}
	else
		struc->calc_precision = 0;
	if (struc->width)
	{
		if (struc->width && struc->precision == 0 && d == 0 && struc->flag_precision)
			struc->calc_width = struc->width - struc->calc_precision - ft_strlen(str) - 1;
		else if (struc->width && struc->precision && struc->flag_precision && d == 0)
			struc->calc_width = struc->width -	struc->calc_precision - ft_strlen(str) - 1;
		else
			struc->calc_width = struc->width -	struc->calc_precision - ft_strlen(str) - 2;
	}
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
	while (str[i] != '%')
		i++;
	if (struc->minus)
	{
		ft_putstr("0x");
		while (struc->calc_precision > 0 && ++struc->i)
		{
			write(1, "0", 1);
			struc->calc_precision--;
		}
		if (struc->flag_precision == 0 && d == 0)
			write(1, "0", 1);
		if (d)
			ft_putstr(str);
		while (struc->calc_width > 0 && ++struc->i)
		{
			write(1, " ", 1);
			struc->calc_width--;
		}
		if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
			struc->count += ft_strlen(str) + 2 + struc->i;
		else if (d == 0)
			struc->count += ft_strlen(str) + 1 + struc->i;
		else
			struc->count += ft_strlen(str) + 2 + struc->i;
	}
	else if (struc->minus == 0)
	{
		if (struc->noll == 0)
		{
			while (struc->calc_width > 0 && ++struc->i)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
		}
		ft_putstr("0x");
		if (struc->noll)
		{
			while (struc->calc_width > 0 && ++struc->i)
			{
				write(1, "0", 1);
				struc->calc_width--;
			}
		}
		if (struc->precision == 0 && d == 0 && struc->flag_precision == 0)
			write(1, "0", 1);
		while (struc->calc_precision > 0 && ++struc->i)
		{
			write(1, "0", 1);
			struc->calc_precision--;
		}
		if (d)
			ft_putstr(str);
		if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
			struc->count += ft_strlen(str) + 2 + struc->i;
		else if (d == 0)
			struc->count += ft_strlen(str) + 1 + struc->i;
		else
			struc->count += ft_strlen(str) + 2 + struc->i;
	}
	ft_bzero(struc, sizeof(int) * 14 + sizeof(char) * 3);
}

void	ft_len_wchar(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		struc->len_wchar++;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			struc->len_wchar++;
		else if (size <= 11)
			struc->len_wchar += 2;
		else if (size <= 16)
			struc->len_wchar += 3;
		else
			struc->len_wchar += 4;
	}
}

void	ft_len_wchar1(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		struc->len_wchar++;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			struc->len_wchar1 = 1;
		else if (size <= 11)
			struc->len_wchar1 = 2;
		else if (size <= 16)
			struc->len_wchar1 = 3;
		else
			struc->len_wchar1 = 4;
	}
}

void	ft_wchar_s(va_list ap, t_struc *struc)
{
	int		i;
	int		j;
	wchar_t	*str;
	int		current_count;

	i = 0;
	j = 0;
	struc->current_count = 0;
	str = va_arg(ap, wchar_t*);
	struc->destruct = 0;
	struc->flag_wchar = 0;
	
	if (!str)
	{
		if (struc->width)
			struc->calc_width = struc->width - 6;
		else
			struc->calc_width = 0;
		if (struc->calc_width < 0)
			struc->calc_width = 0;
		if (struc->minus)
		{
			ft_putstr("(null)");
			while (struc->calc_width > 0 && ++struc->i)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += struc->i + 6;
		}
		else if (struc->minus == 0)
		{
			while (struc->calc_width > 0 && ++struc->i)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->calc_width--;
			}
			ft_putstr("(null)");
			struc->count += struc->i + 6;
		}
		return ;
	}

	while (str[j])
	{
		ft_len_wchar(str[j], struc);
		j++;
	}

	if (struc->precision || struc->flag_precision)
	{
		struc->calc_precision = struc->precision;
		if (struc->calc_precision > struc->len_wchar)
			struc->calc_precision = struc->len_wchar;
		else
			struc->len_wchar = struc->calc_precision;
	}
	else
		struc->calc_precision = struc->len_wchar;

	if (struc->width || struc->width == 0)
	{
		if ((struc->precision < struc->len_wchar) && struc->flag_precision)
			struc->calc_width = struc->width - struc->len_wchar;
		else
			struc->calc_width = struc->width - struc->len_wchar;
		if (struc->calc_width < 0)
			struc->calc_width = 0;
	}

	if (struc->width)
	{
		if (struc->minus)
		{
			while (str[i] && struc->calc_precision > 0 && struc->calc_precision >= struc->len_wchar1)
			{
				if (struc->precision == 1)
				{
					ft_len_wchar1(str[i], struc);
					if (struc->calc_precision == struc->len_wchar1)
					{
						ft_wchar_c(str[i], struc);
						struc->flag_wchar = 1;
					}
					else if (struc->flag_wchar == 0 && ++struc->count)
					{
						if (struc->noll)
							write(1, "0", 1);
						else
							write(1, " ", 1);
					}
				}
				else
				{
					struc->current_count = struc->count;
					ft_wchar_c(str[i], struc);
					struc->destruct = struc->count - struc->current_count;
					struc->calc_precision = struc->calc_precision - struc->destruct;
					ft_len_wchar1(str[i + 1], struc);
				}
				i++;
			}
			while (struc->calc_width && ++struc->count)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
		}
		else if (struc->minus == 0)
		{
			while (struc->calc_width && ++struc->count)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->calc_width--;
			}
			if (struc->precision == 0 && struc->flag_precision)
				write(1, "", 0);
			else if (struc->precision)
			{
				while (str[i] && struc->calc_precision > 0 && struc->calc_precision >= struc->len_wchar1)
				{
					if (struc->precision == 1)
					{
						ft_len_wchar1(str[i], struc);
						if (struc->calc_precision == struc->len_wchar1)
						{
							ft_wchar_c(str[i], struc);
							struc->flag_wchar = 1;
						}
						else if (struc->flag_wchar == 0 && ++struc->count)
						{
							if (struc->noll)
								write(1, "0", 1);
							else
								write(1, " ", 1);
						}
					}
					else
					{
						struc->current_count = struc->count;
						ft_wchar_c(str[i], struc);
						struc->destruct = struc->count - struc->current_count;
						struc->calc_precision = struc->calc_precision - struc->destruct;
						ft_len_wchar1(str[i + 1], struc);
					}
					i++;
				}
			}
			else
			{
				while (str[i] && struc->calc_precision)
				{
					ft_wchar_c(str[i], struc);
					struc->calc_precision = struc->calc_precision - struc->count;
					i++;
				}
			}

		}
	}
	else if (struc->flag_precision)
	{
		while (str[i] && struc->calc_precision > 0 && struc->calc_precision >= struc->len_wchar1)
		{
			if (struc->precision == 1)
			{
				ft_len_wchar1(str[i], struc);
				if (struc->calc_precision == struc->len_wchar1)
					ft_wchar_c(str[i], struc);
			}
			else
			{
				struc->current_count = struc->count;
				ft_wchar_c(str[i], struc);
				struc->destruct = struc->count - struc->current_count;
				struc->calc_precision = struc->calc_precision - struc->destruct;
				ft_len_wchar1(str[i + 1], struc);
			}
			i++;
		}
	}
	else
	{
		while (str[i] && i < struc->calc_precision)
		{
			ft_wchar_c(str[i], struc);
			i++;
		}
	}
	ft_bzero(struc, sizeof(int) * 14 + sizeof(char) * 3);
}
