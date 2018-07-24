/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_c_pointer_wchars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:58:17 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/24 14:58:21 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_str(va_list ap, t_struc *struc)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(ap, char *);
	ft_putstr(str);
	struc->count += ft_strlen(str) + i;
}

void	ft_char(va_list ap, t_struc *struc)
{
	char	c;
	int		i;

	i = 0;
	i++;
	c = va_arg(ap, int);
	ft_putchar(c);
	struc->count += i;
}

void	ft_pointer(va_list ap, t_struc *struc)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_base(va_arg(ap, unsigned long int), 16, 1);
	while (str[i] != '%')
		i++;
	ft_putstr("0x");
	ft_putstr(str);
	struc->count += ft_strlen(str) + 2;
}

void	ft_wchar_s(va_list ap, t_struc *struc)
{
	int		i;
	wchar_t	*str;

	i = 0;
	str = va_arg(ap, wchar_t*);
	while (str[i])
	{
		ft_wchar_c(str[i], struc);
		i++;
	}
}
