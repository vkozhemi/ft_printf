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

int main(void)
{
// sSpdDioOuUxXcC

	 // int i;
	 // int j;
	//char c = 'a';
	//char c = 43;
	//char *s = "hello world";
	//wchar_t wc = L'Ы';
	//wchar_t *str = L"ыыЫЗФд";
	//unsigned int o = 12;
	//long long ll = 9223372036854775807; // изменить itoa_base с -1 на 9223372036854775807
	//unsigned long long ull = 18446744073709551615;
	//int d = atoi(argv[1]);
//	int d = 10;
	//short h = 55;
	//unsigned int ui = 4294967295;

	//ft_printf("%X\n", o);
	//printf("%X\n", o);
	//ft_printf("my %-7d\n", d);
	//printf("or %-7d\n", d);


	ft_printf("my |%-+10.5d\n", -42);
	printf("or |%-+10.5d\n", -42);
	// printf("i = %d\n", i);
	// printf("j = %d\n", j);
	// int nmb = 4235;
		// #define CNV "li"
	 // 	 printf("\n   |"CNV"|:\n");
	// 	 PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
	// 	 PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
	// 	 PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%010.5"CNV"|",nmb, -nmb, nmb, -nmb);
	// 	 PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
	// 	 PRINTF("|%-.10"CNV"|\t|%.10"CNV"|\t|%-15.10"CNV"|\t|%15.10"CNV"|",42,42,42,42);
	// 	 PRINTF("|%-12.8"CNV"|\t|%12.8"CNV"|\t|%-12.5"CNV"|\t|%-12.8"CNV"|\t",42,42,42,42);
	// 	 PRINTF("|%7.5"CNV"|\t|%-7.5"CNV"|\t|%7.5"CNV"|\t|%-7.5"CNV"|\t", 42,42,42,42);
	// 	 PRINTF("|%12.8"CNV"|\t|%20.8"CNV"|\t|%20.8"CNV"||%20"CNV"|\t|%10.8"CNV"|",42,42,42,42,42);
	 	 // PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",2147483648,-2147483648,-2147483649,2147483648,2147483648,2147483648,2147483648,2147483648);
	
	// #ifdef LENGTH
	// TITLE("Number options(field width and length modifiers):\n");
	// printf("\t|%5s|\t|%5s|\t|%20s|\t|%20s|\t|%20s|\t|%10s|\t|%10s|\n", "hh", "h", "l", "ll","j", "z", "nothing" );
	// {
	// 	# define CNV "i"
	// 	printf("\n   |"CNV"|:\n");
	// 	PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,LONG_MAX,-2,LONG_MAX);
	// 	PRINTF("|%5hh"CNV"|\t|%5h"CNV"|\t|%20l"CNV"|\t|%20ll"CNV"|\t|%20j"CNV"|\t|%10z"CNV"|\t|%10"CNV"|", LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,LONG_MIN,-2,LONG_MIN);
	// }
	// # define CNV "i"
	// 	printf("\n   |"CNV"|:\n");
	// 	PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|\t", 8400,8400,0,8400,8400);
	// 	PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#09.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
	// 	PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|\t", 8400,8400,0,8400,8400);
	// 	PRINTF("|%-#13.10"CNV"|\t|%-12#.10"CNV"|\t|%-13.10#"CNV"|\t|%-13.-9#"CNV"|\t\t", 25,25,25,25);
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