#include "libft.h"

int	ft_len_uns(unsigned long long value, int base)
{
	unsigned long long len;

	if (value == 0)
		len = 1;
	else
		len = 0;
	while (value)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_uns(unsigned long long value, int base, int size)
{
	unsigned long long	nbr;
	int					len;
	char				*str;
	char				*base_string;

	nbr = value;
	len = ft_len_uns(value, base);
	if (size == 0)
		base_string = "0123456789ABCDEF";
	else
		base_string = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = base_string[nbr % base];
		nbr = nbr / base;
	}
	return (str);
}