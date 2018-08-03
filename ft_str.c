/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 18:30:41 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/03 18:30:43 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_str_precision(t_struc *struc, int *j)
{
	if (struc->precision > *j)
		struc->precision = *j;
	else
		*j = struc->precision;
}

void	ft_str_minus(t_struc *struc, int j, char *str, int i)
{
	struc->calc_width = struc->width - j;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
	while (str[i] && i < struc->precision && ++struc->count)
	{
		write(1, &str[i], 1);
		i++;
	}
	while (struc->calc_width && ++struc->count)
	{
		write(1, " ", 1);
		struc->calc_width--;
	}
}

void	ft_str_no_minus(t_struc *struc, int j, char *str, int i)
{
	if (struc->width)
	{
		struc->calc_width = struc->width - j;
		if (struc->calc_width < 0)
			struc->calc_width = 0;
		while (struc->calc_width && ++struc->count)
		{
			if (struc->noll)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			struc->calc_width--;
		}
	}
	if (struc->precision == 0 && struc->flag_precision)
		write(1, "", 0);
	else if (struc->precision)
		while (str[i] && i < struc->precision && ++struc->count)
			write(1, &str[i++], 1);
	else
	{
		ft_putstr(str);
		struc->count += ft_strlen(str);
	}
}

void	ft_str(va_list ap, t_struc *struc)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		free(str);
	}
	j = ft_strlen(str);
	if (struc->precision || struc->flag_precision)
		ft_str_precision(struc, &j);
	else
		struc->precision = j;
	if (struc->minus)
		ft_str_minus(struc, j, str, i);
	else if (struc->minus == 0)
		ft_str_no_minus(struc, j, str, i);
	ft_bzero(struc, sizeof(int) * 22 + sizeof(char) * 3);
}
