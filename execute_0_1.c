#include "simple_shell.h"

/**
 * execute_command - Ejecuta un comando usando fork y execvp
 *
 * @command: el comando a ejecutar(ej: "ls")
 *
 */
void execute_command(char *command)
{
	pid_t pid; /* ID de proceso hijo */
	int status; /* Estado de finalizacion del hijo */
	char *argv[2]; /* Arreglo de punteros a cadenas (argv[0] = comando) */

	argv[0] = command; /* Guarda el comando en argv[0] */
	argv[1] = NULL; /*  Termina el arreglo con NULL */

	pid = fork(); /* Crea proceso hijo */

	if (pid == -1)
	{
		perror("Error al crear proceso");
		return;
	}
	
	if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			/* Si no encuentra comando, imprime mensaje standar*/
			fprintf(stderr, "./hsh: 1: %s: not found\n", command);
			exit(127);
		}
	}
	else
	{
		/* Proceso padre: espera a que el hijo termine */
		waitpid(pid, &status, 0);
	}
}
