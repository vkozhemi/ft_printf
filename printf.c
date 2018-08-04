/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:39:15 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/24 16:39:18 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_conversions_str(char *p, int *i, t_struc *struc)
{
	if (p[*i] == 'c')
		struc->conversions = p[*i];
	else if (p[*i] == 's')
		struc->conversions = p[*i];
	else if (p[*i] == 'C')
		struc->conversions = p[*i];
	else if (p[*i] == 'S')
		struc->conversions = p[*i];
	else if (p[*i] == '%')
		struc->conversions = p[*i];
}

void	ft_get_conversions(char *p, int *i, t_struc *struc)
{
	if (p[*i] == 'd' || p[*i] == 'i')
		struc->conversions = p[*i];
	else if (p[*i] == 'D')
		struc->conversions = p[*i];
	else if (p[*i] == 'u')
		struc->conversions = p[*i];
	else if (p[*i] == 'U')
		struc->conversions = p[*i];
	else if (p[*i] == 'O')
		struc->conversions = p[*i];
	else if (p[*i] == 'o')
		struc->conversions = p[*i];
	else if (p[*i] == 'x')
		struc->conversions = p[*i];
	else if (p[*i] == 'X')
		struc->conversions = p[*i];
	else if (p[*i] == 'p')
		struc->conversions = p[*i];
}

void	ft_check_conversions(char *p, int *i, t_struc *struc)
{
	if (p[*i] == 's' || p[*i] == 'S' || p[*i] == 'p' || p[*i] == 'd' ||
		p[*i] == 'D' || p[*i] == 'i' || p[*i] == 'o' || p[*i] == 'O' ||
		p[*i] == 'u' || p[*i] == 'U' || p[*i] == 'x' || p[*i] == 'X' ||
		p[*i] == 'c' || p[*i] == 'C' || p[*i] == '%')
		(*i)++;
	else
	{
		ft_char(p[*i], struc);
		(*i)++;
	}
}

void	ft_call_pars(char *fmt, va_list ap, t_struc *struc)
{
	int		i;
	char	*p;

	i = 0;
	p = fmt;
	while (p[i])
	{
		if (p[i] == '%')
		{
			i++;
			ft_flags(p, &i, struc);
			ft_field_width(p, &i, struc);
			ft_precision(p, &i, struc);
			ft_size_modifier(p, &i, struc);
			ft_conversions(p, &i, ap, struc);
			ft_check_conversions(p, &i, struc);
		}
		else
		{
			write(1, &p[i], 1);
			// ft_str_else(p, &i, struc);
			struc->count++;
			i++;
		}
		// i++;
	}
}

int		ft_printf(char *fmt, ...)
{
	size_t	result;
	t_struc	*struc;
	va_list	ap;

	result = 0;
	struc = (t_struc*)malloc(sizeof(t_struc));
	struc->count = 0;
	va_start(ap, fmt);
	ft_call_pars(fmt, ap, struc);
	va_end(ap);
	return (struc->count);
}
