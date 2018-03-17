/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** tests strcmp function
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(strcmp, sample_test)
{
	const char	*s1 = "Salut";
	const char	*s2 = "Salto";

	cr_expect_eq(strcmp(s1, s2), 1);
}

Test(strcmp, same_strings)
{
	const char	*s1 = "Salut";
	const char	*s2 = "Salut";

	cr_expect_eq(strcmp(s1, s2), 0);
}

Test(strcmp, s1_empty)
{
	const char	*s1 = "";
	const char	*s2 = "Salut";

	cr_expect_eq(strcmp(s1, s2), -83);
}

Test(strcmp, s2_empty)
{
	const char	*s1 = "Salut";
	const char	*s2 = "";

	cr_expect_eq(strcmp(s1, s2), 83);
}

Test(strcmp, both_string_empty)
{
	const char	*s1 = "";
	const char	*s2 = "";

	cr_expect_eq(strcmp(s1, s2), 0);
}

Test(strcmp, same_letter_each)
{
	const char	*s1 = "S";
	const char	*s2 = "S";

	cr_expect_eq(strcmp(s1, s2), 0);
}

Test(strcmp, s1_null, .signal = SIGSEGV)
{
	const char	*s1 = NULL;
	const char	*s2 = "Salut";

	cr_expect_eq(strcmp(s1, s2), 0);
}

Test(strcmp, s2_null, .signal = SIGSEGV)
{
	const char	*s1 = "Salut";
	const char	*s2 = NULL;

	cr_expect_eq(strcmp(s1, s2), 0);
}

Test(strcmp, both_strings_null, .signal = SIGSEGV)
{
	const char	*s1 = NULL;
	const char	*s2 = NULL;

	cr_expect_eq(strcmp(s1, s2), 0);
}
