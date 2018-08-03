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
		struc->len_wchar1 = 1;
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











void	ft_wchar_s_str_p_w(t_struc *struc, char *s)
{
	if (struc->flag_precision)
		struc->calc_precision = struc->precision;
	if (struc->calc_precision > 6)
		struc->calc_precision = 6;
	if (struc->precision == 0)
		struc->calc_precision = ft_strlen(s);
	if (struc->width)
		struc->calc_width = struc->width - struc->calc_precision;
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
}

void	ft_wchar_s_str(t_struc *struc, int j)
{
	char 	*s;

	s = "(null)";
	ft_wchar_s_str_p_w(struc, s);
	if (struc->minus)
	{
		while (s[j] && j < struc->calc_precision)
			write(1, &s[j++], 1);
		while (struc->calc_width-- > 0 && ++struc->count)
			write(1, " ", 1);
		struc->count += struc->calc_precision;
	}
	else if (struc->minus == 0)
	{
		while (struc->calc_width-- > 0 && ++struc->count)
		{
			if (struc->noll)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		while (s[j] && j < struc->calc_precision)
			write(1, &s[j++], 1);
		struc->count += struc->calc_precision;
	}
}

void	ft_wchar_s_precision(t_struc *struc, char *str)
{
	int j;

	j = 0;
	struc->calc_precision = struc->precision;
	while (str[j] && (struc->calc_precision > 0))
	{
		ft_len_wchar1(str[j++], struc);
		struc->calc_precision -= struc->len_wchar1;
		if (struc->calc_precision >= 0)
			struc->wchar_s_res += struc->len_wchar1;
	}
	if (struc->precision > struc->len_wchar)
		struc->precision = struc->len_wchar;
	else
		struc->precision = struc->wchar_s_res;
}

void	ft_wchar_s_width(t_struc *struc, char *str)
{
	if (!*str)
		struc->calc_width = struc->width;
	else
		struc->calc_width = struc->width - struc->wchar_s_res;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
}

void	ft_wchar_s_width_print(t_struc *struc, char *str)
{
	int i;

	i = 0;
	if (struc->minus)
	{
		while (str[i] && struc->wchar_s_res > 0)
		{
			ft_wchar_c(str[i++], struc);
			struc->wchar_s_res -= struc->len_wchar1;
		}
		while (struc->calc_width-- && ++struc->count)
			write(1, " ", 1);
	}
	else if (struc->minus == 0)
	{
		while (struc->calc_width-- && ++struc->count)
		{
			if (struc->noll)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		if (struc->precision == 0 && struc->flag_precision)
			write(1, "", 0);
		else
		{
			while (str[i] && struc->wchar_s_res > 0)
			{
				ft_wchar_c(str[i++], struc);
				struc->wchar_s_res -= struc->len_wchar1;
			}
		}
	}
}

void	ft_wchar_s_print(t_struc *struc, char *str)
{
	int i;

	i = 0;
	while (str[i] && struc->wchar_s_res > 0)
	{
		ft_wchar_c(str[i++], struc);
		struc->wchar_s_res -= struc->len_wchar1;
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
	str = va_arg(ap, wchar_t*);
	if (!str)
	{
		ft_wchar_s_str(struc, j);
		return ;
	}
	while (str[j])
		ft_len_wchar(str[j++], struc);
	struc->wchar_s_res = 0;
	if (struc->precision || struc->flag_precision)
	{
		//ft_wchar_s_precision(struc, str);
		j = 0;
		struc->calc_precision = struc->precision;
		while (str[j] && (struc->calc_precision > 0))
		{
			ft_len_wchar1(str[j++], struc);
			struc->calc_precision -= struc->len_wchar1;
			if (struc->calc_precision >= 0)
				struc->wchar_s_res += struc->len_wchar1;
		}
		if (struc->precision > struc->len_wchar)
			struc->precision = struc->len_wchar;
		else
			struc->precision = struc->wchar_s_res;
	}
	else
		struc->wchar_s_res = struc->len_wchar;
	if (struc->width || struc->width == 0)
		ft_wchar_s_width(struc, str);
	if (struc->width)
	{
		//ft_wchar_s_width_print(struc, str);

		if (struc->minus)
		{
			//ft_wchar_s_print(struc, str);
			while (str[i] && struc->wchar_s_res > 0)
			{
				ft_wchar_c(str[i++], struc);
				struc->wchar_s_res -= struc->len_wchar1;
			}
			while (struc->calc_width-- && ++struc->count)
				write(1, " ", 1);
		}
		else if (struc->minus == 0)
		{
			while (struc->calc_width-- && ++struc->count)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
			}
			if (struc->precision == 0 && struc->flag_precision)
				write(1, "", 0);
			else
			{
				//ft_wchar_s_print(struc, str);
				while (str[i] && struc->wchar_s_res > 0)
				{
					ft_wchar_c(str[i++], struc);
					struc->wchar_s_res -= struc->len_wchar1;
				}
			}
		}
	}
	else
	{
		//ft_wchar_s_print(struc, str);
		while (str[i] && struc->wchar_s_res > 0)
		{
			ft_wchar_c(str[i++], struc);
			struc->wchar_s_res -= struc->len_wchar1;
		}
	}
	ft_bzero(struc, sizeof(int) * 22 + sizeof(char) * 3);
}
