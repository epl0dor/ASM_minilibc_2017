/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** tests memmove function
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(memmove, sample_test)
{
	char dest[] = "oldstring";
	const char src[]  = "newstring";

	memmove(dest, src, 9);
	cr_expect_eq(strcmp(dest, src), 0);
}

Test(memmove, zero_value)
{
	char dest[] = "oldstring";
	const char src[]  = "newstring";

	memmove(dest, src, 0);
	cr_expect_neq(strcmp(dest, src), 0);
}

Test(memmove, dest_empty)
{
	char dest[9] = "";
	const char src[10]  = "newstring";

	memmove(dest, src, 9);
	cr_expect_eq(strcmp(dest, src), 0);
}

Test(memmove, src_empty)
{
	char dest[9] = "oldstring";
	const char src[10]  = "";

	memmove(dest, src, 9);
	cr_expect_eq(strcmp(dest, src), 0);
}

Test(memmove, both_empty)
{
	char dest[9] = "";
	const char src[10]  = "";

	memmove(dest, src, 9);
	cr_expect_eq(strcmp(dest, src), 0);
}
