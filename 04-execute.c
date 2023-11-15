#include "shell.h"

/**
 *	_execute - execute the command.
 *	@idx: integer.
 *	@command: array of strings.
 *	@argv: array of strings.
 *	Return: integer.
*/

int _execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(argv[0], command[0], idx);
		free2darr(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free2darr(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free2darr(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
