#include "shell.h"

/**
 * _strlen -this  returns the length of a string
 * @s:  string- length to check
 *
 * Return:returns the integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - this performs lexicogarphic comparison of two strangs.
 * @s1: first strang
 * @s2:  second strang
 *
 * Return:returns negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - confirms whether needle starts with haystack
 * @haystack:the  string to search
 * @needle: the substring to find
 *
 * Return: returns address of next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - this concatenates 2 strings
 * @dest:  destination buffer
 * @src:  source buffer
 *
 * Return:returns  pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

