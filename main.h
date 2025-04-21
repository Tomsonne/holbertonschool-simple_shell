#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **split_line(char *line);
int execute_command(char **args);
void shell_prompt(void);

#endif
