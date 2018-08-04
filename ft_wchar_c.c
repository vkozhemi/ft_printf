/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:54:16 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/24 17:54:18 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_size_bin(wchar_t value)
{
	int i;

	i = 0;
	while (value)
	{
		value = value / 2;
		i++;
	}
	return (i);
}

void	ft_wchar_c11(unsigned int v, unsigned char octet, t_struc *struc)
{
	unsigned int	mask1;
	unsigned char	o2;
	unsigned char	o1;

	mask1 = 49280;
	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
	struc->count += 2;
}

void	ft_wchar_c16(unsigned int v, unsigned char octet, t_struc *struc)
{
	unsigned int	mask2;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;

	mask2 = 14712960;
	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
	struc->count += 3;
}

void	ft_wchar_c32(unsigned int v, unsigned char octet, t_struc *struc)
{
	unsigned int	mask3;
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;

	mask3 = 4034953344;
	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
	struc->count += 4;
}

void	ft_wchar_c(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	int				size;
	unsigned char	octet;
	int				i;

	if (MB_CUR_MAX == 1)
		ft_char(value, struc);
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7 && ++struc->count)
		{
			octet = value;
			write(1, &octet, 1);
		}
		else if (size <= 11)
			ft_wchar_c11(v, octet, struc);
		else if (size <= 16)
			ft_wchar_c16(v, octet, struc);
		else
			ft_wchar_c32(v, octet, struc);
	}
}

/*
void	ft_wchar_c(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	int				size;
	unsigned char	octet;
	int				i;

	if (MB_CUR_MAX == 1)
	{
		if (value >= 127)
			struc->count = -1;
		else
			ft_char(value, struc);
	}
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7 && ++struc->count)
		{
			octet = value;
			write(1, &octet, 1);
		}
		else if (size <= 11)
			ft_wchar_c11(v, octet, struc);
		else if (size <= 16)
			ft_wchar_c16(v, octet, struc);
		else
			ft_wchar_c32(v, octet, struc);
	}
}
*/
