#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

/**
 * find_in_path - cherche une commande dans le PATH
 * @cmd: nom de la commande
 * Return: chemin complet (à free) si trouvé, NULL sinon
 */
char *find_in_path(char *cmd)
{
	char *path = getenv("PATH");
	char *dir, *path_copy, *full_path;
	size_t len;

	if (!path || strchr(cmd, '/'))
		return (strdup(cmd)); 

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		snprintf(full_path, len, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return full_path;
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
