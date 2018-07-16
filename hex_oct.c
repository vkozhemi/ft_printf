#include "printf.h"

// void	ft_uns_hexb(va_list ap, t_struc *struc)
// {
// 	char *str;

// 	str = ft_itoa_base(va_arg(ap, unsigned int), 16, 0);
// 	ft_putstr(str);
// 	struc->len_uhb = ft_strlen(str);
// }

void	ft_uns_int(uintmax_t d, t_struc *struc)
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
		str = ft_itoa_base_uns(d, 16, 0); // большие буквы
	ft_putstr(str);
	struc->len_uo = ft_strlen(str);
}

// void	ft_uns_hex(uintmax_t d, t_struc *struc)
// {
// 	char *str;

// 	str = ft_itoa_base(d, 16, 1); // 1 & 0
// 	ft_putstr(str);
// 	struc->len_uh = ft_strlen(str);
// }

// void	ft_uns_oct(uintmax_t d, t_struc *struc)
// {
// 	char *str;

// 	str = ft_itoa_base(d, 8, 0); // long
// 	ft_putstr(str);
// 	struc->len_uo = ft_strlen(str);
// }

// void	ft_uns_long_oct(va_list ap, t_struc *struc)
// {
// 	char *str;

// 	str = ft_itoa_base(va_arg(ap, unsigned long int), 8, 0);
// 	ft_putstr(str);
// 	struc->len_ulo = ft_strlen(str);
// }