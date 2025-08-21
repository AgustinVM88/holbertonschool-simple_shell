#include "shell.h"

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

	if (isatty(STDIN_FILENO)) /* Modo interactivo */
	{
		while (1)
		{
			printf("$ "); /* Mostrar prompt */

			/* Leer la linea de entrada */
			read = getline(&line, &len, stdin);

			/* Si getline devuelve -1 => EOF(Ctrl+D) o error */
			if (read == -1)
			{
				free(line);
				break;
			}
			/* Elimina el salto de linea final si existe */
			line[strcspn(line, "\n")] = '\0';

			/* Solo ejecuta si no esta vacio */
			if (strlen(line) > 0)
				execute_command(line);
			
		}
	}
	else /* Modo no interactivo */
	{
		while ((read = getline(&line, &len, stdin)) != -1)
		{
			line[strcspn(line, "\n")] = '\0';
			if (strlen(line) > 0)
				execute_command(line);
		}
		free(line);
	}
}
