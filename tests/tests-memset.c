/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** testing memset function
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(memset, sample_test)
{
	char		s[6] = "SALUT";
	int		c = 'R';
	int		val = 5;

	memset(s, c, val);
	cr_expect_eq(strcmp(s, "RRRRR"), 0);
}

Test(memset, val_set_to_zero)
{
	char		s[6] = "SALUT";
	int		c = 'R';
	int		val = 0;

	memset(s, c, val);
	cr_expect_eq(strcmp(s, "SALUT"), 0);
}

Test(memset, empty_string)
{
	char		s[6] = "";
	int		c = 'R';
	int		val = 5;

	memset(s, c, val);
	cr_expect_eq(strcmp(s, "RRRRR"), 0);
}

Test(memset, null_pointer, .signal = SIGSEGV)
{
	char		*s = NULL;
	int		c = 'R';
	int		val = 5;

	memset(s, c, val);
	cr_expect_eq(strcmp(s, "RRRRR"), 0);
}

