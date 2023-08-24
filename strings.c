#include "monty.h"

int _strcmp(char *s1, char *s2);
int _searchChar(char *s, char c);
char *_strtow(char *s, char *delim);

/**
 * _strcmp - Function that compares two strings.
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: 0 if equal otherwise unequal
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _searchChar - Search for character in string
 * @s: String
 * @c: Character to search
 *
 * Return: 1 if success 0 if not
 */
int _searchChar(char *s, char c)
{
	int count = 0;

	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			break;
		}
		count++;
	}
	if (s[count] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtow - Tokenize string
 * @s: String
 * @delim: Delimitors
 *
 * Return: tokenized string
 */
char *_strtow(char *s, char *delim)
{
	static char *token;
	int i = 0, j = 0;

	if (!s)
		s = token;
	while (s[i] != '\0')
	{
		if (_searchChar(delim, s[i]) == 0 && s[i + 1] == '\0')
		{
			token = s + i + 1;
			*token = '\0';
			s = s + j;
			return (s);
		}
		else if (_searchChar(delim, s[i]) == 0 && _searchChar(delim, s[i + 1]) == 0)
			i++;
		else if (_searchChar(delim, s[i]) == 0 && _searchChar(delim, s[i + 1]) == 1)
		{
			token = s + i + 1;
			*token = '\0';
			token++;
			s = s + j;
			return (s);
		}
		else if (_searchChar(delim, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
