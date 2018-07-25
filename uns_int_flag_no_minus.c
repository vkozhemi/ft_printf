/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_int_flag_no_minus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:31:55 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/21 17:31:57 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_no_minus_uns_int_0(t_struc *struc)
{
	if (struc->noll && struc->precision)
	{
		while (struc->calc_width > 0 && ++struc->i)
		{
			write(1, " ", 1);
			struc->calc_width--;
		}
	}
}

void	ft_flag_no_minus_uns_int_1(t_struc *struc, int d, char *p, int *i)
{
	while (struc->calc_width > 0 && struc->noll == 0 && ++struc->i)
	{
		write(1, " ", 1);
		struc->calc_width--;
	}
	if (struc->hash && p[*i] == 'x' && d && struc->flag_uns_int)
	{
		write(1, "0x", 2);
		struc->i += 2;
		struc->flag_uns_int--;
	}
	if (struc->hash && p[*i] == 'X' && d && struc->flag_uns_int)
	{
		write(1, "0X", 2);
		struc->i += 2;
		struc->flag_uns_int--;
	}
}

void	ft_flag_no_minus_uns_int_2(t_struc *struc, int d)
{
	if (struc->noll && d)
	{
		while (struc->calc_width > 0 && ++struc->i)
		{
			write(1, "0", 1);
			struc->calc_width--;
		}
	}
}

void	ft_flag_no_minus_uns_int(t_struc *struc,
		char *str, int d, char *p, int *i)
{
	struc->flag_uns_int = 1;
	ft_flag_no_minus_uns_int_0(struc);
	ft_flag_no_minus_uns_int_1(struc, d, p, i);
	ft_flag_no_minus_uns_int_2(struc, d);
	if (struc->hash && d > 0 && (p[*i] == 'o' || p[*i] == 'O') && ++struc->i)
		write(1, "0", 1);
	else if (struc->hash && d == 0 && struc->precision == 0 &&
			(p[*i] == 'o' || p[*i] == 'O') && ++struc->i)
		write(1, "0", 1);
	while (struc->calc_precision > 0 && ++struc->i)
	{
		write(1, "0", 1);
		struc->calc_precision--;
	}
	if (struc->precision == 0 && d == 0 && struc->flag_precision)
		write(1, "", 0);
	else
		ft_putstr(str);
}
