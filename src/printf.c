#include "printf.h"
/* minprintf: минимальный printf с переменным числом аргументов */
void ft_parsing(char *p, int i, va_list ap, t_struc **struc) // S D O u U C
{
	if (p[i + 1] == 's')
	{
		ft_putstr(va_arg(ap, char *));
		printf("\n");
	}
	else if (p[i + 1] == 'd' || p[i + 1] == 'i')
		ft_int(ap, struc);
	// else if (p[i + 1] == 'u')
	// 	ft_uns_int(ap, struc);
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
	else if (p[i] == 'c')
		ft_putchar(va_arg(ap, char *));
}

// void	ft_uns_int(va_list ap, t_struc **struc)
// {
// 	t_struc *ptr;
// 	char *str;

// 	ptr = *struc;
// 	str = ft_itoa_base(va_arg(ap, unsigned int), 10, 0);
// 	ft_putstr(str);
// 	ptr->len_u = ft_strlen(str);
// 	printf("ptr->len_u = %zu\n", ptr->len_u);
// }

void	ft_int(va_list ap, t_struc **struc)
{
	t_struc *ptr;
	char *str;

	ptr = *struc;
	str = ft_itoa_base(va_arg(ap, int), 10, 0);
	ft_putstr(str);
	ptr->len_d_i = ft_strlen(str);
	printf("ptr->len_d_i = %zu\n", ptr->len_d_i);
}

void ft_call_pars(char *fmt, va_list ap, t_struc **struc)
{
	int		i;
	int		j;
	char	*p;
	size_t	count;
	t_struc	*ptr;

	j = 0;
	ptr = *struc;
	p = fmt;
	count = 0;
	i = 0;
	ptr->count = count;
	while (p[i])
	{
		if (p[i] =='%')
			if (p[i + 1] != '%')
			{
				ft_parsing(p, i, ap, struc);
				j++;
			}
		i++;
	}
	if (p[i] == '\0' && j == 0)
	{
		ft_putstr(p);
		ptr->count = ft_strlen(p);
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
	ft_call_pars(fmt, ap, &struc);
	va_end(ap); /* очистка, когда все сделано */
	//printf("struc->count = %zu\n", struc->count);
	return (struc->count);
}

int main(void)
{
	int i;
	int res;
	char *str;

	//str = "hello world";
	i = 12;
	ft_printf("%u", i);
	// printf("\n");
	//ft_printf("12345\n");
	//res = ft_printf("12345\n");
	//printf("res = %d\n", res);
	// printf("%p", &i);
	// printf("\n");
	// printf("12345");
	return (0);
}