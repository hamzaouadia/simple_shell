#include "shell.h"

/**
 *	free2darr - freeing a two dementions array.
 *	@arr: array of strings.
 *	Return: void.
*/

void free2darr(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

/**
 *	printerror - printing errors.
 *	@name: string.
 *	@cmd: string.
 *	@idx: integer.
 *	Return: void.
*/

void printerror(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}

/**
 *	_itoa - returning integer to string.
 *	@n: integer.
 *	Return: string.
*/

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_strings(buffer, i);
	return (_strdup(buffer));
}

/**
 *	reverse_strings - reversing the string.
 *	@str: string.
 *	@len: integer.
 *	Return: void.
*/

void reverse_strings(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
