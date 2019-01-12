/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:07:00 by sofchami          #+#    #+#             */
/*   Updated: 2019/01/05 19:07:02 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{

// // // 	// printf("%.4s\n", "42");
// // // 	// ft_printf("%.4s\n", "42");

	int ret4 = 0;
	int ret5 = 0;
	int ret6 = 0;
	int ret7 = 0;

	// ret4 = printf("%X\n", -42);
	// ret5 = ft_printf("%X\n", -42);
	// printf("%d\n", ret4);
	// printf("%d\n", ret5);

	// printf("%s\n, %d");

	// ret4 = printf("{%.100f}-{%F}\n", 123456.1234567891234567891234567891234567891234567891234567891234678912345678912346789123456789, 1.42);
	// ret5 = ft_printf("{%.100f}-{%F}\n", 123456.1234567891234567891234567891234567891234567891234567891234678912345678912346789123456789, 1.42);
	// // ret5 = ft_printf("{%f}\n\n", 1.0);

	// printf("%d\n", ret4);
	// printf("%d\n", ret5);

	// ret6 = printf("{%f}{%F}\n", -1.42, -1.42);
	// ret7 = ft_printf("{%f}{%F}\n", -1.42, -1.42);

	// printf("%d\n", ret6);
	// printf("%d\n", ret7);

	// ret4 = printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	// ret5 = ft_printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);

	// printf("%d\n", ret4);
	// printf("%d\n", ret5);

	// printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
	// ft_printf("{%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);

// 	// ft_printf("%.4s\n", "42");
// 	// printf("%.4s\n\n", "42");

// 	// ret4 = ft_printf("%.4s\n", "42 is the answer");
// 	// ret5 = printf("%.4s\n\n", "42 is the answer");


	
// 	// ret6 = ft_printf("%15.4s\n", "42");
// 	// ret7 = printf("%15.4s\n", "42");
// 	// printf("%d\n", ret6);
// 	// printf("%d\n", ret7);
	
// 	// ret4 = ft_printf("%15.4s\n", "I am 42");
// 	// ret5 = printf("%15.4s\n\n", "I am 42");
	

// 	// ret4 = ft_printf("%15.4s\n", "42 is the answer");
// 	// ret5 = printf("%15.4s\n\n", "42 is the answer");
	
// 	// ret4 = ft_printf("%4.15s\n", "42");
// 	// ret5 = printf("%4.15s\n\n", "42");

// 	// ret4 = ft_printf("%4.15s\n", "I am 42");
// 	// ret5 = printf("%4.15s\n\n", "I am 42");

// 	// ret4 = ft_printf("%4.15s\n", "42 is the answer");
// 	// ret5 = printf("%4.15s\n\n", "42 is the answer");
	
// // 	ret4 = ft_printf("%4.s\n", "42");
// // 	ret5 = printf("%4.s\n\n", "42");
// // 	printf("%d\n", ret4);
// // 	printf("%d\n", ret5 - 1);

	// ft_printf("%.4d\n", -424242);
	// printf("%.4d\n\n", -424242);

	// ft_printf("%4.8d\n", -424242424);
	// printf("%4.8d\n\n", -424242424);

	// ft_printf("%15.4d\n", -424242);
	// printf("%15.4d\n\n", -424242);
	
	// ft_printf("%8.4d\n", -424242424);
	// printf("%8.4d\n\n", -424242424);
	
	// ft_printf("%4.15d\n", -42);
	// printf("%4.15d\n\n", -42);
	
	// ft_printf("%4.15d\n", -424242);
	// printf("%4.15d\n\n", -424242);

	// ft_printf("%15.4d\n", -42);
	// printf("%15.4d\n\n", -42);

	// printf("%03.2d\n", -1);
	// ft_printf("%03.2d\n", -1);

// 	ret4 = printf("%.4d\n", -424242);
// 	ret5 = ft_printf("%.4d\n", -424242);
// 	printf("%d\n", ret4);
// 	printf("%d\n", ret5);
	// int i;
	// char s;
	// char	*test_simple_mix;
	// unsigned long l;
	// ret4 = ft_printf("%10.3d", -42);
	// printf(" le ret4 - - - = %d:\n", ret4);
	// ret5 = printf("%10.3d", -42);
	// printf(" le ret4 - - - = %d:\n", ret5);
	// ret4 = printf("%17p\n", &strlen);
	// printf("%d\n", ret4);
	// ret5 = ft_printf("%17p\n", &strlen);
	// printf("%d\n", ret5);
	// printf("%p\n", &s);
	// ft_printf("%p\n", &s);

	// ft_putendl(ft_itoa_base( 40, "01234567"));
	// char var = -1;
	// int i = 8;
	// while (--i >= 0)
	//   write (1, (var & (1 << i)) ? "1" : "0", 1); 
	// return (0);

	// OCTAL\\

	// printf("OCTAL OK\n");
	
	// ft_printf("%.3%\n");
	// printf("%.p\n", 0);
	// printf ("printf1     :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf1  :|%5o|%5.3o|%5.1o|%5.0o|%5.o|\n\n", 1,1,1,1,1);
	
	// printf ("printf2     :|%#o|%#5.3o|%#5.1o|%#5.0o|%#5.o|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf2  :|%#o|%#5.3o|%#5.1o|%#5.0o|%#5.o|\n\n", 1,1,1,1,1);

	// printf ("printf3     :|%-#5o|%-#5.3o|%-#5.1o|%-#5.0o|%-#5.o|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf3  :|%-#5o|%-#5.3o|%-#5.1o|%-#5.0o|%-#5.o|\n\n", 1,1,1,1,1);

	// printf ("printf4     :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf4  :|%0#5o|%0#5.3o|%0#5.1o|%0#5.0o|%0#5.o|\n\n", 1,1,1,1,1);
	
	// printf ("printf5     :|%-0#5o|%-0#5.3o|%-0#5.1o|%-0#5.0o|%-0#5.o|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf5  :|%-0#5o|%-0#5.3o|%-0#5.1o|%-0#5.0o|%-0#5.o|\n\n", 1,1,1,1,1);

	// printf("|-0#5o|");
	// printf("%LmaD\n", 15);

	// // HEXA\\

	// printf("HEXA OK\n");
	// // //1
	// printf("ref : '%010x'\n", 542);
	// ft_printf("test: '%010x'\n", 542);
	// printf("ref : '%#010x'\n", 542);
	// ft_printf("test: '%#010x'\n", 542);
	// printf ("printf1     :|%5x|%5.3x|%5.1x|%5.0x|%5.x|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf1  :|%5x|%5.3x|%5.1x|%5.0x|%5.x|\n\n", 1,1,1,1,1);
	// // //2
	// printf ("printf2     :|%#5x|%#5.3x|%#5.1x|%#5.0x|%#5.x|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf2  :|%#5x|%#5.3x|%#5.1x|%#5.0x|%#5.x|\n\n", 1,1,1,1,1);
	// //3
	// printf ("printf3     :|%-#5x|%-#5.3x|%-#5.1x|%-#5.0x|%-#5.x|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf3  :|%-#5x|%-#5.3x|%-#5.1x|%-#5.0x|%-#5.x|\n\n", 1,1,1,1,1);
	// // 4
	// printf ("printf4     :|%0#5x|%0#5.3x|%0#5.1x|%0#5.0x|%0#5.x|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf4  :|%0#5x|%0#5.3x|%0#5.1x|%0#5.0x|%0#5.x|\n\n", 1,1,1,1,1);
	// //5
	// printf ("printf5     :|%-0#5x|%-0#5.3x|%-0#5.1x|%-0#5.0x|%-0#5.x|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf5  :|%-0#5x|%-0#5.3x|%-0#5.1x|%-0#5.0x|%-0#5.x|\n\n", 1,1,1,1,1);

	// ret4 = printf("%05d\n", -42);
	// ret5 = ft_printf("%05d\n", -42);
	// printf("ret4 = %d\n", ret4);
	// printf("ret5 = %d\n", ret5);

	// printf("Flag P OK \n");
	// // 1
	// printf ("printf1     :|%7p|%7.3p|%7.1p|%7.0p|%7.p|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf1  :|%7p|%7.3p|%7.1p|%7.0p|%7.p|\n\n", 1,1,1,1,1);
	// // 2
	// printf ("printf2     :|%#7p|%#7.3p|%#7.1p|%#7.0p|%#7.p|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf2  :|%#7p|%#7.3p|%#7.1p|%#7.0p|%#7.p|\n\n", 1,1,1,1,1);
	// //3
	// printf ("printf3     :|%-#7p|%-#7.3p|%-#7.1p|%-#7.0p|%-#7.p|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf3  :|%-#7p|%-#7.3p|%-#7.1p|%-#7.0p|%-#7.p|\n\n", 1,1,1,1,1);
	// // 4
	// printf ("printf4     :|%0#7p|%0#7.1p|\n", -1,-1);
	// ft_printf ("ft_printf4  :|%0#7p|%0#7.1p|\n\n", -1,-1);
	// //5
	// printf ("printf5     :|%-0#7p|%-0#7.3p|%-0#7.1p|%-0#7.0p|%-0#7.p|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf5  :|%-0#7p|%-0#7.3p|%-0#7.1p|%-0#7.0p|%-0#7.p|\n\n", 1,1,1,1,1);


	// // DECI\\

	// printf("DECI OK \n");
	// // 1
	// printf ("printf1     :|%+ 5d|%+ 5.3d|%+ 5.1d|%+ 5.0d|%+ 5.d|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf1  :|%+ 5d|%+ 5.3d|%+ 5.1d|%+ 5.0d|%+ 5.d|\n\n", 1,1,1,1,1);
	// // // //2
	// printf ("printf2     :|% 5d|% 5.3d|% 5.1d|% 5.0d|% 5.d|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf2  :|% 5d|% 5.3d|% 5.1d|% 5.0d|% 5.d|\n\n", 1,1,1,1,1);
	// // //3
	// printf ("printf3     :|%-+5d|%-+5.3d|%-+5.1d|%-+5.0d|%-+5.d|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf3  :|%-+5d|%-+5.3d|%-+5.1d|%-+5.0d|%-+5.d|\n\n", 1,1,1,1,1);
	// //4
	// printf ("printf4     :|%0+5d|%0+6.3d|%0+5.1d|%0+5.0d|%0+5.d|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf4  :|%0+5d|%0+6.3d|%0+5.1d|%0+5.0d|%0+5.d|\n\n", 1,1,1,1,1);
	// // //5
	// printf ("printf5     :|%-+05d|%-+05.3d|%-+05.1d|%-+05.0d|%-+05.d|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf5  :|%-+05d|%-+05.3d|%-+05.1d|%-+05.0d|%-+05.d|\n\n", 1,1,1,1,1);
	// //6
	// printf ("printf6     :|% 05d|% 05.3d|% 05.1d|% 05.0d|% 05.d|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf6  :|% 05d|% 05.3d|% 05.1d|% 05.0d|% 05.d|\n\n", 1,1,1,1,1);
	// // //7
	// printf("printf7      :|% 03d|\n", 0);
	// ft_printf("ft_printf7   :|% 03d|\n", 0);

	// printf("\nunsigned\n");
	// //unsigned\\
	// //1
	// printf ("printf1     :|%+ 5u|%+ 5.3u|%+ 5.1u|%+ 5.0u|%+ 5.u|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf1  :|%+ 5u|%+ 5.3u|%+ 5.1u|%+ 5.0u|%+ 5.u|\n\n", 1,1,1,1,1);
	// //2
	// printf ("printf2     :|% 5u|% 5.3u|% 5.1u|% 5.0u|% 5.u|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf2  :|% 5u|% 5.3u|% 5.1u|% 5.0u|% 5.u|\n\n", 1,1,1,1,1);
	// //3
	// printf ("printf3     :|%-+5u|%-+5.3u|%-+5.1u|%-+5.0u|%-+5.u|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf3  :|%-+5u|%-+5.3u|%-+5.1u|%-+5.0u|%-+5.u|\n\n", 1,1,1,1,1);
	// //4
	// printf ("printf4     :|%0+5u|%0+5.3u|%0+5.1u|%0+5.0u|%0+5.u|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf4  :|%0+5u|%0+5.3u|%0+5.1u|%0+5.0u|%0+5.u|\n\n", 1,1,1,1,1);
	// //5
	// printf ("printf5     :|%-+05u|%-+05.3u|%-+05.1u|%-+05.0u|%-+05.u|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf5  :|%-+05u|%-+05.3u|%-+05.1u|%-+05.0u|%-+05.u|\n\n", 1,1,1,1,1);
	// //6
	// printf ("printf6     :|% 05u|% 05.3u|% 05.1u|% 05.0u|% 05.u|\n", 1,1,1,1,1);
	// ft_printf ("ft_printf6  :|% 05u|% 05.3u|% 05.1u|% 05.0u|% 05.u|\n\n", 1,1,1,1,1);
	//7
	return (0);
}
