/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** tests strncmp function
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(strncmp, sample_test)
{
	const char	*s1 = "Salut";
	const char	*s2 = "Salto";

	cr_expect_eq(strncmp(s1, s2, 3), 0);
}

Test(strncmp, sample_test_2)
{
	const char	*s1 = "Salut";
	const char	*s2 = "Salto";

	cr_expect_neq(strncmp(s1, s2, 5), 0);
}

Test(strncmp, same_strings)
{
	const char	*s1 = "Salut";
	const char	*s2 = "Salut";

	cr_expect_eq(strncmp(s1, s2, 5), 0);
}

Test(strncmp, s1_empty)
{
	const char	*s1 = "";
	const char	*s2 = "Salut";

	cr_expect_eq(strncmp(s1, s2, 5), -83);
}

Test(strncmp, s2_empty)
{
	const char	*s1 = "Salut";
	const char	*s2 = "";

	cr_expect_eq(strncmp(s1, s2, 5), 83);
}

Test(strncmp, both_string_empty)
{
	const char	*s1 = "";
	const char	*s2 = "";

	cr_expect_eq(strncmp(s1, s2, 5), 0);
}

Test(strncmp, same_letter_each)
{
	const char	*s1 = "S";
	const char	*s2 = "S";

	cr_expect_eq(strncmp(s1, s2, 1), 0);
}

Test(strncmp, s1_null, .signal = SIGSEGV)
{
	const char	*s1 = NULL;
	const char	*s2 = "Salut";

	cr_expect_eq(strncmp(s1, s2, 5), 0);
}

Test(strncmp, s2_null, .signal = SIGSEGV)
{
	const char	*s1 = "Salut";
	const char	*s2 = NULL;

	cr_expect_eq(strncmp(s1, s2, 1), 0);
}

Test(strncmp, both_strings_null, .signal = SIGSEGV)
{
	const char	*s1 = NULL;
	const char	*s2 = NULL;

	cr_expect_eq(strncmp(s1, s2, 1), 0);
}
