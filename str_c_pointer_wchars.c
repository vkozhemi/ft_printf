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
	int		counter;
	char	*str;
	int		j;

	i = 0;
	counter = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	j = ft_strlen(str);
	if (struc->precision || struc->flag_precision)
	{
		if (struc->precision > j)
			struc->precision = j;
		else
			j = struc->precision;
	}
	else
		struc->precision = j;
	if (struc->minus)
	{
		if (struc->width || struc->width == 0)
		{
			struc->calc_width = struc->width - j;
			if (struc->calc_width < 0)
				struc->calc_width = 0;
			while (str[i] && i < struc->precision)
			{
				write(1, &str[i], 1);
				i++;
			}
			while (struc->calc_width && ++struc->i)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += i + struc->i;
		}
	}
	else if (struc->minus == 0)
	{
		if (struc->width)
		{
			struc->calc_width = struc->width - j;
			if (struc->calc_width < 0)
				struc->calc_width = 0;
			while (struc->calc_width && ++struc->i)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += struc->i;
		}
		if (struc->precision == 0 && struc->flag_precision)
			write(1, "", 0);
		else if (struc->precision)
		{
			while (str[i] && i < struc->precision)
			{
				write(1, &str[i], 1);
				i++;
			}
			struc->count += i;
		}
		else
		{
			ft_putstr(str);
			struc->count += ft_strlen(str);
		}
	}
	ft_bzero(struc, sizeof(int) * 20 + sizeof(char) * 3);
}

void	ft_char(char c, t_struc *struc)
{
	// int		i;

	// i = 0;
	// i++;
	if (!c)
		c = '\0';
	if (struc->width)
	{
		if (struc->minus)
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
		else if (struc->minus == 0)
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
	}
	else
	{
		write(1, &c, 1);
		struc->count++;
	}
	ft_bzero(struc, sizeof(int) * 20 + sizeof(char) * 3);
}

void	ft_pointer(va_list ap, t_struc *struc)
{
	int					i;
	char				*str;
	unsigned long int	d;

	
	i = 0;
	d = va_arg(ap, unsigned long int);
	str = ft_itoa_base(d, 16, 1);
	struc->len_p = ft_strlen(str);
	//ft_putstr(str);
	if (struc->precision)
	{
		if (d == 0)
			struc->calc_precision = struc->precision;
		else
			struc->calc_precision = struc->precision - struc->len_p;
		if (struc->calc_precision < 0)
			struc->calc_precision = 0;
	}
	else 
		struc->calc_precision = 0;
	if (struc->width)
	{
		if (struc->width && struc->precision == 0 && d == 0 && struc->flag_precision)
			struc->calc_width = struc->width - struc->calc_precision - 1 - struc->len_p;
		else if (struc->width && struc->precision && struc->flag_precision && d == 0)
			struc->calc_width = struc->width -	struc->calc_precision - 1 - struc->len_p;
		else
			struc->calc_width = struc->width -	struc->calc_precision - 2 - struc->len_p;
	}
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;

	/* while (str[i] != '%') //WTF ?????????????????????????????????/
		// i++;*/
	if (struc->minus)
	{
		ft_putstr("0x");
		while (struc->calc_precision > 0 && ++struc->count)
		{
			write(1, "0", 1);
			struc->calc_precision--;
		}
		if (struc->flag_precision == 0 && d == 0)
			write(1, "0", 1);
		if (d)
			ft_putstr(str);
		while (struc->calc_width > 0 && ++struc->count)
		{
			write(1, " ", 1);
			struc->calc_width--;
		}
		if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
			struc->count += 2 + struc->len_p;
		else if (d == 0)
			struc->count += 1 + struc->len_p;
		else
			struc->count += 2 + struc->len_p;
	}
	else if (struc->minus == 0)
	{

		if (struc->noll == 0)
		{
			while (struc->calc_width > 0 && ++struc->count)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
		}
		ft_putstr("0x");
		if (struc->noll)
		{
			while (struc->calc_width > 0 && ++struc->count)
			{
				write(1, "0", 1);
				struc->calc_width--;
			}
		}
		if (struc->precision == 0 && d == 0 && struc->flag_precision == 0)
			write(1, "0", 1);
		while (struc->calc_precision > 0 && ++struc->count)
		{
			write(1, "0", 1);
			struc->calc_precision--;
		}
		if (d)
			ft_putstr(str);
		if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
			struc->count += 2 + struc->len_p;
		else if (d == 0)
			struc->count += 1 + struc->len_p;
		else
			struc->count += 2 + struc->len_p;
	}

	ft_bzero(struc, sizeof(int) * 20 + sizeof(char) * 3);
}

void	ft_len_wchar(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		struc->len_wchar++;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			struc->len_wchar++;
		else if (size <= 11)
			struc->len_wchar += 2;
		else if (size <= 16)
			struc->len_wchar += 3;
		else
			struc->len_wchar += 4;
	}
}

void	ft_len_wchar2(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		struc->len_wchar2++;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			struc->len_wchar2++;
		else if (size <= 11)
			struc->len_wchar2 += 2;
		else if (size <= 16)
			struc->len_wchar2 += 3;
		else
			struc->len_wchar2 += 4;
	}
}

void	ft_len_wchar3(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		struc->len_wchar3++;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			struc->len_wchar3++;
		else if (size <= 11)
			struc->len_wchar3 += 2;
		else if (size <= 16)
			struc->len_wchar3 += 3;
		else
			struc->len_wchar3 += 4;
	}
}

void	ft_len_wchar1(wchar_t value, t_struc *struc)
{
	unsigned int	v;
	unsigned char	octet;
	int				size;
	int				i;

	if (MB_CUR_MAX == 1)
		struc->len_wchar1++;
	else
	{
		v = value;
		size = ft_size_bin(value);
		i = 0;
		octet = 0;
		if (size <= 7)
			struc->len_wchar1 = 1;
		else if (size <= 11)
			struc->len_wchar1 = 2;
		else if (size <= 16)
			struc->len_wchar1 = 3;
		else
			struc->len_wchar1 = 4;
	}
}

void		count_precision_for_unicode(wchar_t *str, t_struc *struc)
{
	int j = 0;

	struc->len_wchar2 = 0;
	while (struc->len_wchar2 < struc->precision)
	{
		ft_len_wchar2(str[j], struc);
		//printf("struc->len_wchar2 = %d\n", struc->len_wchar2);
		if (struc->len_wchar2 < struc->precision)
			ft_len_wchar3(str[j], struc);
		//printf("struc->len_wchar3 = %d\n", struc->len_wchar3);
		j++;
	}
}

void	ft_wchar_s(va_list ap, t_struc *struc)
{
	int		i;
	int		j;
	wchar_t	*str;
	int		current_count;
	char 	*s;

	i = 0;
	j = 0;
	s = "(null)";
	struc->current_count = 0;
	str = va_arg(ap, wchar_t*);
	struc->destruct = 0;
	struc->flag_wchar = 0;
	
	if (!str)
	{
		if (struc->flag_precision)
			struc->calc_precision = struc->precision;
		if (struc->calc_precision > 6)
			struc->calc_precision = 6;

		if (struc->width)
			struc->calc_width = struc->width - struc->calc_precision;
		else
			struc->calc_width = 0;
		if (struc->calc_width < 0)
			struc->calc_width = 0;
		if (struc->minus)
		{
			while (s[j] && j < struc->calc_precision)
			{
				write(1, &s[j], 1);
				j++;
			}
			while (struc->calc_width > 0 && ++struc->count)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
			struc->count += struc->calc_precision;
		}
		else if (struc->minus == 0)
		{
			while (struc->calc_width > 0 && ++struc->count)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->calc_width--;
			}
			while (s[j] && j < struc->calc_precision)
			{
				write(1, &s[j], 1);
				j++;
			}
			struc->count += struc->calc_precision;
		}
		return ;
	}

	while (str[j])
	{
		ft_len_wchar(str[j], struc);
		j++;
	}
	count_precision_for_unicode(str, struc);
	if (struc->precision || struc->flag_precision)
	{
		
		//struc->calc_precision = struc->len_wchar2;
		struc->calc_precision = struc->precision;
		if (struc->calc_precision > struc->len_wchar)
			struc->calc_precision = struc->len_wchar;
		else
			struc->len_wchar = struc->calc_precision;
		printf("struc->len_wchar = %d\n", struc->len_wchar);
	}
	else
		struc->calc_precision = struc->len_wchar;

	if (struc->width || struc->width == 0)
	{
		// printf("struc->precision = %d\n", struc->precision);
		// printf("struc->len_wchar = %d\n", struc->len_wchar);
		if (!*str)
			struc->calc_width = struc->width;
		else if ((struc->precision < struc->len_wchar) && struc->flag_precision)
		{
			struc->calc_width = struc->width - struc->len_wchar;
			printf("11111111111\n"); //////
			// printf("struc->width = %d\n", struc->width);
			// printf("struc->len_wchar2 = %d\n", struc->len_wchar2);
			// printf("struc->calc_width = %d\n", struc->calc_width);
		}
		else if ((struc->precision == struc->len_wchar) && struc->flag_precision)
		{
			struc->calc_width = struc->width - struc->len_wchar;

			// if (struc->precision != struc->len_wchar3)
			// {
			// 	struc->calc_width = struc->width - struc->len_wchar3;
			// 	//printf("11111111222222\n");
			// }
			// else
			// {
			// 	struc->calc_width = struc->width - struc->len_wchar;
			// 	//printf("222222222222\n"); //////
			// }
			printf("222222222222\n");
			printf("struc->precision = %d\n", struc->precision);
			printf("struc->len_wchar = %d\n", struc->len_wchar);
			printf("struc->len_wchar1 = %d\n", struc->len_wchar1);
			printf("struc->len_wchar2 = %d\n", struc->len_wchar2);
			printf("struc->len_wchar3 = %d\n", struc->len_wchar3);
			printf("struc->width = %d\n", struc->width);
			printf("struc->calc_width = %d\n", struc->calc_width);
		}
		else if ((struc->precision > struc->len_wchar) && struc->flag_precision)
		{
			struc->calc_width = struc->width - struc->len_wchar2; //////
			printf("3333333333333\n");
			// printf("struc->precision = %d\n", struc->precision);
			// printf("struc->len_wchar2 = %d\n", struc->len_wchar2);
			// printf("struc->width = %d\n", struc->width);
			// printf("struc->calc_width = %d\n", struc->calc_width);
		}
		else if (struc->flag_precision)
		{
			if (struc->precision == 1)
				struc->calc_width = struc->width - struc->len_wchar;
			else
			{
				struc->calc_width = struc->width - struc->len_wchar2;
				//printf("4444444444444\n");
			}
		}
		else if (struc->flag_precision == 0)
			struc->calc_width = struc->width - struc->len_wchar;
		if (struc->calc_width < 0)
			struc->calc_width = 0;
		// printf("struc->width = %d\n", struc->width);
		// printf("struc->len_wchar = %d\n", struc->len_wchar);
		// printf("struc->calc_width = %d\n", struc->calc_width);
		// printf("struc->calc_precision = %d\n", struc->calc_precision);
		// printf("struc->calc_width = %d\n", struc->calc_width);
		// printf("struc->len_wchar3 = %d\n", struc->len_wchar3);
	}
	if (struc->width)
	{
		if (struc->minus)
		{
			while (str[i] && struc->calc_precision > 0 && struc->calc_precision >= struc->len_wchar1)
			{
				if (struc->precision == 1)
				{
					ft_len_wchar1(str[i], struc);
					if (struc->calc_precision == struc->len_wchar1)
					{
						ft_wchar_c(str[i], struc);
						struc->flag_wchar = 1;
					}
					else if (struc->flag_wchar == 0 && ++struc->count)
					{
						if (struc->noll)
							write(1, "0", 1);
						else
							write(1, " ", 1);
					}
					//struc->calc_precision--;
				}
				else
				{
					struc->current_count = struc->count;
					if (struc->precision >= struc->len_wchar2)
					{
						ft_wchar_c(str[i], struc);
						struc->destruct = struc->count - struc->current_count;
						struc->calc_precision = struc->calc_precision - struc->destruct;
						ft_len_wchar1(str[i + 1], struc);
					}
					
				}
				i++;
			}
			while (struc->calc_width && ++struc->count)
			{
				write(1, " ", 1);
				struc->calc_width--;
			}
		}
		else if (struc->minus == 0)
		{
			// printf("struc->calc_precision = %d\n", struc->calc_precision);
			// printf("struc->calc_width = %d\n", struc->calc_width);
			//ft_len_wchar1(str[i], struc);
			//printf("struc->len_wchar1 = %d\n", struc->len_wchar1);
			//printf("struc->calc_precision = %d\n", struc->calc_precision);
			
			while (struc->calc_width && ++struc->count)
			{
				if (struc->noll)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				struc->calc_width--;
			}
			if (struc->precision == 0 && struc->flag_precision)
				write(1, "", 0);
			else if (struc->precision)
			{
				while (str[i] && struc->calc_precision > 0 && struc->calc_precision >= struc->len_wchar1)
				{
					//printf("struc->calc_precision = %d\n", struc->calc_precision);
					if (struc->precision == 1)
					{
						ft_len_wchar1(str[i], struc);
						if (struc->calc_precision == struc->len_wchar1)
						{
							ft_wchar_c(str[i], struc);
							struc->flag_wchar = 1;
						}
						else if (struc->flag_wchar == 0 && ++struc->count)
						{
							if (struc->noll)
								write(1, "0", 1);
							else
								write(1, " ", 1);
						}
						//struc->calc_precision--;
					}
					else
					{
						struc->current_count = struc->count;
						ft_wchar_c(str[i], struc);
						struc->destruct = struc->count - struc->current_count;
						struc->calc_precision = struc->calc_precision - struc->destruct;
						// if (struc->calc_precision < 0)
						// 	struc->calc_precision = 0;
						ft_len_wchar1(str[i + 1], struc);
					}
					i++;
					// printf("struc->calc_precision = %d\n", struc->calc_precision);
					// printf("struc->len_wchar1 = %d\n", struc->len_wchar1);
				}
			}
			else
			{
				while (str[i] && struc->calc_precision)
				{
					ft_wchar_c(str[i], struc);
					struc->calc_precision = struc->calc_precision - struc->count;
					i++;
				}
			}

		}
	}
	else if (struc->flag_precision)
	{
		while (str[i] && struc->calc_precision > 0 && struc->calc_precision >= struc->len_wchar1)
		{
			if (struc->precision == 1)
			{
				ft_len_wchar1(str[i], struc);
				if (struc->calc_precision == struc->len_wchar1)
					ft_wchar_c(str[i], struc);
			}
			else
			{
				struc->current_count = struc->count;
				ft_wchar_c(str[i], struc);
				struc->destruct = struc->count - struc->current_count;
				struc->calc_precision = struc->calc_precision - struc->destruct;
				ft_len_wchar1(str[i + 1], struc);
			}
			i++;
			struc->calc_precision--;
		}
	}
	else
	{
		while (str[i] && i < struc->calc_precision)
		{
			ft_wchar_c(str[i], struc);
			i++;
		}
	}
	ft_bzero(struc, sizeof(int) * 22 + sizeof(char) * 3);
}
