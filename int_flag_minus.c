/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flag_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:36:34 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/21 17:36:36 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_minus_int_0(t_struc *struc, int d)
{
	if (d < 0 && ++struc->i)
		write(1, "-", 1);
	else if (struc->plus && d >= 0 && struc->flag_int && ++struc->i)
		write(1, "+", 1);
	if (struc->space && ++struc->i)
		write(1, " ", 1);
	while (struc->calc_precision > 0 && ++struc->i)
	{
		ft_putchar('0');
		struc->calc_precision--;
	}
}

void	ft_flag_minus_int(t_struc *struc, char *str, int d)
{
	if (struc->space && d > 0 && ++struc->i)
		write(1, " ", 1);
	if (struc->plus && d >= 0 && struc->flag_int && ++struc->i)
	{
		write(1, "+", 1);
		struc->flag_int--;
	}
	if (struc->calc_precision > 0)
		ft_flag_minus_int_0(struc, d);
	if (d < 0 && struc->precision == 0 && ++struc->i)
		write(1, "-", 1);
	if (struc->precision == 0 && d == 0 && struc->flag_precision)
		write(1, "", 0);
	else
		ft_putstr(str);
	while (struc->calc_width > 0 && ++struc->i)
	{
		if (struc->noll)
			ft_putchar('0');
		else
			ft_putchar(' ');
		struc->calc_width--;
	}
}
