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
		struc->precision = ft_atoi(p + (*i));
		while (p[*i] >= '0' && p[*i] <= '9')
			(*i)++;
		printf("struc->precision = %d\n", struc->precision);
	}
	//else
	//	ft_putstr(p + (*i));
}

void ft_size_modifier(char *p, int *i, va_list ap, t_struc *struc)
{
	int j;

	j = 0;
	if ((p[*i] == 'h' && p[*i + 1] == 'h') ||
			(p[*i] == 'l' && p[*i + 1] == 'l'))
	{
		while (p[*i] == 'h' || p[*i] == 'l')
		{
			struc->modifier[j] = p[*i];
			(*i)++;
			j++;
		}
	}
	else if (p[*i] == 'h' || p[*i] == 'l' || p[*i] == 'j' || p[*i] == 'z')
	{
		struc->modifier[j] = p[*i];
		(*i)++;
		j++;
	}
	//else
		//(*i)++;
	printf("struc->modifier = %s\n", struc->modifier);
	printf("i_modifier = %d\n", *i);
}


void ft_conversions(char *p, int *i, va_list ap, t_struc *struc)
{
	if (p[*i] == 'c')
		ft_char(ap, struc);
	else if (p[*i] == 's')
		ft_str(ap, struc);
	else if (p[*i] == 'd' || p[*i] == 'i')
		ft_int(ap, struc);
	else if (p[*i] == 'D')
		ft_long_int(ap, struc);
	else if (p[*i] == 'C')
	{
		wchar_t value = va_arg(ap, wchar_t);
		ft_wchar_c(value, struc);
	}
	else if (p[*i] == 'S')
	 	ft_wchar_s(ap, struc);
	else if (p[*i] == 'O')
		ft_uns_long_oct(ap, struc);
	else if (p[*i] == 'u')
		ft_uns_int(ap, struc);
	else if (p[*i] == 'U')
		ft_uns_long_int(ap, struc);
	else if (p[*i] == 'o')
		ft_uns_oct(ap, struc);
	else if (p[*i] == 'x')
		ft_uns_hex(ap, struc);
	else if (p[*i] == 'X')
		ft_uns_hexb(ap, struc);
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
	if (p[i] == '\0' && j == 0)
	{
		ft_putstr(p);
		struc->count = ft_strlen(p);
	}
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

int main(int argc, char **argv)
{
// sSpdDioOuUxXcC

	//char c = 'a';
	//char c = 43;
	//char *s = "hello world";
	//wchar_t wc = L'Ы';
	//wchar_t *str = L"ыыЫЗФд";
	//unsigned int o = 12;
	//long long ll = 9223372036854775807; // изменить itoa_base с -1 на 9223372036854775807
	//unsigned long long ull = 18446744073709551615;
	//int d = atoi(argv[1]);
	//int d = -2147483648;
	short h = 55;
	//unsigned int ui = 4294967295;

	//ft_printf("%X\n", o);
	//printf("%X\n", o);
	ft_printf("my %015.14d\n", h);
	printf("or %015.14d\n",h);

	//res = ft_printf("%u\n", i);
	//printf("res = %d\n", res);
	// printf("\n");
	//ft_printf("12345\n");
	//res = ft_printf("12345\n");
	//printf("res = %d\n", res);
	//ft_printf("%U\n", ull);
	//printf("%U\n", ull);
	// printf("\n");
	// printf("12345");
	return (0);
}