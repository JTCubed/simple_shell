#include "main.h"
#include <dirent.h>

extern char **environ;

char *_getenv(char *name)
{
        int l, i;
	l = _strlen(name);

        if (!environ || !name)
                return (NULL);
        while (environ[i])
        {
                if (strncmp(name, environ[i], l) == 0 && environ[i][l] == '=')
                        return (&environ[i][l + 1]);
                i++;
        }
        return (NULL);
}


char **_getdir()
{
        char **list;
        char *pathcpy, *path;

        path = _getenv("PATH");
	pathcpy = malloc((_strlen(path) + 1) * sizeof(char));
        pathcpy = _strcpy(pathcpy, path);

        if (path == NULL)
        {
                printf("PATH error");
                exit(-1);
        }


        if (pathcpy == NULL)
                exit(-1);

        list = create_tokens1(pathcpy);
	free(pathcpy);
        return (list);
}

/*char *_path()
{
        char **l;
        char *dir;
        int i;

        l = _getdir();
        for (i = 0; l[i] != NULL; i++)
        {
                if (strcmp("/bin", l[i]) == 0)
                {
                        dir = l[i];
                }
        }

        return (dir);
	}*/

char *_bin()
{
	int i;
	char *dir;
	char **ges;

	ges = _getdir();
	dir = malloc(sizeof(char) * 5);

	for (i = 0; ges[i] != NULL; i++)
	{
		if (_strcmp("/bin", ges[i]) == 10)
		{
			dir = ges[i];
		}
	}
	free(ges);
        return (dir);
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
		fprintf(stderr, "PATH environment variable not set\n");
		return NULL;
	}

	path_copy = strdup(path);
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
