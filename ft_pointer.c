/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:22:27 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/03 19:22:30 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_pointer_precision(t_struc *struc, unsigned long int d)
{
	if (d == 0)
		struc->calc_precision = struc->precision;
	else
		struc->calc_precision = struc->precision - struc->len_p;
	if (struc->calc_precision < 0)
		struc->calc_precision = 0;
}

void	ft_pointer_width(t_struc *struc, unsigned long int d)
{
	if (struc->width && struc->precision == 0 && d == 0 &&
		struc->flag_precision)
		struc->calc_width = struc->width - struc->calc_precision - 1
		- struc->len_p;
	else if (struc->width && struc->precision && struc->flag_precision &&
		d == 0)
		struc->calc_width = struc->width - struc->calc_precision - 1
		- struc->len_p;
	else
		struc->calc_width = struc->width - struc->calc_precision - 2
		- struc->len_p;
}

void	ft_pointer_minus(t_struc *struc, char *str, unsigned long int d)
{
	ft_putstr("0x");
	while (struc->calc_precision > 0 && ++struc->count)
	{
		write(1, "0", 1);
		struc->calc_precision--;
	}
	if (struc->flag_precision == 0 && d == 0)
		write(1, "0", 1);
	if (d)
		ft_putstr(str);
	while (struc->calc_width > 0 && ++struc->count)
	{
		write(1, " ", 1);
		struc->calc_width--;
	}
	if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
		struc->count += 2 + struc->len_p;
	else if (d == 0)
		struc->count += 1 + struc->len_p;
	else
		struc->count += 2 + struc->len_p;
}

void	ft_pointer_no_minus(t_struc *struc, char *str, unsigned long int d)
{
	if (struc->noll == 0)
		while (struc->calc_width-- > 0 && ++struc->count)
			write(1, " ", 1);
	ft_putstr("0x");
	if (struc->noll)
		while (struc->calc_width-- > 0 && ++struc->count)
			write(1, "0", 1);
	if (struc->precision == 0 && d == 0 && struc->flag_precision == 0)
		write(1, "0", 1);
	while (struc->calc_precision-- > 0 && ++struc->count)
		write(1, "0", 1);
	if (d)
		ft_putstr(str);
	if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
		struc->count += 2 + struc->len_p;
	else if (d == 0)
		struc->count += 1 + struc->len_p;
	else
		struc->count += 2 + struc->len_p;
}

void	ft_pointer(va_list ap, t_struc *struc)
{
	int					i;
	char				*str;
	unsigned long int	d;

	i = 0;
	d = va_arg(ap, unsigned long int);
	str = ft_itoa_base(d, 16, 1);
	struc->len_p = ft_strlen(str);
	if (struc->precision)
		ft_pointer_precision(struc, d);
	else
		struc->calc_precision = 0;
	if (struc->width)
		ft_pointer_width(struc, d);
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
	if (struc->minus)
		ft_pointer_minus(struc, str, d);
	else if (struc->minus == 0)
		ft_pointer_no_minus(struc, str, d);
	ft_bzero(struc, sizeof(int) * 22 + sizeof(char) * 3);
	//free(str);
}
