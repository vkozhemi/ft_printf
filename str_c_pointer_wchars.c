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

void	ft_len_wchar(wchar_t value, t_s *s)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		s->len_wchar++;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			s->len_wchar++;
		else if (size <= 11)
			s->len_wchar += 2;
		else if (size <= 16)
			s->len_wchar += 3;
		else
			s->len_wchar += 4;
	}
}

void	ft_len_wchar1(wchar_t value, t_s *s)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		s->len_wchar1 = 1;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			s->len_wchar1 = 1;
		else if (size <= 11)
			s->len_wchar1 = 2;
		else if (size <= 16)
			s->len_wchar1 = 3;
		else
			s->len_wchar1 = 4;
	}
}











void	ft_wchar_s_str_p_w(t_s *s, char *n)
{
	if (s->flag_precision)
		s->calc_precision = s->precision;
	if (s->calc_precision > 6)
		s->calc_precision = 6;
	if (s->precision == 0)
		s->calc_precision = ft_strlen(n);
	if (s->width)
		s->calc_width = s->width - s->calc_precision;
	else
		s->calc_width = 0;
	if (s->calc_width < 0)
		s->calc_width = 0;
}

void	ft_wchar_s_str(t_s *s, int j)
{
	char 	*n;

	n = "(null)";
	ft_wchar_s_str_p_w(s, n);
	if (s->minus)
	{
		while (j < s->calc_precision)
			write(1, &n[j++], 1);
		while (s->calc_width-- > 0 && ++s->count)
			write(1, " ", 1);
		s->count += s->calc_precision;
	}
	else if (s->minus == 0)
	{
		while (s->calc_width-- > 0 && ++s->count)
		{
			if (s->noll)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		while (j < s->calc_precision)
			write(1, &n[j++], 1);
		s->count += s->calc_precision;
	}
}

void	ft_wchar_s_precision(t_s *s, char *str)
{
	int j;

	j = 0;
	s->calc_precision = s->precision;
	while (str[j] && (s->calc_precision > 0))
	{
		ft_len_wchar1(str[j++], s);
		s->calc_precision -= s->len_wchar1;
		if (s->calc_precision >= 0)
			s->wchar_s_res += s->len_wchar1;
	}
	if (s->precision > s->len_wchar)
		s->precision = s->len_wchar;
	else
		s->precision = s->wchar_s_res;
}

void	ft_wchar_s_width(t_s *s, wchar_t *str)
{
	if (!*str)
		s->calc_width = s->width;
	else
		s->calc_width = s->width - s->wchar_s_res;
	if (s->calc_width < 0)
		s->calc_width = 0;
}

void	ft_wchar_s_width_print(t_s *s, wchar_t *str)
{
	int i;

	i = 0;
	if (s->minus)
	{
		while (str[i] && s->wchar_s_res > 0)
		{
			ft_wchar_c(str[i++], s);
			s->wchar_s_res -= s->len_wchar1;
		}
		while (s->calc_width-- && ++s->count)
			write(1, " ", 1);
	}
	else if (s->minus == 0)
	{
		while (s->calc_width-- && ++s->count)
		{
			if (s->noll)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		if (s->precision == 0 && s->flag_precision)
			write(1, "", 0);
		else
		{
			while (str[i] && s->wchar_s_res > 0)
			{
				ft_wchar_c(str[i++], s);
				s->wchar_s_res -= s->len_wchar1;
			}
		}
	}
}

void	ft_wchar_s_print(t_s *s, char *str)
{
	int i;

	i = 0;
	while (str[i] && s->wchar_s_res > 0)
	{
		ft_wchar_c(str[i++], s);
		s->wchar_s_res -= s->len_wchar1;
	}
}

void	ft_wchar_s(va_list ap, t_s *s)
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
		ft_wchar_s_str(s, j);
		return ;
	}
	while (str[j])
		ft_len_wchar(str[j++], s);
	s->wchar_s_res = 0;
	if (s->precision || s->flag_precision)
	{
		//ft_wchar_s_precision(s, str);
		j = 0;
		s->calc_precision = s->precision;
		while (str[j] && (s->calc_precision > 0))
		{
			ft_len_wchar1(str[j], s);
			s->calc_precision -= s->len_wchar1;
			if (s->calc_precision >= 0)
				s->wchar_s_res += s->len_wchar1;
			j++;
		}
		if (s->precision > s->len_wchar)
			s->precision = s->len_wchar;
		else
			s->precision = s->wchar_s_res;
	}
	else
		s->wchar_s_res = s->len_wchar;
	if (s->width || s->width == 0)
		ft_wchar_s_width(s, str);
	if (s->width)
	{
		//ft_wchar_s_width_print(s, str);

		if (s->minus)
		{
			//ft_wchar_s_print(s, str);
			while (str[i] && s->wchar_s_res > 0)
			{
				ft_wchar_c(str[i++], s);
				s->wchar_s_res -= s->len_wchar1;
			}
			while (s->calc_width-- && ++s->count)
				write(1, " ", 1);
		}
		else if (s->minus == 0)
		{
			while (s->calc_width-- && ++s->count)
			{
				if (s->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
			}
			if (s->precision == 0 && s->flag_precision)
				write(1, "", 0);
			else
			{
				//ft_wchar_s_print(s, str);
				while (str[i] && s->wchar_s_res > 0)
				{
					ft_wchar_c(str[i++], s);
					s->wchar_s_res -= s->len_wchar1;
				}
			}
		}
	}
	else
	{
		int res = s->wchar_s_res;
		while (str[i] && res > 0)
		{
			ft_wchar_c(str[i], s);
			ft_len_wchar1(str[i++], s);
			res -= s->len_wchar1;
		}
	}
	ft_bzero(s, sizeof(int) * 22 + sizeof(char) * 3);
}
