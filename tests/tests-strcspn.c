/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** test strcspn function
*/

#include <criterion/criterion.h>

Test(strcspn, first_char_found)
{
	const char	str1[] = "abcde2fghi3jk4l";
	const char	str2[] = "34";
	size_t		ret;

	ret = strcspn(str1, str2);
	cr_expect_eq(ret, 10);
}

Test(strcspn, first_char_not_found)
{
	const char	str1[] = "abcde2fghiOjk4l";
	const char	str2[] = "34";
	size_t		ret;

	ret = strcspn(str1, str2);
	cr_expect_eq(ret, 13);
}

Test(strcspn, str2_empty)
{
	const char	str1[] = "abcde2fghiOjk4l";
	const char	str2[] = "";
	size_t		ret;

	ret = strcspn(str1, str2);
	cr_expect_eq(ret, 15);
}

Test(strcspn, str1_empty)
{
	const char	str1[] = "";
	const char	str2[] = "34";
	size_t		ret;

	ret = strcspn(str1, str2);
	cr_expect_eq(ret, 0);
}
