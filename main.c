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

#define TITLE(...){printf("\033[1m\n");printf(__VA_ARGS__);printf("\n\033[0m");}

int main(void)
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
//	int d = 10;
	//short h = 55;
	//unsigned int ui = 4294967295;

	//ft_printf("%X\n", o);
	//printf("%X\n", o);
	//ft_printf("my %-7d\n", d);
	//printf("or %-7d\n", d);


	int i = ft_printf("%#011.7o\n", 42);
	int j = printf("%#011.7o\n", 42);
	 printf("i = %d\n", i);
	 printf("j = %d\n", j);

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

	 // 	 int nmb = 4235;
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