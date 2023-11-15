#include "shell.h"

/**
 * main - simple shell main fonction
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **argv)
{
    char *line = NULL, **command = NULL;
    int status = 0, idx =0;
    (void) ac;
    (void) argv;

    while (1)
    {
        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDOUT_FILENO))
                write(STDOUT_FILENO, "\n", 1 );
            return (status);
        }
        idx++;
        command = tokenizer(line);
        if (!command)
            continue;
        if (is_built_in(command[0]))
            handle_built_in(command,argv, &status, idx );
        else
        status = _execute (command , argv, idx);
    }
    
}