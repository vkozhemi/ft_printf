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
			// if (p[i + 1] != '%')
			// {
				i++;
				ft_flags(p, &i, struc);
				ft_field_width(p, &i, struc);
				ft_precision(p, &i, struc);
				ft_size_modifier(p, &i, struc);
				ft_conversions(p, &i, ap, struc);
			// }
		}
		// else if (p[i] == '%' && p[i + 1] == '%')
		// {
		// 	write(1, "%%", 2);
		// 	struc->count += 2;
		// }
		else if (++struc->count)
			write(1, &p[i], 1);
		i++;
		ft_bzero(struc, sizeof(int) * 13 + sizeof(char) * 3);
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
