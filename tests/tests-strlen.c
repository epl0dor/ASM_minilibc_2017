/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** tests strlen
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(strlen, empty_string)
{
	const char	*s = "";
	cr_expect_eq(strlen(s), 0);
}

Test(strlen, normal_test)
{
	const char	*s = "Salut";
	cr_expect_eq(strlen(s), 5);
}

Test(strlen, one_char_length)
{
	const char	*s = "S";
	cr_expect_eq(strlen(s), 1);
}

Test(strlen, segfault_test, .signal = SIGSEGV)
{
	const char	*s = NULL;
	cr_expect(strlen(s));
}
