/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:52:15 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/07/24 17:52:18 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_flags(char *p, int *i, t_struc *struc)
{
	struc->minus = 0;
	struc->plus = 0;
	struc->hash = 0;
	struc->noll = 0;
	struc->space = 0;
	while (p[*i] == '-' || p[*i] == '+' || p[*i] == '#'
			|| p[*i] == '0' || p[*i] == ' ')
	{
		if (p[*i] == '-')
			struc->minus = 1;
		else if (p[*i] == '+')
			struc->plus = 1;
		else if (p[*i] == '#')
			struc->hash = 1;
		else if (p[*i] == '0')
			struc->noll = 1;
		else if (p[*i] == ' ')
			struc->space = 1;
		(*i)++;
	}
}

void	ft_field_width(char *p, int *i, t_struc *struc)
{
	struc->width = 0;
	struc->width = ft_atoi(p + (*i));
	while (p[*i] >= '0' && p[*i] <= '9')
		(*i)++;
}

void	ft_precision(char *p, int *i, t_struc *struc)
{
	struc->flag_precision = 0;
	struc->precision = 0;
	if (p[*i] == '.')
	{
		(*i)++;
		struc->precision = ft_atoi(p + (*i));
		while (p[*i] >= '0' && p[*i] <= '9')
			(*i)++;
		struc->flag_precision = 1;
	}
}

void	ft_size_modifier(char *p, int *i, t_struc *struc)
{
	if ((p[*i] == 'h' && p[*i + 1] == 'h') ||
			(p[*i] == 'l' && p[*i + 1] == 'l'))
	{
		if (p[*i] == 'h')
			struc->modifier = 'H';
		else if (p[*i] == 'l')
			struc->modifier = 'L';
		while (p[*i] == 'h' || p[*i] == 'l')
			(*i)++;
	}
	else if (p[*i] == 'h' || p[*i] == 'l' || p[*i] == 'j' || p[*i] == 'z')
	{
		struc->modifier = p[*i];
		(*i)++;
	}
}
