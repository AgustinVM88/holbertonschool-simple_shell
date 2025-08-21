#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>	/* printf, perror */
#include <stdlib.h>	/* malloc, free, exit */
#include <unistd.h>	/* fork, execve */
#include <string.h>	/* strtok */
#include <sys/types.h>	/* pid_t */
#include <sys/wait.h>	/* wait */

void run_shell(void);
void execute_command(char *command);

#endif /* SHELL_H */
