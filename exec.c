#include "main.h"

extern char **environ;

void execute_cmd(char **args)
{
	pid_t pid;
	char *full_path;
	if (args[0] == NULL)
	{
		return;
	}



	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (args[0][0] == '/')
			execve(args[0], args, environ);
		else
		{
			full_path = find_in_path(args[0]);
			if (full_path != NULL)
			{
				if (execve(full_path, args, environ) == -1)
					perror("failed to execute");
				free(full_path);
			}
		}
		perror("Command execution failed");
		exit(EXIT_FAILURE);
	} else
	{
		int status;
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
/**			printf("Child exited with status: %d\n", exit_status);
 */		}
	}
}
