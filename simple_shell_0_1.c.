#include "simple_shell.h"

/**
 * run_shell - Bucle principal de la shell
 *
 * Lee la entrada del usuario o de un pipe(modo interactivo o no)
 * Muestra un promt "$ " solo en modo interactivo
 * Llama a execute_command() para ejecutar los comandos
 */
void run_shell(void)
{
	char *line = NULL; /* Puntero donde guardara la linea leida */
	size_t len = 0;    /* Tamano asignado por getline */
	ssize_t read;      /* Numero de caracteres leidos */

	while (1)
	{
		/* Modo interactivo */
		if (isatty(STDIN_FILENO))
			printf("$ ");

		/* Lee entrada del usuario */
		read = getline(&line, &len, stdin);

		/* Si getline devuelve -1 => EOF (Ctrl+D) o error */
		if (read == -1)
		{
			free(line);
			break;
		}
		/* Eliminar el salto de linea al final de la entrada */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Si el usuario no escribe nada, continuar */
		if (line[0] == '\0')
			continue;

		/* Ejecuta el comando escrito */
		execute_command(line);
	}
}
