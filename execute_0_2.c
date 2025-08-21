#include "simple_shell_3.h"

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

	/* Si el comando contiene '/' probarlo directamente */
	if (strchr(args[0]. '/'))
	{
		if (access(args[0], X_OK) == 0) /* Existe y es ejecutable */
		{
			pid = fork();
			if (pid == 0)
			{
				execve(args[0], args, environ);
				perror("execve"); /* Solo si falla*/
				exit(127);
			}
			else if (pid > 0)
				waitpid(pid, &status, 0);
			else
				perror("fork");
		}
		else
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);

		return;
	}
	/* Busca en PATH si no contiene '/' */
	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		dir = strtok(path_copy, ":");

		while (dir)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", dir, args[0]);
			if (access(full_path, X_OK) == 0) /* Encontradp */
			{
				pid = fork();

				if (pid == 0)
				{
					execve(full_path, args, environ);
					perror("execve");
					exit(127);
				}
				else if (pid > 0)
					waitpid(pid, &status, 0);
				else
					perror("fork");

				free(path_copy);
				return; /* Ejecutado */
			}
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	/* Si no existe */
	fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
}
