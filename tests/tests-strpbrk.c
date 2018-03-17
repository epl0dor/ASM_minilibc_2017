/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** test strpbrk function
*/

#include <criterion/criterion.h>

Test(strpbrk, first_char_found)
{
	const char	str1[] = "abcde2fghi3jk4l";
	const char	str2[] = "34";
	char		*ret;

	ret = strpbrk(str1, str2);
	cr_expect_eq(ret, &str1[10]);
}

Test(strpbrk, first_char_not_found)
{
	const char	str1[] = "abcde2fghiOjk4l";
	const char	str2[] = "34";
	char		*ret;

	ret = strpbrk(str1, str2);
	cr_expect_eq(ret, &str1[13]);
}

Test(strpbrk, str2_empty)
{
	const char	str1[] = "abcde2fghiOjk4l";
	const char	str2[] = "";
	char		*ret;

	ret = strpbrk(str1, str2);
	cr_expect_eq(ret, NULL);
}

Test(strpbrk, str1_empty)
{
	const char	str1[] = "";
	const char	str2[] = "34";
	char		*ret;

	ret = strpbrk(str1, str2);
	cr_expect_eq(ret, NULL);
}
