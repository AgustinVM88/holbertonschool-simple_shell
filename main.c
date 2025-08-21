#include "shell.h"

/**
 * main - Punto de entrada de la shell
 *
 * @argc: numero de argumentos(no usado aqui)
 * @argv: arreglo de argumentos(no usado aqui)
 *
 * Return: 0 en exito
 */
int main(int argc, char **argv)
{
	(void)argc; /* Evitan el warning de "unused parameter"*/
	(void)argv;

	run_shell(); /* Ejecuta la shell */
	return (0);
}
