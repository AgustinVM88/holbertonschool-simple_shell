#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>	/* printf, perror */
#include <stdlib.h>	/* malloc, free, exit */
#include <unistd.h>	/* fork, execve */
#include <string.h>	/* strtok */
#include <sys/types.h>	/* pid_t */
#include <sys/wait.h>	/* wait */

extern char **environ;

void run_shell(void);
void execute_command(char *command);

#endif /* SIMPLE_SHELL_H */
