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
		if ((struc->plus && d > 0) || (struc->plus && d < 0) || d < 0)
			width = struc->width - ft_strlen(str) - precision - 1;
		else if (struc->space)
			width = struc->width - ft_strlen(str) - precision - 1;
		else
			width = struc->width - ft_strlen(str) - precision;
	}
	else
		width = 0;
	if (struc->minus)
	{
		if (precision > 0)
		{
			if (d < 0) /////////////// вставить провел если пробел
				write(1, "-", 1);
			else
				if (struc->plus)
					write(1, "+", 1);
			if (struc->space)
				write(1, " ", 1);
			while (precision > 0)
			{
				
				ft_putchar('0');
				precision--;
			}
		}
		ft_putstr(str);
		while (width > 0)
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
		while (width > 0)
		{
			if (struc->noll && struc->precision)
				ft_putchar(' ');
			else if (struc->noll)
				ft_putchar('0');
			else
				ft_putchar(' ');
			width--;
		}
		if (d < 0)
			write(1, "-", 1);
		else
			if (struc->plus)
				write(1, "+", 1);
		if (precision > 0)
		{
			while (precision > 0)
			{
				ft_putchar('0');
				precision--;
			}
		}
		ft_putstr(str);
	}
	struc->len_int = ft_strlen(str);
}
