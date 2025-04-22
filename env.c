#include "main.h"

/**
 * _setenv - Ajoute ou modifie une variable d’environnement
 * @nom: Nom de la variable.
 * @valeur: Valeur
 * @ecraser: 1 = écraser si existe, 0 = ne rien faire si existe
 * Return: 0 si succès, -1 sinon.
 */
int _setenv(const char *nom, const char *valeur, int ecraser)
{
	if (!nom || !valeur)
		return (-1);

	if (!ecraser && getenv(nom))
		return (0);

	return (setenv(nom, valeur, 1));
}

/**
 * _unsetenv - Supprime une variable d’environnement
 * @nom: Nom de la variable à supprimer
 * Return: 0 si succès, -1 sinon
 */
int _unsetenv(const char *nom)
{
	if (!nom)
		return (-1);

	return (unsetenv(nom));
}

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
 * executer_setenv - Gère la commande setenv
 * @arguments: arguments[1] = nom, arguments[2] = valeur
 */
void executer_setenv(char **arguments)
{
	if (arguments[1] && arguments[2])
	{
		if (_setenv(arguments[1], arguments[2], 1) != 0)
			perror("Erreur setenv");
	}
	else
	fprintf(stderr, "Usage : setenv NOM VALEUR\n");
}

/**
 * executer_unsetenv - Gère la commande unsetenv
 * @arguments: arguments[1] = nom
 */
void executer_unsetenv(char **arguments)
{
	if (arguments[1])
	{
		if (_unsetenv(arguments[1]) != 0)
			perror("Erreur unsetenv");
	}
	else
	fprintf(stderr, "Usage : unsetenv NOM\n");
}
