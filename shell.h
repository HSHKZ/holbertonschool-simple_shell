#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void prompt(void);
char *read_input(void);
char **parse_command(char *command);
void execute_command(char **args);
char *find_command_in_path(char *command);
void print_env(void);
void change_directory(char **args);

extern char **environ;

#endif
