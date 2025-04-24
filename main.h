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
char *trouver_path(char *cmd);
int simple_shell(char *program_name);
char **decouper_ligne(char *line);
int executer_commande(char **args, char *program_name);
void shell_prompt(void);
void executer_env(void);
char *_getenv(const char *name);

#endif
