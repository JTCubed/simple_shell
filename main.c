#include "main.h"

extern char **environ;

int _strlen(char *s);

int main(int argc, char **argv)
{
	char *lineptr;
	char *linecpy, *lncpy;
	size_t n;
	ssize_t charsread;
	char **argv2;
	char *prompt;
	int cd, i;

	(void)argc;
	n = 0;
	prompt = "$ ";
	lineptr = NULL;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		charsread = getline(&lineptr, &n, stdin);

		if (charsread == -1)
		{
			free(lineptr);
			return (-1);
		}


/*		linecpy = malloc(sizeof(char) * _strlen(lineptr + 1));
 		lncpy = malloc(sizeof(char) * _strlen(lineptr + 1));
*/		if (linecpy == NULL)
		{
			free(lineptr);
			return (-1);
		}

		linecpy = _strcpy(malloc(sizeof(char) * (_strlen(lineptr) + 1)), lineptr);
		lncpy = strdup(lineptr);
		lineptr[_strcspn(lineptr, "\n")] = 0;
		argv = create_tokens(lineptr);
		argv2 = create_tokens(lncpy);
		i = _strlen(argv2[1]);
		if (_strcmp(argv2[0], "cd") == 0)
		{
			printf("sding %s\n%d\n", argv2[1], i);
			cd = chdir(argv2[1]);
			if (cd == -1)
				printf("%s\n", strerror(errno));
		}
		else if (_strcmp(argv2[0], "exit") == 10)
		{
			free(argv2);
			free(argv);
			free(linecpy);
			free(lncpy);
			break;
		}
		else
		{
			execute_cmd(argv);
		}
		free(argv);
		free(linecpy);
		free(argv2);
		free(lncpy);

	}
	free(lineptr);
	return (0);
}
