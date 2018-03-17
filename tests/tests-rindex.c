/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** testing strchr function
*/

#include <criterion/criterion.h>

Test(rindex, empty_string)
{
	const char	*s = "";
	int		c = 'A';

	cr_expect_eq(rindex(s, c), NULL);
}

Test(rindex, char_at_the_beginning)
{
	const char	*s = "ALLO";
	int		c = 'A';

	cr_expect_eq(rindex(s, c), s);
}

Test(rindex, char_at_the_end)
{
	const char	*s = "ALOHA";
	int		c = 'A';

	cr_expect_eq(rindex(s, c), &s[4]);
}

Test(rindex, non_present_char)
{
	const char	*s = "SALUT";
	int		c = '+';

	cr_expect_eq(rindex(s, c), NULL);
}

Test(rindex, normal_test)
{
	const char	*s = "EASY";
	int		c = 'A';

	cr_expect_eq(rindex(s, c), &s[1]);
}
