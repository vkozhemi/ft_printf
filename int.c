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
	char *str;

	str = ft_itoa_base(d, 10, 0);
	ft_putstr(str);
	struc->len_d_i = ft_strlen(str);
}