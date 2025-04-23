# 🐚 simple_shell

```
     ____  _                 _      ____  _          _ _
    / ___|| |__   ___   ___ | | __ / ___|| |__   ___| | |
    \___ \| '_ \ / _ \ / _ \| |/ / \___ \| '_ \ / _ \ | |
     ___) | | | | (_) | (_) |   <   ___) | | | |  __/ | |
    |____/|_| |_|\___/ \___/|_|\_\ |____/|_| |_|\___|_|_|
```

[![Build](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/hagguishel/holbertonschool-simple_shell)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Shell](https://img.shields.io/badge/made%20with-C89-orange.svg)](https://en.wikipedia.org/wiki/C89)

---

## 📖 Description

**`simple_shell`** est une implémentation simple d’un shell Unix en C développée dans le cadre du programme **Holberton School**.  
Il permet l'exécution de commandes, la gestion des variables d'environnement, et prend en charge les modes interactif et non-interactif.

---

## 🚀 Features

- 🔹 Exécution de commandes Unix classiques (`ls`, `pwd`, etc.)
- 🔹 Recherche automatique dans le `PATH`
- 🔹 Support du mode interactif (avec prompt `#cisfun$`)
- 🔹 Mode non-interactif via redirection ou pipe
- 🔹 Commandes internes :
  - `exit` : quitte le shell
  - `env` : affiche les variables d'environnement
  - `setenv` : ajoute ou modifie une variable
  - `unsetenv` : supprime une variable
- 🔹 Gestion d’erreurs : code retour `127` si commande non trouvée

---

## 📦 Requirements

- OS : **Ubuntu 20.04 LTS**
- Compiler : **GCC**
- Flags :
  ```bash
  -Wall -Werror -Wextra -pedantic -std=gnu89
  ```

---

## ⚙️ Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## 💡 Usage

### Mode interactif
```bash
./hsh
#cisfun$ ls
```

### Mode non-interactif
```bash
echo "ls -l" | ./hsh
```

### Quitter le shell
```bash
#cisfun$ exit
```

---

## 🗃️ File Structure

| Fichier     | Description                                  |
|-------------|----------------------------------------------|
| `main.c`    | Entrée principale du programme               |
| `shell.c`   | Boucle principale du shell                   |
| `exec.c`    | Exécution de commandes (`fork`, `execve`)    |
| `env.c`     | Gestion de `env`, `setenv`, `unsetenv`       |
| `split.c`   | Découpe la ligne utilisateur en arguments    |
| `path.c`    | Recherche de la commande dans `$PATH`        |
| `utils.c`   | Affiche le prompt                            |
| `main.h`    | Fichier d'en-tête global                     |

---

## 🔍 Examples

```bash
#cisfun$ ls
README.md  main.c  shell.c  ...

#cisfun$ /bin/echo Hello World
Hello World

#cisfun$ command404
./hsh: command404: not found
```

---

## 📙 Man Page

Si tu ajoutes une page man, elle est consultable avec :
```bash
man ./man_1_simple_shell
```

---

## 🧪 Testing

### Test simple
```bash
echo "ls -l" | ./hsh
```

### Test mémoire avec Valgrind
```bash
valgrind --leak-check=full ./hsh
```

Sortie attendue :
```
== All heap blocks were freed -- no leaks are possible
```

---

## ⚠️ Limitations

- ❌ Pas de support des redirections `>`, `<` ou pipes `|`
- ❌ Pas d'historique ou de complétion automatique
- ❌ Pas de commandes multiples (`;`, `&&`, `||`)
- ❌ Pas de parsing avancé ou gestion de quotes

---

## 🧑‍💼 Authors

- **RAZAFIMAITSO Haggui**  
  [@hagguishel](https://github.com/hagguishel)

- **ROUSSEAU Thomas**  
  [@Tomsonne](https://github.com/Tomsonne)

---

## 🪪 License

Ce projet est sous licence **MIT**. Voir le fichier `LICENSE` pour plus de détails.

---

> Made with ❤️ at Holberton School

