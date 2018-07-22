/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_int_flag_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:36:34 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/21 17:36:36 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flag_minus_uns_int(t_struc *struc, char *str, int d, char *p, int *i)
{
	//printf("struc->width = %d", struc->width);
	if (struc->hash	&& d && (p[*i] == 'o' || p[*i] == 'O') && ++struc->i) //////////////////////
		write(1, "0", 1);
	if (struc->hash && p[*i] == 'x' && d)
	{
		write(1, "0x", 2);
		struc->i += 2;
	}
	else if (struc->hash && p[*i] == 'X' && d)
	{
		write(1, "0X", 2);
		struc->i += 2;
	}
	while (struc->calc_precision > 0 && ++struc->i)
	{
		write(1, "0", 1);
		struc->calc_precision--;
	}
	if (struc->precision == 0 && d == 0 && struc->flag_precision)
		write(1, "", 0);
	else
		ft_putstr(str);
	while (struc->calc_width > 0 && ++struc->i)
	{
		if (struc->noll)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		struc->calc_width--;
	}
}
