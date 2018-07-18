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
		else
			width = struc->width - ft_strlen(str) - precision;
	}
	else
		width = 0;
	if (width < 0)
		width = 0;
	if (struc->minus)
	{
		if (struc->space && width && d > 0) /////////////// space ????????????????
			write(1, " ", 1);
		if (struc->plus && d >= 0 && flag)
		{
			write(1, "+", 1);
			flag--;
		} /////////////// space ????????????????
			
		if (precision > 0)
		{
			if (d < 0)
				write(1, "-", 1);
			else
				if (struc->plus && d >= 0 && flag)
					write(1, "+", 1);
			if (struc->space)
				write(1, " ", 1);
			while (precision > 0)
			{
				ft_putchar('0');
				precision--;
			}
		}
		if (d < 0 && struc->precision == 0)
			write(1, "-", 1);
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
		if (struc->space && struc->noll && width && d > 0) /////////////// space ????????????????
			write(1, " ", 1);
		printf("width = %d\n", width);
		if (width == 0)
		{
			if (width == 0 && struc->plus && d >= 0)
					write(1, "+", 1);
				else if (d < 0)
					write(1, "-", 1);
		}
		while (width > 0) /// width = 0 ???????????????????????
		{
			
			if ((d < 0 && struc->noll == 0) || (struc->plus && struc->noll == 0))
			{
				while (width > 0)
				{
					ft_putchar(' ');
					width--;
				}
				if (struc->plus && d >= 0)
					write(1, "+", 1);
				else if (d < 0 )
					write(1, "-", 1);
			}
			else if (struc->noll && struc->precision)
			{
				if (struc->plus && d >= 0)
					write(1, "+", 1);
				else if (d < 0)
					write(1, "-", 1);
				else
					ft_putchar(' ');
			}
			else if (struc->noll) ///////////// ??????????????
			{
				if (d < 0 && flag)
				{
					write(1, "-", 1);
					flag--;
				}
				else
					if (struc->plus && d >= 0 && flag)
					{
						write(1, "+", 1);
						flag--;
					}
				ft_putchar('0');
			}
			else
				ft_putchar(' ');
			width--;
		}
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
