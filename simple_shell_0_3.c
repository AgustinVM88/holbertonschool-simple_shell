#include "simple_shell_2.h"

#define MAX_IMPUT 1024 /* Maximo tamano del comando */

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
	char *token;
	char *args[64];   /* Array para comando y argumentos*/
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("$ ");
		

		/* Lee linea de comando */
		read = getline(&line, &len, stdin);

		/* (Ctrl+D) */
		if (read == -1)
		{
			free(line);
			exit(0);
		}
		/* Eliminar el salto de linea al final de la entrada */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Tokenizar la linea en args[] */
		i = 0;
		token = strtok(line, " ");
		
		while(token != NULL && i < 63)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL; /* Termina con NULL(requisito de execve) */

		if (args[0] != NULL) 
			execute_command(args);
	}
}
