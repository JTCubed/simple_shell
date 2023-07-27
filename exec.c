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
			printf("%s\n", full_path);
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
		waitpid(pid, NULL, 0);
	}
}
