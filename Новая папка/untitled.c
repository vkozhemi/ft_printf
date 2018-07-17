#include "printf.h"
/* minprintf: минимальный printf с переменным числом аргументов */
void ft_parsing(char *p, int i, va_list ap) // s S p d D i o O u U x X c C
{
	if (p[i + 1] == 's')
	{
		ft_putstr(va_arg(ap, char *));
		printf("\n");
	}
	else if (p[i + 1] == 'd' || p[i + 1] == 'i')
		ft_putstr(ft_itoa_base(va_arg(ap, int), 10, 0));
	else if (p[i + 1] == 'o')
		ft_putstr(ft_itoa_base(va_arg(ap, int), 8, 0));
	else if (p[i + 1] == 'x')
		ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 1));
	else if (p[i + 1] == 'X')
		ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 0));
	else if (p[i + 1] == 'p')
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base(va_arg(ap, unsigned long int), 16, 1));
	}
	else if (p[i] == 's')
		ft_putstr(va_arg(ap, char *));
}

void ft_call_pars(char *fmt, va_list ap)
{
	int		i;
	int		j;
	char	*p;
	size_t	count;
	t_struc	*struc;

	p = fmt;
	count = 0;
	i = 0;
	struc = (t_struc*)malloc(sizeof(t_struc));
	struc->count = count;
	while (p[i])
	{
		if (p[i] =='%')
			if (p[i + 1] != '%')
			{
				ft_parsing(p, i, ap);
				j++;
			}
		i++;
	}
	if (p[i] == '\0' && j == 0)
	{
		ft_putstr(p);
		struc->count = ft_strlen(p);
		printf("count = %zu\n", struc->count);
	}
}

int ft_printf(char *fmt, ...)
{
	size_t	result;
	
	result = 0;
	va_list ap; /* указывает на очередной безымянный аргумент */
	char	*p;

	va_start(ap, fmt); /* устанавливает ap на 1-й безымянный аргумент */
	ft_call_pars(fmt, ap);
	va_end(ap); /* очистка, когда все сделано */
	return (0);
}

int main(void)
{
	int i;
	char *str;
	int res;

	str = "hello world";
	i = 12;
	//ft_printf("%s", str);
	// printf("\n");
	res = ft_printf("12345\n");
	printf("res = %d\n", res);
	// printf("%p", &i);
	// printf("\n");
	// printf("12345");
	return (0);
}