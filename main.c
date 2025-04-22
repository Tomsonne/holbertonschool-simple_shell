#include "main.h"

/**
 * main - point d'entrée du shell
 * @ac: nombre d'arguments
 * @av: tableau d'arguments
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	(void)ac;
	return (simple_shell(av[0]));
}
