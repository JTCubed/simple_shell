#include "main.h"

int _strlen(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; i++)
                ;

        return (i);
}

char *_strcpy(char *dest, char *src)
{
        int len = _strlen(src);
        int i;

        for (i = 0; i < len; i++)
        {
                dest[i] = src[i];
        }
        dest[i] = '\0';

        return(dest);
}


int _strncmp(char *dest, char *src, int n)
{

        while (n--)
        {
                if (src == dest)
                        return (0);
                else if(src < dest)
                        return (-1);
                else
                        return (1);

                dest++;
                src++;
        }
        return (0);
}

int _strcmp(char *str1, char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}


char *_strcat(char *dest, char *src)
{
	int destlen = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[destlen + i] = src[i];
	}
	dest[destlen + i] = '\0';
	return (dest);
}
