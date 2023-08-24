#include "monty.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int len = 0;

	while (s1[len] == s2[len] && s1[len])
		len++;
	if (s1[len] > s2[len])
		return (1);
	if (s1[len] < s2[len])
		return (-1);
	return (0);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;
	while (src[len] != '\0')
		len++;
	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strtok - tokenize strings
 * @str: input string
 * @del: delimiters
 * Return: first token;
 */
char *_strtok(char *str, char *del)
{
	static char *tok;
	int i, j;

	i = j = 0;
	if (str == NULL)
		str = tok;
	while (str[i] != '\0')
	{
		if (char_search(del, str[i]) == 0 && str[i + 1] == '\0')
		{
			tok = str + i + 1;
			*tok = '\0';
			str = str + j;
			return (str);
		}
		else if (char_search(del, str[i]) == 0 && char_search(del, str[i + 1]) == 0)
			i++;
		else if (char_search(del, str[i]) == 0 && char_search(del, str[i + 1]) == 1)
		{
			tok = str + i + 1;
			*tok = '\0';
			tok++;
			str = str + j;
			return (str);
		}
		else if (char_search(del, str[i]) == 1)
			i++, j++;
	}
	return (NULL);
}
/**
 * char_search - determines if a particular char is in a string
 * @str: string
 * @c: char to find
 * Return: 1 if found
 */
int char_search(char *str, char c)
{
	int cnt = 0;

	while (str[cnt] != '\0')
	{
		if (str[cnt] == c)
			break;
		cnt++;
	}
	if (str[cnt] == c)
		return (1);
	else
		return (0);
}
