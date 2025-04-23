#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "main.h"

extern char **environ; // Déclaration de la variable globale contenant les variables d'environnement

/**
 * execute_command - Exécute une commande passée en arguments
 * @args: Tableau d'arguments (args[0] = commande, args[1..n] = options)
 * @program_name: Nom du programme (pour afficher les erreurs propres)
 *
 * Return: code de retour de la commande, ou 127 si non trouvée, ou 1 en cas d'erreur interne
 */
int execute_command(char **args, char *program_name)
{
    pid_t pid;
    int status;
    char *cmd_path = find_in_path(args[0]); 
    // Cherche où se trouve la commande dans les PATHs système (typiquement /bin, /usr/bin, etc.)

    if (!cmd_path || access(cmd_path, X_OK) != 0)
    {
        // Si la commande n'existe pas ou n'est pas exécutable
        fprintf(stderr, "%s: %s: not found\n", program_name, args[0]);
        if (cmd_path)
            free(cmd_path); // Toujours libérer la mémoire si elle a été allouée
        return (127); // 127 = convention pour "commande non trouvée" dans UNIX
    }
		
    pid = fork(); // On crée un nouveau processus
    if (pid == -1)
    {
        // fork a échoué
        perror("fork failed"); // Affiche l'erreur système
        free(cmd_path);
        return (1); // Erreur interne
    }

    if (pid == 0)
    {
        // Processus fils
        execve(cmd_path, args, environ); 
        // Remplace le processus courant par le nouveau programme
        // Si execve échoue, on continue ici (très important, sinon on ne sort jamais)
        
        fprintf(stderr, "%s: %s: not found\n", program_name, args[0]);
        free(cmd_path);
        exit(127); // Si execve échoue, on quitte proprement
    }
    else
    {
        // Processus parent
        wait(&status); // Attend que le fils termine
        // Important pour récupérer correctement le code de sortie et éviter des zombies
    }

    free(cmd_path); // Libère la mémoire même si tout s'est bien passé

    if (WIFEXITED(status))
        return (WEXITSTATUS(status)); // Récupère et retourne le code de sortie du fils
    else
        return (1); // Si le processus n'a pas terminé normalement (ex: tué par un signal)
}
