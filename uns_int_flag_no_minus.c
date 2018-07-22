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

void	ft_flag_no_minus_uns_int(t_struc *struc, char *str, int d, char *p, int *i)
{
	// printf("struc->precision = %d\n", struc->precision);
	// printf("struc->width = %d\n", struc->width);
	struc->flag_uns_int = 1;
	if (struc->noll && struc->precision && ++struc->i)
	{
		while (struc->calc_width > 0)
		{
			write(1, " ", 1);
			struc->calc_width--;
		}
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
	if (struc->noll && ++struc->i && d)
	{
		while (struc->calc_width > 0)
		{
			write(1, "0", 1);
			struc->calc_width--;
		}
	}
	if (++struc->i)
	{
		while (struc->calc_width > 0)
		{
			write(1, " ", 1);
			struc->calc_width--;
		}
	}
	if (struc->hash && d && (p[*i] == 'o' || p[*i] == 'O') && ++struc->i)
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
