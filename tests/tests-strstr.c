/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** testing strchr function
*/

#include <criterion/criterion.h>

char		*my_strstr(const char *haystack, const char *needle)
{
	char	*ret = (char *)haystack;
	size_t	i;

	if (*needle == '\0')
		return (ret);
	while (*ret != '\0') {
		i = 0;
		while (ret[i] == needle[i])
			i++;
		if (needle[i] == '\0')
			return (ret);
		*ret++;
	}
	return (NULL);
}

Test(strstr, sample_test)
{
	const char	*haystack = "Bonjour. Ou plutôt, Salut.";
	const char	*needle = "Salut";
	char		*ret;

	ret = strstr(haystack, needle);
	cr_expect_eq(ret, haystack + 21);
}

Test(strstr, needle_not_found)
{
	const char	*haystack = "Bonjour. Ou plutôt, Salut.";
	const char	*needle = "ALOHA";
	char		*ret;

	ret = strstr(haystack, needle);
	cr_expect_eq(ret, NULL);
}

Test(strstr, empty_needle)
{
	const char	*haystack = "Bonjour. Ou plutôt, Salut.";
	const char	*needle = "";
	char		*ret;

	ret = strstr(haystack, needle);
	cr_expect_eq(ret, haystack);
}

Test(strstr, empty_haystack)
{
	const char	*haystack = "";
	const char	*needle = "Salut";
	char		*ret;

	ret = strstr(haystack, needle);
	cr_expect_eq(ret, NULL);
}

Test(strstr, only_never_complete_needle)
{
	const char	*haystack = "Salto arrière, puis Salto avant";
	const char	*needle = "Salut";
	char		*ret;

	ret = strstr(haystack, needle);
	cr_expect_eq(ret, NULL);
}
