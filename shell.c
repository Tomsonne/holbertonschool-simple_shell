#include "main.h"

/**
 * simple_shell - boucle principale du shell
 * @program_name: nom du programme (argv[0])
 *
 * Return: 0
 */
int simple_shell(char *program_name)
{
	char *line = NULL;
	size_t len = 0;
	char **args;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			shell_prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			if (interactive)
				write(1, "\n", 1);
			break;
		}
		args = split_line(line);
		if (!args || !args[0])
		{
			free(args);
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			free(args);
			break;
		}
		else if (strcmp(args[0], "env") == 0)
		{
			executer_env();
			free(args);
			continue;
		}
		else
		execute_command(args, program_name);
		free(args);
	}
	free(line);
	return (0);
}
