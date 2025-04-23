#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

/**
 * find_in_path - Cherche une commande dans les répertoires listés dans PATH
 * @cmd: Nom de la commande à rechercher (ex: "ls")
 * 
 * Return: Chemin complet de la commande (à free() par l'appelant), ou NULL si non trouvé.
 */
char *find_in_path(char *cmd)
{
    char *path = _getenv("PATH"); 
    // Récupère la valeur de PATH via ta fonction _getenv
    char *dir, *path_copy, *full_path;
    size_t len;

    if (!path || strchr(cmd, '/'))
        return (strdup(cmd)); 
        /* 
         - Si PATH est introuvable, ou si cmd contient déjà un '/',
           on considère que c'est déjà un chemin absolu ou relatif.
         - strdup() pour retourner une copie car il faudra le free plus tard.
        */

    path_copy = strdup(path); // Crée une copie modifiable de PATH pour strtok
    if (!path_copy)
        return (NULL); // Problème d'allocation mémoire

    dir = strtok(path_copy, ":"); 
    // strtok divise path_copy en "morceaux" séparés par ":"
    while (dir)
    {
        len = strlen(dir) + strlen(cmd) + 2; 
        // +2 pour '/' et '\0' final
        
        full_path = malloc(len);
        if (!full_path)
        {
            free(path_copy);
            return (NULL); // Problème d'allocation mémoire
        }

        snprintf(full_path, len, "%s/%s", dir, cmd); 
        // Construit le chemin complet (ex: "/bin/ls")

        if (access(full_path, X_OK) == 0)
        {
            // Si le fichier existe et est exécutable
            free(path_copy);
            return full_path; // On retourne le chemin trouvé
        }
        
        free(full_path); // Sinon, on libère la tentative actuelle
        dir = strtok(NULL, ":"); // Passe au prochain répertoire
    }

    free(path_copy); // Important : éviter fuite mémoire
    return (NULL); // Si pas trouvé dans aucun répertoire
}
