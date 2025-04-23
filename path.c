#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

/**
 * trouver_path - cherche une commande dans le PATH
 * @cmd: nom de la commande
 * Return: chemin complet (à free) si trouvé, NULL sinon
 */
char *trouver_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *rep, *copie_path, *path_entier;
	size_t len;

	if (!path || strchr(cmd, '/'))
		return (strdup(cmd)); 

	copie_path = strdup(path);
	if (!copie_path)
		return (NULL);

	rep = strtok(copie_path, ":");
	while (rep)
	{
		len = strlen(rep) + strlen(cmd) + 2;
		path_entier = malloc(len);
		if (!path_entier)
		{
			free(copie_path);
			return (NULL);
		}
		snprintf(path_entier, len, "%s/%s", rep, cmd);
		if (access(path_entier, X_OK) == 0)
		{
			free(copie_path);
			return path_entier;
		}
		free(path_entier);
		rep = strtok(NULL, ":");
	}
	free(copie_path);
	return (NULL);
}
