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

void	ft_int(intmax_t d, t_struc *struc)
{
	char	*str;
	int		width;
	int		precision;
	int 	flag;
	int		i;

	i = 0;
	flag = 1;
	if (d < 0)
		str = ft_itoa_base_plus(d, 10, 0);
	else
		str = ft_itoa_base(d, 10, 0);
	if (struc->precision)
	{
		precision = struc->precision - ft_strlen(str);
		if (precision < 0)
			precision = 0;
	}
	else
		precision = 0;
	if (struc->width)
	{
		if ((struc->plus && d > 0) || (struc->plus && d < 0) || d < 0 || (struc->plus && d == 0))
			width = struc->width - ft_strlen(str) - precision - 1;
		else if (struc->space)
			width = struc->width - ft_strlen(str) - precision - 1;
		else if (d == 0 && struc->precision == 0 && struc->flag_precision) /////////
			width = struc->width;
		else
			width = struc->width - ft_strlen(str) - precision;
	}
	else
		width = 0;
	if (width < 0)
		width = 0;
	// printf("struc->width = %d\n", struc->width);
	// printf("width = %d\n", width);
	if (struc->minus)
	{
		if (struc->space && width && d > 0 && ++i)
			write(1, " ", 1);
		if (struc->plus && d >= 0 && flag && ++i)
		{
			write(1, "+", 1);
			flag--;
		}
		if (precision > 0)
		{
			if (d < 0 && ++i)
				write(1, "-", 1);
			else
				if (struc->plus && d >= 0 && flag && ++i)
					write(1, "+", 1);
			if (struc->space && ++i)
				write(1, " ", 1);
			while (precision > 0 && ++i)
			{
				ft_putchar('0');
				precision--;
			}
		}
		if (d < 0 && struc->precision == 0 && ++i)
			write(1, "-", 1);
		if (struc->precision == 0 && d == 0 && struc->flag_precision)
			write(1, "", 0);
		else
			ft_putstr(str);
		while (width > 0 && ++i)
		{
			if (struc->noll)
				ft_putchar('0');
			else
				ft_putchar(' ');
			width--;
		}
	}
	else
	{
		if (struc->space && struc->noll && width && d > 0 && ++i)
			write(1, " ", 1);
		//printf("width = %d\n", width);
		if (width == 0)
		{
			if (width == 0 && struc->plus && d >= 0 && ++i)
				write(1, "+", 1);
			else if (d < 0 && ++i)
				write(1, "-", 1);
		}
		while (width > 0)
		{
			//printf("struc->noll = %d\n", struc->noll);
			//printf("width = %d\n", width);
			if ((d < 0 && struc->noll == 0) || (struc->plus && struc->noll == 0))
			{
				while (width > 0 && ++i)
				{
					ft_putchar(' ');
					width--;
				}
				if (struc->plus && d >= 0 && ++i)
					write(1, "+", 1);
				else if (d < 0 && ++i)
					write(1, "-", 1);
			}
			else if (struc->noll && struc->precision)
			{
				while (width && d < 0 && ++i)
				{
					write(1, " ", 1);
					width--;
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
			width--;
		}
		if (precision > 0)
		{
			while (precision > 0 && ++i)
			{
				ft_putchar('0');
				precision--;
			}
		}
		if (struc->precision == 0 && d == 0 && struc->flag_precision)
			write(1, "", 0);
		else
			ft_putstr(str);
	}
	if (d == 0 && struc->precision)
		struc->count += i;
	else
		struc->count += ft_strlen(str) + i;
	//printf("struc->count = %zu\n", struc->count);
}
