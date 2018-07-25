/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:00:06 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/23 18:00:11 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_choose_base(uintmax_t d, t_struc *struc, char **str)
{
	if (struc->conversions == 'u')
		*str = ft_itoa_base_uns(d, 10, 0);
	else if (struc->conversions == 'U')
		*str = ft_itoa_base_uns(d, 10, 0);
	else if (struc->conversions == 'o')
		*str = ft_itoa_base_uns(d, 8, 0);
	else if (struc->conversions == 'O')
		*str = ft_itoa_base_uns(d, 8, 0);
	else if (struc->conversions == 'x')
		*str = ft_itoa_base_uns(d, 16, 1);
	else if (struc->conversions == 'X')
		*str = ft_itoa_base_uns(d, 16, 0);
	return (**str);
}

void	ft_find_precision_uns_int(t_struc *struc, char *str, int d, char *p, int *i)
{
	if (struc->precision)
	{
		if ((p[*i] == 'O' || p[*i] == 'o') && struc->hash && d)
			struc->calc_precision = struc->precision - ft_strlen(str) - 1;
		else
			struc->calc_precision = struc->precision - ft_strlen(str);
		if (struc->calc_precision < 0)
			struc->calc_precision = 0;
	}
	else
		struc->calc_precision = 0;
}

void	ft_width_uns_int(t_struc *struc, char *str, int d, char *p, int *i)
{
	if (struc->width)
	{
		if (struc->hash && (p[*i] == 'x' || p[*i] == 'X'))
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision - 2;
		else if (struc->hash && d == 0 && struc->precision &&
			(p[*i] == 'o' || p[*i] == 'O'))
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision;
		else if (struc->hash && d == 0 && (p[*i] == 'o' || p[*i] == 'O'))
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision;
		else if (struc->hash && (p[*i] == 'o' || p[*i] == 'O'))
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision - 1;
		else if (d == 0 && struc->precision == 0 && struc->flag_precision)
			struc->calc_width = struc->width;
		else if (struc->width && d == 0 && struc->precision == 0 &&
			struc->flag_precision)
			struc->calc_width = struc->width;
		else
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision;
	}
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
}

void	ft_count_uns_int(t_struc *struc, char *str, int d)
{
	if (d == 0 && struc->precision)
		struc->count += struc->i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
		struc->count += struc->i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0)
		struc->count += struc->i;
	else
		struc->count += struc->i + ft_strlen(str);
}

void	ft_uns_int(uintmax_t d, t_struc *struc, char *p, int *i)
{
	char *str;

	str = NULL;
	struc->calc_precision = 0;
	ft_choose_base(d, struc, &str);
	ft_find_precision_uns_int(struc, str, d, p, i);
	ft_width_uns_int(struc, str, d, p, i);
	if (struc->minus)
		ft_flag_minus_uns_int(struc, str, d, p, i);
	else
		ft_flag_no_minus_uns_int(struc, str, d, p, i);
	ft_count_uns_int(struc, str, d);
	ft_bzero(struc, sizeof(int) * 13 + sizeof(char) * 3);
}
