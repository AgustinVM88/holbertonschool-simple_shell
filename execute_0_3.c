#include "simple_shell_2.h"

/**
 * execute_command - Ejecuta un comando usando fork y execvp
 *
 * @args: array a punteros a cadenas(args[0] = comando,
 * args[1..n] = argumentos, args[n] = NULL)
 *
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *path, *path_copy, *dir, full_path[1024];

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	
	if (pid == 0)
	{
		/* Si el comando contiene '/', lo ejecuta directamente */
		if (strchr(args[0], '/'))
		{
			execve(args[0], args, environ);
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(127);
		}
		/* Caso contrario, buscar en $PATH */
		path = getenv("PATH");

		if (path)
		{
			path_copy = strdup(path);
			dir = strtok(path_copy, ":");
			
			while (dir)
			{
				snprintf(full_path, sizeof(full_path), "%s/%s", dir, args[0]);
				execve(full_path, args, environ);
				dir = strtok(NULL, ":");
			}
			free(path_copy);
		}
		/* Si no se encontro */
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
