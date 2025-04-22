#include "main.h"

/**
 * execute_command - exécute une commande
 * @args: tableau contenant la commande
 * @program_name: nom du programme (argv[0])
 *
 * Return: 0 si OK, -1 sinon
 */
int execute_command(char **args, char *program_name)
{
	pid_t pid;
	int status;

	if (access(args[0], X_OK) != 0)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (-1);
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
