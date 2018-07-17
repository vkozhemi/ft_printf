#include "printf.h"

void ft_flags(char *p, int *i, va_list ap, t_struc *struc)
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

void ft_field_width(char *p, int *i, va_list ap, t_struc *struc)
{
	struc->width = 0;
	struc->width = ft_atoi(p + (*i));
	while (p[*i] >= '0' && p[*i] <= '9')
		(*i)++;
	printf("struc->width = %d\n", struc->width);
}

void ft_precision(char *p, int *i, va_list ap, t_struc *struc)
{
	if (p[*i] == '.')
	{
		(*i)++;
		struc->precision = 0;
		struc->precision = ft_atoi(p + (*i));
		while (p[*i] >= '0' && p[*i] <= '9')
			(*i)++;
		printf("struc->precision = %d\n", struc->precision);
	}
}

void ft_size_modifier(char *p, int *i, va_list ap, t_struc *struc)
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
	printf("struc->modifier = %c\n", struc->modifier);
}

void ft_get_conversions(char *p, int *i, va_list ap, t_struc *struc)
{
	if (p[*i] == 'c') // char c
		struc->conversions = p[*i];
	else if (p[*i] == 's') // char *str
		struc->conversions = p[*i];
	else if (p[*i] == 'd' || p[*i] == 'i') // int
		struc->conversions = p[*i];
	else if (p[*i] == 'D') // long int
		struc->conversions = p[*i];
	else if (p[*i] == 'u') // unsigned int
		struc->conversions = p[*i];
	else if (p[*i] == 'U') // unsigned long int
		struc->conversions = p[*i];
	else if (p[*i] == 'C') // char unicode
		struc->conversions = p[*i];
	else if (p[*i] == 'S') // char *unicode
	 	struc->conversions = p[*i];
	else if (p[*i] == 'O') // unsigned long 8 
		struc->conversions = p[*i];
	else if (p[*i] == 'o') // unsigned 8
		struc->conversions = p[*i];
	else if (p[*i] == 'x') // unsigned 16
		struc->conversions = p[*i];
	else if (p[*i] == 'X') // UNSIGNED 16 
		struc->conversions = p[*i];
	else if (p[*i] == 'p') // pointer
		struc->conversions = p[*i];
}

void ft_conversions(char *p, int *i, va_list ap, t_struc *struc)  // hh, h, l, ll, j, z
{
	ft_get_conversions(p, i, ap, struc);
	if (p[*i] == 'c')
		ft_char(ap, struc);
	else if (p[*i] == 's')
		ft_str(ap, struc);
	else if (p[*i] == 'd' || p[*i] == 'i' || p[*i] == 'D') // l ll h hh j z 
	{
		if (struc->modifier == 'l' || p[*i] == 'D')
			ft_int(va_arg(ap, long int), struc);
		else if (struc->modifier == 'L') // ll
			ft_int(va_arg(ap, long long int), struc);
		else if (struc->modifier == 'h')
			ft_int((short)va_arg(ap, int), struc);
		else if (struc->modifier == 'H') // hh - char or unsigned char
			ft_int((char)va_arg(ap, int), struc);
		else if (struc->modifier == 'j') // 
			ft_int(va_arg(ap, intmax_t), struc);
		else if (struc->modifier == 'z') // 
			ft_int(va_arg(ap, size_t), struc);
		else
			ft_int(va_arg(ap, int), struc);
	}
	else if (p[*i] == 'u' || p[*i] == 'U' || p[*i] == 'o' || p[*i] == 'O'
			|| p[*i] == 'x' || p[*i] == 'X') 								// u: l ll h hh j z         U:         
	{
		if (struc->modifier == 'l')
			ft_uns_int(va_arg(ap, unsigned long int), struc);
		else if (struc->modifier == 'L') // ll
			ft_uns_int(va_arg(ap, unsigned long long int), struc);
		else if (struc->modifier == 'h')
			ft_uns_int((short)va_arg(ap, unsigned int), struc);
		else if (struc->modifier == 'H') // hh - char or unsigned char
			ft_uns_int((unsigned char)va_arg(ap, unsigned int), struc);
		else if (struc->modifier == 'j') // 
			ft_uns_int(va_arg(ap, uintmax_t), struc);
		else if (struc->modifier == 'z') // 
			ft_uns_int(va_arg(ap, size_t), struc);
		else
			ft_uns_int(va_arg(ap, unsigned int), struc);
	}
	else if (p[*i] == 'C')
	{
		wchar_t value = va_arg(ap, wchar_t);
		ft_wchar_c(value, struc);
	}
	else if (p[*i] == 'S')
	 	ft_wchar_s(ap, struc);
//	else if (p[*i] == 'O') long o
//		ft_uns_long_oct(ap, struc);
//	else if (p[*i] == 'o') // l ll h hh j z
//		ft_uns_oct(ap, struc);
//	else if (p[*i] == 'x') // l ll h hh j z
//		ft_uns_hex(ap, struc);
//	else if (p[*i] == 'X') // l ll h hh j z  //большие буквы
//		ft_uns_hexb(ap, struc);
	else if (p[*i] == 'p')
		ft_pointer(ap, struc);
}

void ft_call_pars(char *fmt, va_list ap, t_struc *struc)
{
	int		i;
	int		j;
	char	*p;
	size_t	count;

	j = 0;
	p = fmt;
	count = 0;
	i = 0;
	struc->count = count;
	while (p[i])
	{
		if (p[i] =='%')
		{
			if (p[i + 1] != '%')
			{
				i++;
				ft_flags(p, &i, ap, struc);
				ft_field_width(p, &i, ap, struc);
				ft_precision(p, &i, ap, struc);
				ft_size_modifier(p, &i, ap, struc);
				ft_conversions(p, &i, ap, struc);
				j++;
			}
			//i++; // change it!!!!!
		}
		else
			write(1, &p[i], 1);	
		i++;
	}
	struc->count = ft_strlen(p);
	printf("struc->count = %zu\n", struc->count);

	// if (p[i] == '\0' && j == 0)
	// {
	// 	ft_putstr(p);
	// 	struc->count = ft_strlen(p);
	// }
}

int ft_printf(char *fmt, ...)
{
	size_t	result;
	t_struc	*struc;
	result = 0;
	va_list ap; /* указывает на очередной безымянный аргумент */
	char	*p;

	struc = (t_struc*)malloc(sizeof(t_struc));
	va_start(ap, fmt); /* устанавливает ap на 1-й безымянный аргумент */
	ft_call_pars(fmt, ap, struc);
	va_end(ap); /* очистка, когда все сделано */
	return (struc->count);
}