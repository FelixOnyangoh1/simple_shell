#include "shell.h"

/**
 * **strtow - seperate a str into words. delimiters- ignored
 * @str: in-put str
 * @d: deli-meter str
 * Return: ptr to arr of strs. void on failing
 */

char **strtow(char *str, char *d)
{
	int a, b, c, d, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		e = " ";
	for (i = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], e) && (is_delim(str[a + 1], e) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[a], e))
			a++;
		k = 0;
		while (!is_delim(str[a + k], e) && str[a + k])
			k++;
		s[a] = malloc((k + 1) * sizeof(char));
		if (!s[b])
		{
			for (k = 0; k < b; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[a++];
		s[j][m] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * **strtow2 - seperate str into words
 * @str: in-put str
 * @d:  deli-meter
 * Return: ptr to an arr of strs, void on failing
 */
char **strtow2(char *str, char e)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

