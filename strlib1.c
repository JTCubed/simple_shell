#include <stdbool.h>
#include "main.h"

static bool is_present(const char *str, char c)
{
	while (*str != '\0') {
		if (*str == c) {
			return true;
		}
		str++;
	}
	return false;
}

size_t _strcspn(const char *str1, const char *str2)
{
	size_t count = 0;

	while (*str1 != '\0') {
		if (is_present(str2, *str1)) {
			break;
		} else {
			count++;
			str1++;
		}
	}
	return count;
}


/**
 * _strdup - check the code for ALX School students.
 * @str: str
 * Return: Always 0.
 */


char *_strdup(char *str)
{
	int i, j;
	char *s;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	s = malloc((sizeof(char) * i) + 1);
	if (s == NULL)
		return (NULL);

	for (j = 0; str[j] != '\0'; j++)
	{
		s[j] = str[j];
	}
	s[j] = '\0';
	return (s);
}
