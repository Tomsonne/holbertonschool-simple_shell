#include "main.h"

/**
 * split_line - découpe une ligne de commande en mots
 * @line: la ligne entrée par l'utilisateur
 *
 * Return: tableau de mots terminé par NULL
 */
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
	return (tokens);
}
