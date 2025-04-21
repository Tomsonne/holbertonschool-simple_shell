#include "main.h"

extern char **environ;

char **split_line(char *line)
{
	char **tokens = malloc(64 * sizeof(char *));
	char *token;
	int i = 0;

	if (!tokens)
		return (NULL);

	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\r\n");
	} 

	tokens[i] = NULL;
	return tokens;
}


void shell_prompt(void)
{
	printf("#cisfun$ ");
}

int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (access(args[0], X_OK) != 0)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return -1;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return -1;
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return 0;
}
