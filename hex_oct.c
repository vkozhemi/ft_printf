#include "printf.h"

void	ft_uns_int(uintmax_t d, t_struc *struc, char *p, int *i)
{
	char *str;
	if (struc->conversions == 'u')
		str = ft_itoa_base_uns(d, 10, 0);
	else if (struc->conversions == 'U') // long
		str = ft_itoa_base_uns(d, 10, 0);
	else if (struc->conversions == 'o')
		str = ft_itoa_base_uns(d, 8, 0);
	else if (struc->conversions == 'O')
		str = ft_itoa_base_uns(d, 8, 0); // long
	else if (struc->conversions == 'x')
		str = ft_itoa_base_uns(d, 16, 1);
	else if (struc->conversions == 'X')
		str = ft_itoa_base_uns(d, 16, 0);// большие буквы
	
	if (struc->precision) /// precision
	{
		if ((p[*i] == 'O' || p[*i] == 'o') && struc->hash)
			struc->calc_precision = struc->precision - ft_strlen(str) - 1;
		else
			struc->calc_precision = struc->precision - ft_strlen(str);
		if (struc->calc_precision < 0)
			struc->calc_precision = 0;
	}
	else
		struc->calc_precision = 0;


	if (struc->width) // width
	{
		if (struc->width && d == 0 && struc->precision == 0 && struc->flag_precision)
			struc->calc_width = struc->width;
		else if (struc->hash && (p[*i] == 'x' || p[*i] == 'X'))
			struc->calc_width = struc->width - ft_strlen(str) -	struc->calc_precision - 2;
		else if (struc->hash && (p[*i] == 'o' || p[*i] == 'O'))
			struc->calc_width = struc->width - ft_strlen(str) -	struc->calc_precision - 1;
		else if (d == 0 && struc->precision == 0 && struc->flag_precision)
			struc->calc_width = struc->width;
		else
			struc->calc_width = struc->width - ft_strlen(str) -	struc->calc_precision;
	}
	else
		struc->calc_width = 0;
	if (struc->calc_width < 0)
		struc->calc_width = 0;

	if (struc->minus)
		ft_flag_minus_uns_int(struc, str, d, p, i);
	else
		ft_flag_no_minus_uns_int(struc, str, d, p, i);

	// if ((p[*i] == 'x' && struc->hash) || (p[*i] == 'X' && struc->hash)) // count i
	// 	struc->count += struc->i + ft_strlen(str) + 2;
	if (d == 0 && struc->precision) // count i
		struc->count += struc->i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0 && struc->flag_precision == 0)
		struc->count += struc->i + ft_strlen(str);
	else if (d == 0 && struc->precision == 0)
		struc->count += struc->i;
	else
		struc->count += ft_strlen(str) + struc->i;
	ft_bzero(struc, sizeof(char) + 3);
	ft_bzero(struc, sizeof(int) + 13);
}