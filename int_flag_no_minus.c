/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flag_no_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:31:55 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/21 17:31:57 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_no_minus_int_0(t_struc *struc, int d)
{
	if (struc->calc_width == 0 && struc->plus && d >= 0 && ++struc->i)
		write(1, "+", 1);
	else if (d < 0 && ++struc->i)
		write(1, "-", 1);
}

void	ft_flag_no_minus_int_1(t_struc *struc, int d)
{
	while (struc->calc_width > 0 && ++struc->i)
	{
		ft_putchar(' ');
		struc->calc_width--;
	}
	if (struc->plus && d >= 0 && ++struc->i)
		write(1, "+", 1);
	else if (d < 0 && ++struc->i)
		write(1, "-", 1);
}

void	ft_flag_no_minus_int_2(t_struc *struc, int d)
{
	while (struc->calc_width && d < 0 && ++struc->i)
	{
		write(1, " ", 1);
		struc->calc_width--;
	}
	if (struc->plus && d >= 0 && ++struc->i)
		write(1, "+", 1);
	else if (d < 0 && ++struc->i)
		write(1, "-", 1);
	else if (++struc->i)
		ft_putchar(' ');
}

void	ft_flag_no_minus_int_3(t_struc *struc, int d)
{
	if (d < 0 && struc->flag_int && ++struc->i)
	{
		write(1, "-", 1);
		struc->flag_int--;
	}
	else if (struc->plus && d >= 0 && struc->flag_int && ++struc->i)
	{
		write(1, "+", 1);
		struc->flag_int--;
	}
	write(1, "0", 1);
	struc->i++;
}

void	ft_flag_no_minus_int(t_struc *struc, char *str, int d)
{
	if (struc->space && struc->noll && struc->calc_width && d > 0 && ++struc->i)
		write(1, " ", 1);
	if (struc->calc_width == 0)
		ft_flag_no_minus_int_0(struc, d);
	while (struc->calc_width > 0)
	{
		if ((d < 0 && struc->noll == 0) || (struc->plus && struc->noll == 0))
			ft_flag_no_minus_int_1(struc, d);
		else if (struc->noll && struc->precision)
			ft_flag_no_minus_int_2(struc, d);
		else if (struc->noll)
			ft_flag_no_minus_int_3(struc, d);
		else if (++struc->i)
			write(1, " ", 1);
		struc->calc_width--;
	}
	while (struc->calc_precision > 0 && ++struc->i)
	{
		ft_putchar('0');
		struc->calc_precision--;
	}
	if (struc->precision == 0 && d == 0 && struc->flag_precision)
		write(1, "", 0);
	else
		ft_putstr(str);
}
