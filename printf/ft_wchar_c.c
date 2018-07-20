#include "printf.h"

int	ft_size_bin(wchar_t value)
{
	int i;

	i = 0;
	while(value)
	{
		value = value / 2;
		i++;
	}
	return (i);
}

void	ft_wchar_c(wchar_t value, t_struc *struc)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	unsigned int mask1 = 49280;
	unsigned int mask2 = 14712960;
	unsigned int mask3 = 4034953344;
	unsigned int v = value;
	int size = ft_size_bin(value);
	unsigned char octet;
	int			i;

	i = 0;
	octet = 0;
	if (size <= 7)
	{
			octet = value;
			write(1, &octet, 1);
			struc->count++;
	}
	else  if (size <= 11)
		ft_wchar_c11(v, mask1, octet, struc);
	else  if (size <= 16)
		ft_wchar_c16(v, mask2, octet, struc);
	else
		ft_wchar_c32(v, mask3, octet, struc);
}

void	ft_wchar_c11(unsigned int v, unsigned int mask1, unsigned char octet, t_struc *struc)
{
	unsigned char o2 = (v << 26) >> 26; // Восстановление первых 6 бит 110xxxxx 10(xxxxxx)
	unsigned char o1 = ((v >> 6) << 27) >> 27; // Восстановление последних 5 бит 110(xxxxx) 10xxxxxx

	octet = (mask1 >> 8) | o1; // Применение первой битовой маски ко первому байту
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2; // Применение второй битовой маски ко второму байту
	write(1, &octet, 1);
	struc->count += 2;
}

void	ft_wchar_c16(unsigned int v, unsigned int mask2, unsigned char octet, t_struc *struc)
{
	unsigned char o3 = (v << 26) >> 26; // Восстановление первых 6 бит 1110xxxx 10xxxxxx 10(xxxxxx)
	unsigned char o2 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 1110xxxx 10(xxxxxx) 10xxxxxx
	unsigned char o1 = ((v >> 12) << 28) >> 28; // Восстановление последних 4 бит 1110(xxxx) 10xxxxxx 10xxxxxx

	octet = (mask2 >> 16) | o1; // Применение первой битовой маски ко первому байту
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2; // Применение второй битовой маски ко второму байту
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
	write(1, &octet, 1);
	struc->count += 3;
}

void	ft_wchar_c32(unsigned int v, unsigned int mask3, unsigned char octet, t_struc *struc)
{
	unsigned char o4 = (v << 26) >> 26; // Восстановление первых 6 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
	unsigned char o3 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
	unsigned char o2 = ((v >> 12) << 26) >> 26;  // Восстановление третьих 6 бит bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
	unsigned char o1 = ((v >> 18) << 29) >> 29; // Восстановление последних 3 бита 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

	octet = (mask3 >> 24) | o1; // Применение бит первого байта на первый байт маски
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2; // Применение второй битовой маски ко второму байту
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4; // Применение последней битовой маски ко последнему байту
	write(1, &octet, 1);
	struc->count += 4;
}