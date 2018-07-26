#include "printf.h"
#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <wchar.h>
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

#define TITLE(...){printf("\033[1m\n");printf(__VA_ARGS__);printf("\n\033[0m");}

int main(void)
{
// sSpdDioOuUxXcC
	setlocale(LC_ALL, "en_US.UTF-8");
	//char c = 'a';
	//char c = 43;
	char *string = "hello world";
	//wchar_t wc = L'Ы';
	wchar_t *str = L"Привет";
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
	//wchar_t a = L'П';


	// int i = ft_printf("%1.0x\n", 0);
	// int j = printf("%1.0x\n", 0);
	int i = ft_printf("%.p, %.0p\n", 0, 0);
	int j =    printf("%.p, %.0p\n", 0, 0);
	printf("i = %d\n", i);
	printf("j = %d\n", j);
	// int a = ft_printf("my %d\n", 42);
	// int b = printf("or %d\n", 42);
	// printf("a = %d\n", a);
	// printf("b = %d\n", b);
	//printf("MB_CUR_MAX = %d\n", MB_CUR_MAX);
	//printf("%S\n", L"привет");


	// char a = ' ';
	// for (a = ' '; a <' ' + 60 ; a+=15)
	// PRINTF("|%-2c|(%3d)\t|%-2c|(%3d)\t|%-2c|(%3d)", a, a, a+5,a+5,a+10,a+10);
	// PRINTF("|%-2.3c|(%3d)\t|%-2.5c|(%3d)\t|%-2.0c|(%3d)", a, a, a+5,a+5,a+10,a+10);
	// PRINTF("|%+3c|(%3d)\t|%+3c|(%3d)\t|%+c|(%3d)", a, a, a+5, a+5, a+10, a+10);
	// PRINTF("|%3.4c|(%3d)\t|%+3.4c|(%3d)\t|%.4c|(%3d)", a, a, a+5, a+5, a+10, a+10);
	// PRINTF("|%-3w|(%3w)\t|%3Z|(%3Z)\t|%Q|(%3Q)");
	// PRINTF("|%3h|\t|%3l|\t|%3hhll|\t|%3llhhllQ|\t|%3z|\t|%3j|\t|%3J|");
	// PRINTF("|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|\t|%.C|\t|%.5C|", 0,0,0,0,0,0,0,0,0);
	

// # define CNV "o"
// 		printf("\n   |"CNV"|:\n");
// 		PRINTF("|%#6"CNV"|\t|%#-12"CNV"|\t|%#"CNV"|\t\t|%#09"CNV"|\t|%#02"CNV"|", 8400,8400,0,8400,8400);
// 		PRINTF("|%#6.7"CNV"|\t|%#-12.7"CNV"|\t|%#.7"CNV"|\t|%#011.7"CNV"|\t|%#02.7"CNV"|", 8400,8400,0,8400,8400);
// 		PRINTF("|%#6.2"CNV"|\t|%#-12.2"CNV"|\t|%#.3"CNV"|\t\t|%#09.2"CNV"|\t|%#02.2"CNV"|", 8400,8400,0,8400,8400);
// 		PRINTF("|%-#13.10"CNV"|\t|%-12.10"CNV"|\t|%-13.10"CNV"|\t|%-13.9"CNV"|\t\t", 25,25,25,25);

		


	// int nmb = 4235;
	// 	#define CNV "i"
	//  	 printf("\n   |"CNV"|:\n");
	// 	 PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
	// 	 PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
	// 	 PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%010.5"CNV"|",nmb, -nmb, nmb, -nmb);
	// 	 PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
	// 	 PRINTF("|%-.10"CNV"|\t|%.10"CNV"|\t|%-15.10"CNV"|\t|%15.10"CNV"|",42,42,42,42);
	// 	 PRINTF("|%-12.8"CNV"|\t|%12.8"CNV"|\t|%-12.5"CNV"|\t|%-12.8"CNV"|\t",42,42,42,42);
	// 	 PRINTF("|%7.5"CNV"|\t|%-7.5"CNV"|\t|%7.5"CNV"|\t|%-7.5"CNV"|\t", 42,42,42,42);
	// 	 PRINTF("|%12.8"CNV"|\t|%20.8"CNV"|\t|%20.8"CNV"||%20"CNV"|\t|%10.8"CNV"|",42,42,42,42,42);
	//  	 PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);

	 	// int nmb = 4235;
		// #define CNV "u"
	 // 	 printf("\n   |"CNV"|:\n");
		//  PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
		//  PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|",nmb, nmb, nmb, nmb);
		//  PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%010.5"CNV"|",nmb, nmb, nmb, nmb);
		//  PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, nmb, nmb, nmb);
		//  PRINTF("|%-.10"CNV"|\t|%.10"CNV"|\t|%-15.10"CNV"|\t|%15.10"CNV"|",42,42,42,42);
		//  PRINTF("|%-12.8"CNV"|\t|%12.8"CNV"|\t|%-12.5"CNV"|\t|%-12.8"CNV"|\t",42,42,42,42);
		//  PRINTF("|%7.5"CNV"|\t|%-7.5"CNV"|\t|%7.5"CNV"|\t|%-7.5"CNV"|\t", 42,42,42,42);
		//  PRINTF("|%12.8"CNV"|\t|%20.8"CNV"|\t|%20.8"CNV"||%20"CNV"|\t|%10.8"CNV"|",42,42,42,42,42);
	 // 	 PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);
	
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

// int nmb = 4235;
// 		#define CNV "x"
// 		printf("\n   |"CNV"|:\n");
// 		PRINTF("|%1.1"CNV"|\t\t|%5.1"CNV"|\t\t|%5.3"CNV"|\t\t|%1.5"CNV"|\t",nmb, nmb, nmb, nmb);
// 		PRINTF("|%1.1"CNV"|\t|%5.1"CNV"|\t|%5.3"CNV"|\t|%1.5"CNV"|",-nmb, -nmb, -nmb, -nmb);
// 		PRINTF("|%3.5"CNV"|\t\t|%3.5"CNV"|\t|%07.5"CNV"|\t|%07.5"CNV"|",nmb, -nmb, nmb, -nmb);
// 		PRINTF("|%8.5"CNV"|\t|%8.5"CNV"|\t|%08"CNV"|\t|%08"CNV"|",nmb, -nmb, nmb, -nmb);
// 		PRINTF("|%-.10"CNV"|\t|%.10"CNV"|\t|%-15.10"CNV"|\t|%15.10"CNV"|",42,42,42,42);
// 		PRINTF("|%-12.8"CNV"|\t|%12.8"CNV"|\t|%-12.8"CNV"|\t|%-12.8"CNV"|\t",42,42,42,42);
// 		PRINTF("|%7.5"CNV"|\t|%-7.5"CNV"|\t|%7.5"CNV"|\t|%-7.5"CNV"|\t", 42,42,42,42);
// 		PRINTF("|%12.8"CNV"|\t|%20.8"CNV"|\t|%20.8"CNV"||%20.5"CNV"|\t|%10.8"CNV"|",42,42,42,42,42);
// 		PRINTF("|%."CNV" %.0"CNV" %0."CNV" %0.0"CNV"|\t\t|%"CNV" %.2"CNV" %2."CNV" %2.2"CNV"|\t\t\t\t",0,0,0,0,0,0,0,0);







	// printf("   |i|:\n");
	// PRINTF("\t|%12i|\t|%12i|\t|%12i|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012i|\t|%-12i|\t|%012i|",-42,42,42);
	// printf("\n   |d|:\n");
	// PRINTF("\t|%12d|\t|%12d|\t|%12d|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012d|\t|%-12d|\t|%012d|",-42,42,42);
	// printf("\n   |D|:\n");
	// PRINTF("\t|%12D|\t|%12D|\t|%12D|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012D|\t|%-12D|\t|%012D|",-42,42,42);
	// printf("\n   |u|:\n");
	// PRINTF("\t|%12u|\t|%12u|\t|%12u|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012u|\t|%-12u|\t|%012u|",-42,42,42);
	// printf("\n   |U|:\n");
	// PRINTF("\t|%12U|\t|%12U|\t|%12U|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012U|\t|%-12U|\t|%012U|",-42,42,42);
	// printf("\n   |o|:\n");
	// PRINTF("\t|%12o|\t|%12o|\t|%12o|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012o|\t|%-12o|\t|%012o|",-42,42,42);
	// printf("\n   |O|:\n");
	// PRINTF("\t|%12O|\t|%12O|\t|%12O|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012O|\t|%-12O|\t|%012O|",-42,42,42);
	// printf("\n   |x|:\n");
	// PRINTF("\t|%12x|\t|%12x|\t|%12x|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012x|\t|%-12x|\t|%012x|",-42,42,42);
	// printf("\n   |X|:\n");
	// PRINTF("\t|%12X|\t|%12X|\t|%12X|", INT_MIN, INT_MAX,0);
	// PRINTF("\t|%012X|\t|%-12X|\t|%012X|",-42,42,42);
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