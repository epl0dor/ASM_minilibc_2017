/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** testing strchr function
*/

#include <criterion/criterion.h>

Test(strchr, empty_string)
{
	const char	*s = "";
	int		c = 'A';

	cr_expect_eq(strchr(s, c), NULL);
}

Test(strchr, char_at_the_beginning)
{
	const char	*s = "ALLO";
	int		c = 'A';

	cr_expect_eq(strchr(s, c), s);
}

Test(strchr, char_at_the_end)
{
	const char	*s = "KURWA";
	int		c = 'A';

	cr_expect_eq(strchr(s, c), &s[4]);
}

Test(strchr, non_present_char)
{
	const char	*s = "SALUT";
	int		c = '+';

	cr_expect_eq(strchr(s, c), NULL);
}

Test(strchr, normal_test)
{
	const char	*s = "EASY";
	int		c = 'A';

	cr_expect_eq(strchr(s, c), &s[1]);
}
