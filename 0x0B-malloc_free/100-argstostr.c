#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the command-line arguments
 *
 * @ac: Number of command-line arguments
 * @av: Array of command-line argument strings
 *
 * Return: A pointer to the concatenated string
 */
char *argstostr(int ac, char **av)
{
	int i, n, r = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length of the concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
			l++;
	}
	l += ac; /* Add space for newline characters */

	/* Allocate memory for the concatenated string */
	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);

	/* Copy each character to the concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
		{
			str[r] = av[i][n];
			r++;
		}
		if (i < ac - 1)
		{
			str[r] = '\n'; /* Add newline character, except for the last line */
			r++;
		}
	}

	return (str);
}
