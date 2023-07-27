#include "main.h"

char **create_tokens(char *str)
{
        char **tokens, *token;
        int max_tokens, count;
        const char *delim;

        max_tokens = _strlen(str);
        tokens = malloc(sizeof(char *) * (max_tokens + 1));
        delim = " ";
        count = 0;

        if (tokens == NULL)
                exit(-1);

        token = strtok(str, delim);

        while (token != NULL)
        {
                tokens[count] = token;
                count++;
                token = strtok(NULL, delim);
        }
        tokens[count] = NULL;

        return (tokens);
}
