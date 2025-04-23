#include "main.h"

/**
 * simple_shell - Boucle principale du shell (fonctionnement infini sauf si exit)
 * @program_name: Nom du programme (typiquement argv[0]) pour afficher les erreurs correctement
 *
 * Return: 0 (ne devrait jamais vraiment arriver sauf en sortie propre)
 */
int simple_shell(char *program_name)
{
    char *line = NULL;    // Pour stocker la ligne entrée par l'utilisateur
    size_t len = 0;       // Taille allouée pour getline (modifiée dynamiquement)
    char **args;          // Tableau de mots (arguments)
    int interactive = isatty(STDIN_FILENO); 
    // Vérifie si l'entrée est un terminal (mode interactif) ou un script

    while (1) // Boucle infinie du shell
    {
        if (interactive)
            shell_prompt(); // Affiche un prompt (ex: "$ ") seulement en mode interactif

        if (getline(&line, &len, stdin) == -1)
        {
            // getline lit l'entrée utilisateur (ligne entière)
            if (interactive)
                write(1, "\n", 1); // Remet une ligne propre si Ctrl+D
            break; // Sort du shell sur EOF ou erreur de lecture
        }

        args = split_line(line);
        // Découpe la ligne entrée en mots/commandes (ex: "ls -l" => {"ls", "-l", NULL})

        if (!args || !args[0])
        {
            // Ligne vide ou échec du split → on libère et recommence la boucle
            free(args);
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            // Si l'utilisateur tape "exit", on nettoie et on quitte
            free(args);
            free(line);
            exit(0);
        }

        else if (strcmp(args[0], "env") == 0)
        {
            // Si l'utilisateur tape "env", on affiche l'environnement
            executer_env();
            free(args);
            continue;
        }

        else
            execute_command(args, program_name);
            // Sinon, c'est une commande classique → on tente de l'exécuter

        free(args); // On libère les arguments à chaque tour
    }

    free(line); // Nettoie la mémoire de la ligne avant de quitter
    return (0);
}
