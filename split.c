#include "main.h"

/**
 * split_line - Découpe une ligne de commande en plusieurs mots (arguments)
 * @line: La ligne entrée par l'utilisateur (ex: "ls -l /home")
 *
 * Return: Tableau de pointeurs vers chaque mot (terminé par NULL),
 *         ou NULL si erreur d'allocation.
 */
char **split_line(char *line)
{
    char **tokens = malloc(64 * sizeof(char *)); 
    // On prévoit un tableau capable de stocker jusqu'à 64 mots (pointeurs vers char*)
    char *token;
    int i = 0;

    if (!tokens)
        return (NULL); // Vérification de l'allocation mémoire

    token = strtok(line, " \t\r\n"); 
    // strtok coupe la ligne au premier espace, tabulation, retour chariot ou saut de ligne

    while (token != NULL)
    {
        tokens[i++] = token; // On stocke le pointeur vers le mot extrait
        token = strtok(NULL, " \t\r\n"); // strtok continue à couper à chaque appel
    }

    tokens[i] = NULL; // Toujours terminer un tableau de pointeurs par NULL pour execve et autres
    return (tokens);
}
