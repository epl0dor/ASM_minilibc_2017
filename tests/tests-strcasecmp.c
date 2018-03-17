/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** tests strcasecmp function
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(strcasecmp, sample_test)
{
	const char	*s1 = "Salut";
	const char	*s2 = "Salto";

	cr_expect_eq(strcasecmp(s1, s2), 1);
}

Test(strcasecmp, same_strings)
{
	const char	*s1 = "Salut";
	const char	*s2 = "Salut";

	cr_expect_eq(strcasecmp(s1, s2), 0);
}

Test(strcasecmp, s1_empty)
{
	const char	*s1 = "";
	const char	*s2 = "Salut";

	cr_expect_eq(strcasecmp(s1, s2), -115);
}

Test(strcasecmp, s2_empty)
{
	const char	*s1 = "Salut";
	const char	*s2 = "";

	cr_expect_eq(strcasecmp(s1, s2), 115);
}

Test(strcasecmp, both_string_empty)
{
	const char	*s1 = "";
	const char	*s2 = "";

	cr_expect_eq(strcasecmp(s1, s2), 0);
}

Test(strcasecmp, same_letter_each)
{
	const char	*s1 = "S";
	const char	*s2 = "S";

	cr_expect_eq(strcasecmp(s1, s2), 0);
}

Test(strcasecmp, sample_test_capitalized)
{
	const char	*s1 = "SALUT";
	const char	*s2 = "Salto";

	cr_expect_eq(strcasecmp(s1, s2), 1);
}

Test(strcasecmp, s1_null, .signal = SIGSEGV)
{
	const char	*s1 = NULL;
	const char	*s2 = "Salut";

	cr_expect_eq(strcasecmp(s1, s2), 0);
}

Test(strcasecmp, s2_null, .signal = SIGSEGV)
{
	const char	*s1 = "Salut";
	const char	*s2 = NULL;

	cr_expect_eq(strcasecmp(s1, s2), 0);
}

Test(strcasecmp, both_strings_null, .signal = SIGSEGV)
{
	const char	*s1 = NULL;
	const char	*s2 = NULL;

	cr_expect_eq(strcasecmp(s1, s2), 0);
}
