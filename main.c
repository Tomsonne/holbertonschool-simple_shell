#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char **args;

	while (1)
	{
		shell_prompt();

		if (getline(&line, &len, stdin) == -1)
		{
			printf("\n");
			break;
		}

		args = split_line(line);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			free(args);
			break;
		}

		execute_command(args);
		free(args);
	}

	free(line);
	return 0;
}
