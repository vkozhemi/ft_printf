#include "printf.h"

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
	int d = 10;
	//short h = 55;
	//unsigned int ui = 4294967295;

	//ft_printf("%X\n", o);
	//printf("%X\n", o);
	//ft_printf("my %-7d\n", d);
	//printf("or %-7d\n", d);


	ft_printf("%- 10.5d\n", 555);
	printf("%- 10.5d\n", 555);
	printf("%10.5d\n", 555);
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