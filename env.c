#include "main.h" // Inclusion de ton header personnel, probablement où tu as les prototypes de fonctions

/**
 * _setenv - Ajoute ou modifie une variable d’environnement
 * @nom: Nom de la variable.
 * @valeur: Valeur de la variable.
 * @ecraser: Si 1 => écraser la variable si elle existe déjà, sinon ne rien faire.
 * Return: 0 si succès, -1 en cas d'erreur (paramètre invalide).
 */
int _setenv(const char *nom, const char *valeur, int ecraser)
{
    if (!nom || !valeur)
        return (-1); // Vérifie que nom et valeur ne sont pas NULL (sécurité de base)

    if (!ecraser && _getenv(nom))
        return (0); // Si on ne veut pas écraser ET que la variable existe déjà, on quitte sans rien faire

    return (setenv(nom, valeur, 1)); 
    // Sinon, on utilise setenv du système pour (ré)ajouter la variable.
    // Remarque : on force ecrasement à 1 ici, ce qui est correct car le contrôle est fait juste avant.
}

/**
 * _unsetenv - Supprime une variable d’environnement
 * @nom: Nom de la variable à supprimer.
 * Return: 0 si succès, -1 en cas d'erreur.
 */
int _unsetenv(const char *nom)
{
    if (!nom)
        return (-1); // Toujours vérifier les arguments pour éviter un comportement imprévisible.

    return (unsetenv(nom)); // Utilisation directe de la fonction système unsetenv
}

/**
 * executer_env - Affiche toutes les variables d’environnement
 */
void executer_env(void)
{
    int i;

    for (i = 0; environ[i]; i++)
        printf("%s\n", environ[i]); // Parcourt tout le tableau environ et affiche chaque variable
    // Remarque : environ est une variable globale qui contient les variables d'environnement sous forme de tableau de chaînes
}

/**
 * executer_setenv - Traite la commande "setenv" (depuis un shell par ex.)
 * @arguments: arguments[1] = nom, arguments[2] = valeur
 */
void executer_setenv(char **arguments)
{
    if (arguments[1] && arguments[2])
    {
        if (_setenv(arguments[1], arguments[2], 1) != 0)
            perror("Erreur setenv"); // Affiche une erreur système si setenv échoue
    }
    else
        fprintf(stderr, "Usage : setenv NOM VALEUR\n"); 
        // Message d'erreur si l'utilisateur ne fournit pas assez d'arguments
}

/**
 * executer_unsetenv - Traite la commande "unsetenv"
 * @arguments: arguments[1] = nom
 */
void executer_unsetenv(char **arguments)
{
    if (arguments[1])
    {
        if (_unsetenv(arguments[1]) != 0)
            perror("Erreur unsetenv"); // Affiche une erreur système en cas d'échec
    }
    else
        fprintf(stderr, "Usage : unsetenv NOM\n"); 
        // Message d'aide si l'utilisateur oublie de donner un nom
}

/**
 * _getenv - Recherche manuellement une variable d'environnement
 * @name: Nom de la variable recherchée
 * Return: Un pointeur vers la valeur si trouvée, NULL sinon.
 */
char *_getenv(const char *name)
{
    int i;
    size_t len;

    if (!name || !*name)
        return (NULL); // Vérifie que le nom n'est pas NULL ou vide

    len = strlen(name); // On stocke la longueur pour éviter de la recalculer dans la boucle

    for (i = 0; environ[i]; i++)
    {
        // strncmp compare seulement les 'len' premiers caractères
        // On vérifie aussi que juste après le nom, il y a un '=' pour être sûr que c'est un match exact
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return (&environ[i][len + 1]); 
            // Retourne un pointeur vers la valeur (après le '=')
    }
    return (NULL); // Retourne NULL si pas trouvé
}
