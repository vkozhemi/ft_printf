#include "printf.h"

void	ft_str(va_list ap, t_struc *struc)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr(str);
	struc->count = ft_strlen(str);
}

void	ft_char(va_list ap, t_struc *struc)
{
	char	c;
	int		i;

	i = 0;
	i++;
	c = va_arg(ap, int);
	ft_putchar(c);
	struc->count = i;
}

void	ft_pointer(va_list ap, t_struc *struc)
{
	char *str;

	str = ft_itoa_base(va_arg(ap, unsigned long int), 16, 1);
	ft_putstr("0x");
	ft_putstr(str);
	struc->count = ft_strlen(str);
}

void	ft_wchar_s(va_list ap, t_struc *struc)
{
	int i = 0;
	wchar_t *str = va_arg(ap, wchar_t*);
	while (str[i])
	{
		ft_wchar_c(str[i], struc);
		i++;
	}
}