#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
int _execute(char **command , char **argv, int idx);
void free2darr(char **arr);
char *_getenv(char *variable);
char* _getpath(char *command);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_strings(char *str, int len);
void print_env(char **command, int *status);
void exit_shell(char **command,char **argv,  int *status, int idx);
void handle_built_in(char **command ,char **argv, int *status, int idx);
int is_built_in(char *command);
int _atoi(char *str);
int _is_positif(char *str);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);




#endif