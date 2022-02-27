/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macasubo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:32:53 by macasubo          #+#    #+#             */
/*   Updated: 2022/02/27 19:22:21 by macasubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

void		red()
{
	printf("\033[1;31m");
}

void		green()
{
	printf("\033[0;32m");
}

void		reset()
{
	printf("\033[0m");
}

void		fail(int n)
{
	printf("test %d: ", n);
	red();
	printf("FAIL\n");
	reset();
}

void		pass(int n)
{
	printf("test %d: ", n);
	green();
	printf("PASS\n");
	reset();
}

void		test_without_flags()
{
	if (printf("\n") == ft_printf("\n"))
		pass(1);
	else
		fail(1);
	if (printf("42\n") == ft_printf("42\n"))
		pass(2);
	else
		fail(2);
	if (printf("%42\n") == ft_printf("%42\n"))
		pass(3);
	else
		fail(3);
	printf("UNDEFINED BEHAVIOR\n");
	if (printf("          \n") == ft_printf("          \n"))
		pass(4);
	else
		fail(4);
	if (printf("\n", "test", 42) == ft_printf("\n", "test", 42))
		pass(5);
	else
		fail(5);
}

void		test_percent()
{
	if (printf("%%\n") == ft_printf("%%\n"))
		pass(1);
	else
		fail(1);
	if (printf("%%%\n") == ft_printf("%%%\n"))
		pass(2);
	else
		fail(2);
	printf("UNDEFINED BEHAVIOR\n");
	if (printf("%%%%\n") == ft_printf("%%%%\n"))
		pass(3);
	else
		fail(3);
	if (printf("%%\n", "test") == ft_printf("%%\n", "test"))
		pass(4);
	else
		fail(4);
	if (printf("%\n") == ft_printf("%\n"))
		pass(5);
	else
		fail(5);
	printf("UNDEFINED BEHAVIOR\n");
}

void		test_c()
{
	if (printf("%c\n", 42) == ft_printf("%c\n", 42))
		pass(1);
	else
		fail(1);
	if (printf("%c\n", 0) == ft_printf("%c\n", 0))
		pass(2);
	else
		fail(2);
	if (printf("lol%cabc%cdef\n", '4', '2') ==
		ft_printf("lol%cabc%cdef\n", '4', '2'))
		pass(3);
	else
		fail(3);
}

void		test_s()
{
	if (printf("%s\n", "") == ft_printf("%s\n", ""))
		pass(1);
	else
		fail(1);
	if (printf("%s\n", "aaaaaaaaaa") == ft_printf("%s\n", "aaaaaaaaaa"))
		pass(2);
	else
		fail(2);
	if (printf("aaa%sccc%seee\n", "bbb", "ddd") ==
		ft_printf("aaa%sccc%seee\n", "bbb", "ddd"))
		pass(3);
	else
		fail(3);
	if (printf("%s\n", NULL) == ft_printf("%s\n", NULL))
		pass(4);
	else
		fail(4);
}

void		test_int()
{
	if (printf("%d\n", 0) == ft_printf("%d\n", 0))
		pass(1);
	else
		fail(1);
	if (printf("%d\n", 42) == ft_printf("%d\n", 42))
		pass(2);
	else
		fail(2);
	if (printf("%d\n", INT_MIN) == ft_printf("%d\n", INT_MIN))
		pass(3);
	else
		fail(3);
	if (printf("%d\n", INT_MAX) == ft_printf("%d\n", INT_MAX))
		pass(4);
	else
		fail(4);
	if (printf("%i\n", 0) == ft_printf("%i\n", 0))
		pass(5);
	else
		fail(5);
	if (printf("%i\n", 42) == ft_printf("%i\n", 42))
		pass(6);
	else
		fail(6);
	if (printf("%i\n", INT_MIN) == ft_printf("%i\n", INT_MIN))
		pass(7);
	else
		fail(7);
	if (printf("%i\n", INT_MAX) == ft_printf("%i\n", INT_MAX))
		pass(8);
	else
		fail(8);
	if (printf("%u\n", 0) == ft_printf("%u\n", 0))
		pass(9);
	else
		fail(9);
	if (printf("%u\n", 42) == ft_printf("%u\n", 42))
		pass(10);
	else
		fail(10);
	if (printf("%u\n", UINT_MAX - 1) == ft_printf("%u\n", UINT_MAX - 1))
		pass(11);
	else
		fail(11);
	if (printf("%u\n", UINT_MAX) == ft_printf("%u\n", UINT_MAX))
		pass(12);
	else
		fail(12);
}

void		test_hex()
{
	if (printf("%p\n", NULL) == ft_printf("%p\n", NULL))
		pass(1);
	else
		fail(1);
	if (printf("%p\n", "abc") == ft_printf("%p\n", "abc"))
		pass(2);
	else
		fail(2);
	if (printf("%xa\n", 15) == ft_printf("%xa\n", 15))
		pass(3);
	else
		fail(3);
	if (printf("%xa\n", 16) == ft_printf("%xa\n", 16))
		pass(4);
	else
		fail(4);
	if (printf("%x\n", INT_MIN) == ft_printf("%x\n", INT_MIN))
		pass(5);
	else
		fail(5);
	if (printf("%x\n", UINT_MAX + 1) == ft_printf("%x\n", UINT_MAX + 1))
		pass(6);
	else
		fail(6);
	if (printf("%Xa\n", 15) == ft_printf("%Xa\n", 15))
		pass(7);
	else
		fail(7);
	if (printf("%Xa\n", 16) == ft_printf("%Xa\n", 16))
		pass(8);
	else
		fail(8);
	if (printf("%X\n", INT_MIN) == ft_printf("%X\n", INT_MIN))
		pass(9);
	else
		fail(9);
	if (printf("%X\n", INT_MAX) == ft_printf("%X\n", INT_MAX))
		pass(10);
	else
		fail(10);
	if (printf("%x\n", 0) == ft_printf("%x\n", 0))
		pass(11);
	else
		fail(11);
	if (printf("%X\n", 0) == ft_printf("%x\n", 0))
		pass(12);
	else
		fail(12);
	if (printf("%x\n", -42) == ft_printf("%x\n", -42))
		pass(13);
	else
		fail(13);
	if (printf("%x\n", INT_MAX) == ft_printf("%x\n", INT_MAX))
		pass(14);
	else
		fail(14);
}

void		test_zero()
{
	if (printf("%0u\n", UINT_MAX) == ft_printf("%0u\n", UINT_MAX))
		pass(1);
	else
		fail(1);
	if (printf("%050u\n", UINT_MAX) == ft_printf("%050u\n", UINT_MAX))
		pass(2);
	else
		fail(2);
	if (printf("%010u\n", UINT_MAX) == ft_printf("%010u\n", UINT_MAX))
		pass(3);
	else
		fail(3);
	if (printf("%011u\n", UINT_MAX) == ft_printf("%011u\n", UINT_MAX))
		pass(4);
	else
		fail(4);
	if (printf("%050.15u\n", 42) == ft_printf("%050.15u\n", 42))
		pass(5);
	else
		fail(5);
	if (printf("%014.25u\n", UINT_MAX) == ft_printf("%014.25u\n", UINT_MAX))
		pass(6);
	else
		fail(6);
	if (printf("%014d\n", INT_MIN) == ft_printf("%014d\n", INT_MIN))
		pass(7);
	else
		fail(7);
}

void		test_other()
{
	if (printf("%15.4d\n", -42) == ft_printf("%15.4d\n", -42))
		pass(1);
	else
		fail(1);
	if (printf("%.d, %.0d\n", 0, 0) == ft_printf("%.d, %.0d\n", 0, 0))
		pass(2);
	else
		fail(2);
	if (printf("%.p, %.0p\n", 0, 0) == ft_printf("%.p, %.0p\n", 0, 0))
		pass(3);
	else
		fail(3);
	if (printf("%.5p\n", 0) == ft_printf("%.5p\n", 0))
		pass(4);
	else
		fail(4);
	if (printf("%5p\n", 0) == ft_printf("%5p\n", 0))
		pass(5);
	else
		fail(5);
	if (printf("%*d\n", -5, 42) == ft_printf("%*d\n", -5, 42))
		pass(6);
	else
		fail(6);
	if (printf("%.*d\n", 0, 42) == ft_printf("%.*d\n", 0, 42))
		pass(7);
	else
		fail(7);
	if (printf("%.*s\n", 0, "42") == ft_printf("%.*s\n", 0, "42"))
		pass(8);
	else
		fail(8);
	if (printf("%3.1s\n", NULL) == ft_printf("%3.1s\n", NULL))
		pass(9);
	else
		fail(9);
	printf("UNDEFINED BEHAVIOUR\n");
	if (printf("%5.x %5.0xa\n", 0, 0) == ft_printf("%5.x %5.0xa\n", 0, 0))
		pass(10);
	else
		fail(10);
	if (printf("%.x %.0xa\n", 0, 0) == ft_printf("%.x %.0xa\n", 0, 0))
		pass(11);
	else
		fail(11);
	if (printf("%5.d %5.0da\n", 0, 0) == ft_printf("%5.d %5.0da\n", 0, 0))
		pass(12);
	else
		fail(12);
	if (printf("%*3d\n", 5, 0) == ft_printf("%*3d\n", 5, 0))
		pass(13);
	else
		fail(13);
	printf("UNDEFINED BEHAVIOR\n");
	if (printf("%015%\n") == ft_printf("%015%\n"))
		pass(14);
	else
		fail(14);
	printf("UNDEFINED BEHAVIOUR\n");
	if (printf("%015s\n", "yo") == ft_printf("%015s\n", "yo"))
		pass(15);
	else
		fail(15);
	if (printf("%015c\n", 'c') == ft_printf("%015c\n", 'c'))
		pass(16);
	else
		fail(16);
	//printf("ret = %d\n", ft_printf("%.x %.0xa\n", 0, 0));
	//printf("ret = %d\n", printf("%.x %.0xa\n", 0, 0));
}

void		test_hard()
{
	if (printf("%0000*.1c%0-*.*s\t%-0.1d%0*.14i%*u  %013x%.*X%17p\n", 5, 's', 9, 7, "alut ca", INT_MIN, 16, INT_MAX, 13, UINT_MAX, INT_MAX - 42, 11, INT_MAX - 4242, test_hard) == ft_printf("%0000*.1c%0-*.*s\t%-0.1d%0*.14i%*u  %013x%.*X%17p\n", 5, 's', 9, 7, "alut ca", INT_MIN, 16, INT_MAX, 13, UINT_MAX, INT_MAX - 42, 11, INT_MAX - 4242, test_hard))
		pass(1);
	else
		fail(1);
}

int			main(void)
{
	printf("\tWITHOUT FLAGS : \n");
	test_without_flags();
	printf("\n\tPERCENT : \n");
	test_percent();
	printf("\n\tc CONVERSION : \n");
	test_c();
	printf("\n\ts CONVERSION : \n");
	test_s();
	printf("\n\tint CONVERSIONS : \n");
	test_int();
	printf("\n\thex CONVERSIONS : \n");
	test_hex();
	printf("\n\tZERO FLAG : \n");
	test_zero();
	printf("\n\tOTHER TESTS : \n");
	test_other();
	printf("\n\tHARD TESTS : \n");
	test_hard();

	return (0);
}
