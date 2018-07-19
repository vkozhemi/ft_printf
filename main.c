#include "printf.h"
#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <limits.h>
#include <errno.h>

#define RED "\x1b[31m"
#define NORM "\x1b[0m"
#define PRINTF(...){\
		int ret = 0,ret2 = 0;\
		printf("Args:\t%s\n", #__VA_ARGS__);\
		printf("Origin:\t");ret = printf(__VA_ARGS__);\
		printf("\tret: %d\n",ret);fflush(stdout);\
		ft_printf("    Ft:\t");ret2 = ft_printf(__VA_ARGS__);\
		printf("\t%sret: %d"NORM"\n",(ret == ret2) ? NORM : RED, ret2);\
		printf("\n");fflush(stdout);\
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
	int d = 10;
	//short h = 55;
	//unsigned int ui = 4294967295;

	//ft_printf("%X\n", o);
	//printf("%X\n", o);
	//ft_printf("my %-7d\n", d);
	//printf("or %-7d\n", d);


	//ft_printf("my |%-d\n", 0);
	//printf("or |%-d\n", 0);
	int nmb = 4235;
		#define CNV "i"
		printf("\n   |"CNV"|:\n");
		// PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		// PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
		// PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%010.5"CNV"|",nmb, -nmb, nmb, -nmb);
		// PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
		// PRINTF("|%-.10"CNV"|\t|%.10"CNV"|\t|%-15.10"CNV"|\t|%15.10"CNV"|",42,42,42,42);
		// PRINTF("|%-12.8"CNV"|\t|%12.8"CNV"|\t|%-12.5"CNV"|\t|%-12.8"CNV"|\t",42,42,42,42);
		// PRINTF("|%7.5"CNV"|\t|%-7.5"CNV"|\t|%7.5"CNV"|\t|%-7.5"CNV"|\t", 42,42,42,42);
		// PRINTF("|%12.8.10.6"CNV"|\t|%20.8.-12.6"CNV"|\t|%20.8.12.-6"CNV"||%20.-5.12.3"CNV"|\t|%10.8.12.6-"CNV"|",42,42,42,42,42);
		 PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	// неправильно возвращает кол символов !!!!!!!!!!!!!!!!!!!!!!!!!!
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