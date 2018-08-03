/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 18:28:22 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/08/03 18:28:25 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_char_struc_minus(char c, t_struc *struc)
{
	write(1, &c, 1);
	struc->count++;
	struc->width -= 1;
	while (struc->width && ++struc->count)
	{
		write(1, " ", 1);
		struc->width--;
	}
	struc->count += struc->i;
}

void	ft_char_struc_no_minus(char c, t_struc *struc)
{
	struc->width -= 1;
	while (struc->width && ++struc->count)
	{
		if (struc->noll)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		struc->width--;
	}
	write(1, &c, 1);
	struc->count++;
}

void	ft_char(char c, t_struc *struc)
{
	if (!c)
		c = '\0';
	if (struc->width)
	{
		if (struc->minus)
		{
			ft_char_struc_minus(c, struc);
		}
		else if (struc->minus == 0)
			ft_char_struc_no_minus(c, struc);
	}
	else
	{
		write(1, &c, 1);
		struc->count++;
	}
	ft_bzero(struc, sizeof(int) * 22 + sizeof(char) * 3);
}
