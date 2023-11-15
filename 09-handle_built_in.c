#include "shell.h"

/**
 *	is_built_in - if the command is builtin.
 *	@command: string.
 *	Return: 1 or 0.
*/

int is_built_in(char *command)
{
	char *builtins[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 *	handle_built_in - handling the builtin
 *	@command: array of strings.
 *	@argv: array of strings.
 *	@status: integer.
 *	@idx: integer.
 *	Return: void.
*/

void handle_built_in(char **command, char **argv, int *status, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, status, idx);
	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
 *	exit_shell - printing
 *	@command: array of strings.
 *	@argv: array of strings.
 *	@status: integer.
 *	@idx: integer.
 *	Return: void.
*/

void exit_shell(char **command, char **argv,  int *status, int idx)
{
	int exit_value = (*status);
	char *index, mssg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (_is_positif(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free2darr(command);
			(*status) = 2;
			return;
		}
	}
	free2darr(command);
	exit(exit_value);
}

/**
 *	print_env - printing environment
 *	@command: array of strings.
 *	@status: integer.
 *	Return: void.
*/


void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free2darr(command);
	(*status) = 0;
}
