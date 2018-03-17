/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** testing memcpy function
*/

#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(memcpy, sample_test)
{
	char	src[6] = "SALUT";
	char	dest[6] = "";

	memcpy(dest, src, strlen(src) + 1);
	cr_expect_eq(strcmp(dest, "SALUT"), 0);
}

Test(memcpy, empty_src)
{
	char	src[6] = "";
	char	dest[6] = "LOL";

	memcpy(dest, src, strlen(src) + 1);
	cr_expect_eq(strcmp(dest, ""), 0);
}

Test(memcpy, null_src)
{
	char	*src = NULL;
	char	dest[6] = "";

	memcpy(dest, src, 0);
	cr_expect_eq(strcmp(dest, ""), 0);
}

Test(memcpy, null_dest, .signal = SIGSEGV)
{
	char	src[6] = "SALUT";
	char	*dest = NULL;

	memcpy(dest, src, strlen(src) + 1);
	cr_expect_eq(strcmp(dest, "SALUT"), 0);
}
