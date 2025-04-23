#ifndef MAIN_H
#define MAIN_H

#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char *find_in_path(char *cmd);
int simple_shell(char *program_name);
char **split_line(char *line);
int execute_command(char **args, char *program_name);
void shell_prompt(void);
void executer_env(void);


/** 
 * int _setenv(const char *nom, const char *valeur, int ecraser);
int _unsetenv(const char *nom);
 * 
void executer_setenv(char **arguments);
void executer_unsetenv(char **arguments);*/


#endif
