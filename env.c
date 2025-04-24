#include "main.h"


/**
 * executer_env - Affiche les variables d’environnement
 */
void executer_env(void)
{
int i;

for (i = 0; environ[i]; i++)
	printf("%s\n", environ[i]);
}


/**
 * _getenv - Recherche une variable d'environnement manuellement
 * @name: Le nom de la variable recherchée
 *
 * Return: Un pointeur vers la valeur associée, ou NULL si pas trouvée.
 */
char *_getenv(const char *name)
{
int i;
size_t len;

if (!name || !*name)
	return (NULL);

len = strlen(name);

for (i = 0; environ[i]; i++)
{
	if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		return (&environ[i][len + 1]);
}
return (NULL);
}

