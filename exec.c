#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "main.h"

extern char **environ;

int execute_command(char **args, char *program_name)
{
	pid_t pid;
	int status;
	char *cmd_path = find_in_path(args[0]);

	if (!cmd_path || access(cmd_path, X_OK) != 0)
	{
		fprintf(stderr, "%s: %s: not found\n", program_name, args[0]);
		if (cmd_path)
			free(cmd_path);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		free(cmd_path);
		return (1);
	}

	if (pid == 0)
	{
		execve(cmd_path, args, environ);
		fprintf(stderr, "%s: %s: not found\n", program_name, args[0]);
		free(cmd_path);
		exit(127);
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (1);
}
