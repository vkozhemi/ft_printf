#include "printf.h"

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
		str = ft_itoa_base_uns(d, 16, 0);// большие буквы
	
	ft_putstr(str);
	struc->count = ft_strlen(str);
}