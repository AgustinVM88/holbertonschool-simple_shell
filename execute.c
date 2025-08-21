#include "shell.h"

/**
 * execute_command - Ejecuta un comando usando fork y execvp
 *
 * @command: el comando a ejecutar(ej: "ls")
 *
 */
void execute_command(char *command)
{
	pid_t pid; /* pid_t = entero para guardar el ID de proceso */
	char *argv[2]; /* Arreglo de punteros a cadenas (argv[0] = comando) */

	argv[0] = command; /* Guarda el comando en argv[0] */
	argv[1] = NULL; /*  Termina el arreglo con NULL */

	pid = fork(); /* Crea proceso hijo */

	if (pid == -1)
	{
		perror("Error al crear proceso");
		return;
	}
	else if (pid == 0)
	{
		/* Proceso hijo: intentamos ejecutar el comando */
		execvp(argv[0], argv);

		/* Si execvp falla, mostramos error y salimos del hijo */
		perror("Error en execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Proceso padre: espera a que el hijo termine */
		wait(NULL);
	}
}
