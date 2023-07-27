#include "main.h"

extern char **environ;

int _strlen(char *s);

int main(int argc, char **argv)
{
	char *lineptr;
	char *linecpy;
	size_t n;
	ssize_t charsread;
	char *cmd;
	char *prompt;

	(void)argc;
	n = 0;
	prompt = "$ ";
	lineptr = NULL;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		charsread = getline(&lineptr, &n, stdin);
		lineptr[_strcspn(lineptr, "\n")] = 0;
		if (charsread == -1)
		{
			free(lineptr);
			return (-1);
		}

		linecpy = malloc(sizeof(char) * _strlen(lineptr + 1));
		if (linecpy == NULL)
		{
			free(lineptr);
			return (-1);
		}
		linecpy = _strcpy(linecpy, lineptr);
		argv = create_tokens(lineptr);

		cmd = argv[0];

		if (_strcmp(cmd, "cd") == 0)
		{
			printf("cding...");
			chdir(argv[1]);
		}
		else if (_strcmp(cmd, "exit") == 10)
			break;
		else
		{
			execute_cmd(argv);
		}
		free(argv);
		free(linecpy);

	}
	free(lineptr);
	return (0);
}
