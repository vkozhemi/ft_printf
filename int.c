/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:43:40 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/21 17:43:43 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_plus_minus_int(intmax_t d, char **str)
{
	if (d < 0)
		*str = ft_itoa_base_plus(d, 10, 0);
	else
		*str = ft_itoa_base(d, 10, 0);
	return (**str);
}

void	ft_find_precision_int(t_struc *struc, char *str)
{
	if (struc->precision)
	{
		struc->calc_precision = struc->precision - ft_strlen(str);
		if (struc->calc_precision < 0)
			struc->calc_precision = 0;
	}
	else
		struc->calc_precision = 0;
}

void	ft_width_int(t_struc *struc, char *str, intmax_t d)
{
	if (struc->width)
	{
		if (struc->width && d == 0 && struc->precision == 0 &&
			struc->flag_precision)
			struc->calc_width = struc->width;
		else if ((struc->plus && d > 0) || (struc->plus && d < 0) ||
			d < 0 || (struc->plus && d == 0))
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision - 1;
		else if (d == 0 && struc->precision == 0 && struc->flag_precision)
			struc->calc_width = struc->width;
		else if (struc->space)
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision - 1;
		else
			struc->calc_width = struc->width - ft_strlen(str) -
			struc->calc_precision;
	}
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
}

void	ft_count_int(t_struc *struc, char *str, intmax_t d)
{
	if (d == 0 && struc->precision)
		struc->count += struc->i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
		struc->count += struc->i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0)
		struc->count += struc->i;
	else
		struc->count += ft_strlen(str) + struc->i;
}

void	ft_int(intmax_t d, t_struc *struc)
{
	char	*str;

	struc->flag_int = 1;
	str = NULL;
	struc->calc_precision = 0;
	ft_plus_minus_int(d, &str);
	ft_find_precision_int(struc, str);
	ft_width_int(struc, str, d);
	if (struc->minus)
		ft_flag_minus_int(struc, str, d);
	else
		ft_flag_no_minus_int(struc, str, d);
	ft_count_int(struc, str, d);
	ft_bzero(struc, sizeof(int) * 13 + sizeof(char) * 3);
}
