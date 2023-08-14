#include "main.h"
#include <dirent.h>

extern char **environ;

char *_getenv(char *name)
{
        int l, i = 0;
	l = _strlen(name);

        if (!environ || !name)
                return (NULL);
        while (environ[i])
        {
                if (_strncmp(name, environ[i], l) == 0 && environ[i][l] == '=')
                        return (&environ[i][l + 1]);
                i++;
        }
        return (NULL);
}


char *_getdir()
{

        char *pathcpy, *path;

        path = _getenv("PATH");
	pathcpy = malloc((_strlen(path) + 1) * sizeof(char));
        pathcpy = _strcpy(pathcpy, path);

        if (path == NULL)
        {
                perror("PATH error");
                exit(1);
        }


        if (pathcpy == NULL)
                exit(-1);

	free(pathcpy);

	return(pathcpy);
}


char* find_in_path(char* command)
{
	char* path;
	char* path_copy;
	char* dir;
	DIR* dirp;
	struct dirent * dp;

	path = _getenv("PATH");
	if (path == NULL)
	{
		perror("PATH environment variable not set\n");
		return NULL;
	}

	path_copy = _strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		dirp = opendir(dir);
		if (dirp == NULL)
		{
			perror("opendir failed");
			continue;
		}


		while ((dp = readdir(dirp)) != NULL)
		{
			if (dp == NULL)
			{
				perror("readdir failed");
				break;
			}
			if (strcmp(dp->d_name, command) == 0)
			{
				char* full_path = malloc(_strlen(dir) + strlen(command) + 2);
				_strcpy(full_path, dir);
				_strcat(full_path, "/");
				_strcat(full_path, command);
				free(path_copy);
				closedir(dirp);
				return full_path;
			}
		}
		closedir(dirp);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
