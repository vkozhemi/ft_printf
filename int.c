#include "printf.h"

// void	ft_uns_long_int(va_list ap, t_struc *struc)
// {
// 	char *str;

// 	str = ft_itoa_base_uns(va_arg(ap, unsigned long int), 10, 0);
// 	ft_putstr(str);
// 	struc->len_lu = ft_strlen(str);
// }

// void	ft_long_int(uintmax_t d, t_struc *struc)
// {
// 	char *str;

// 	str = ft_itoa_base(d, 10, 0);
// 	ft_putstr(str);
// 	struc->len_ld = ft_strlen(str);
// }

// void	ft_uns_int(uintmax_t d, t_struc *struc)
// {
// 	char *str;

// 	str = ft_itoa_base(d, 10, 0);
// 	ft_putstr(str);
// 	struc->len_u = ft_strlen(str);
// }

char 	ft_plus_minus(intmax_t d, char **str)
{
	if (d < 0)
		*str = ft_itoa_base_plus(d, 10, 0);
	else
		*str = ft_itoa_base(d, 10, 0);
	return (**str);
}

void 	ft_find_precision(t_struc *struc, char *str)
{
	if (struc->precision)
	{
		struc->calc_precision = struc->precision - ft_strlen(str);
		if (struc->calc_precision < 0)
			struc->calc_precision = 0;
	}
	else
		struc->calc_precision = 0;
}

void ft_width(t_struc *struc, char *str, int d)
{
	if (struc->width)
	{
		if ((struc->plus && d > 0) || (struc->plus && d < 0) || d < 0 || (struc->plus && d == 0))
			struc->calc_width = struc->width - ft_strlen(str) - struc->calc_precision - 1;
		else if (struc->space)
			struc->calc_width = struc->width - ft_strlen(str) - struc->calc_precision - 1;
		else if (d == 0 && struc->precision == 0 && struc->flag_precision) /////////
			struc->calc_width = struc->width;
		else
			struc->calc_width = struc->width - ft_strlen(str) - struc->calc_precision;
	}
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;
}

// void ft_flag_minus(t_struc *struc, char *str, int d, int *flag, int *i)
// {

// }

void	ft_int(intmax_t d, t_struc *struc)
{
	char	*str;
	int 	flag;
	int		i;

	i = 0;
	flag = 1;
	str = NULL;
	struc->calc_precision = 0;
	ft_plus_minus(d, &str);
	ft_find_precision(struc, str);
	// if (d < 0)
	// 	str = ft_itoa_base_plus(d, 10, 0);
	// else
	// 	str = ft_itoa_base(d, 10, 0);
	// if (struc->precision)
	// {
	// 	precision = struc->precision - ft_strlen(str);
	// 	if (precision < 0)
	// 		precision = 0;
	// }
	// else
	// 	precision = 0;
	ft_width(struc, str, d);
	// if (struc->width)
	// {
	// 	if ((struc->plus && d > 0) || (struc->plus && d < 0) || d < 0 || (struc->plus && d == 0))
	// 		width = struc->width - ft_strlen(str) - precision - 1;
	// 	else if (struc->space)
	// 		width = struc->width - ft_strlen(str) - precision - 1;
	// 	else if (d == 0 && struc->precision == 0 && struc->flag_precision) /////////
	// 		width = struc->width;
	// 	else
	// 		width = struc->width - ft_strlen(str) - precision;
	// }
	// else
	// 	width = 0;
	// if (width < 0)
	// 	width = 0;
	// printf("struc->width = %d\n", struc->width);
	// printf("width = %d\n", width);
	//ft_flag_minus(struc, str, d, &flag, &i);
	if (struc->minus)
	{
		if (struc->space && d > 0 && ++i)
			write(1, " ", 1);
		if (struc->plus && d >= 0 && flag && ++i)
		{
			write(1, "+", 1);
			flag--;
		}
		if (struc->calc_precision > 0)
		{
			if (d < 0 && ++i)
				write(1, "-", 1);
			else
				if (struc->plus && d >= 0 && flag && ++i)
					write(1, "+", 1);
			if (struc->space && ++i)
				write(1, " ", 1);
			while (struc->calc_precision > 0 && ++i)
			{
				ft_putchar('0');
				struc->calc_precision--;
			}
		}
		if (d < 0 && struc->precision == 0 && ++i)
			write(1, "-", 1);
		if (struc->precision == 0 && d == 0 && struc->flag_precision)
			write(1, "", 0);
		else
			ft_putstr(str);
		while (struc->calc_width > 0 && ++i)
		{
			if (struc->noll)
				ft_putchar('0');
			else
				ft_putchar(' ');
			struc->calc_width--;
		}
	}
	else
	{
		if (struc->space && struc->noll && struc->calc_width && d > 0 && ++i)
			write(1, " ", 1);
		//printf("width = %d\n", width);
		if (struc->calc_width == 0)
		{
			if (struc->calc_width == 0 && struc->plus && d >= 0 && ++i)
				write(1, "+", 1);
			else if (d < 0 && ++i)
				write(1, "-", 1);
		}
		while (struc->calc_width > 0)
		{
			//printf("struc->noll = %d\n", struc->noll);
			//printf("width = %d\n", width);
			if ((d < 0 && struc->noll == 0) || (struc->plus && struc->noll == 0))
			{
				while (struc->calc_width > 0 && ++i)
				{
					ft_putchar(' ');
					struc->calc_width--;
				}
				if (struc->plus && d >= 0 && ++i)
					write(1, "+", 1);
				else if (d < 0 && ++i)
					write(1, "-", 1);
			}
			else if (struc->noll && struc->precision)
			{
				while (struc->calc_width && d < 0 && ++i)
				{
					write(1, " ", 1);
					struc->calc_width--;
				}
				if (struc->plus && d >= 0 && ++i)
					write(1, "+", 1);
				else if (d < 0 && ++i)
					write(1, "-", 1);
				else if (++i)
					ft_putchar(' ');
			}
			else if (struc->noll)
			{
				if (d < 0 && flag && ++i)
				{
					write(1, "-", 1);
					flag--;
				}
				else if (struc->plus && d >= 0 && flag && ++i)
				{
						write(1, "+", 1);
						flag--;
				}
				write(1, "0", 1);
				i++;
			}
			else if (++i)
				write(1, " ", 1);
			struc->calc_width--;
		}
		if (struc->calc_precision > 0)
		{
			while (struc->precision > 0 && ++i)
			{
				ft_putchar('0');
				struc->calc_precision--;
			}
		}
		if (struc->precision == 0 && d == 0 && struc->flag_precision)
			write(1, "", 0);
		else
			ft_putstr(str);
	}
	if (d == 0 && struc->precision)
		struc->count += i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
		struc->count += i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0)
		struc->count += i;
	else
		struc->count += ft_strlen(str) + i;
	//printf("struc->count = %zu\n", struc->count);
}
