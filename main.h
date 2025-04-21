#ifndef MAIN_H
#define MAIN_H

/* Librairies système */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Fonctions du shell */
int simple_shell(char *program_name);
char **split_line(char *line);
int execute_command(char **args, char *program_name);
void shell_prompt(void);

#endif
