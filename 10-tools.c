#include "shell.h"

/**
 *	_is_positif - atoi helpful func.
 *	@str: string.
 *	Return: integer.
*/

int _is_positif(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 *	_atoi - simple atoi.
 *	@str: string.
 *	Return: integer.
*/

int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
