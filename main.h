#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stddef.h>

int main(int argc, char *argv[]);
//int main();
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void _puts(char *str);
char **create_tokens(char *str);
char **create_tokens1(char *str);
char *_getenv(char *name);
char *_getdir();
int _strcmp(char *str1, char *str2);
char *_path();
int _strcmp(char *s1, char *s2);
int _isdir(char *name);
char *_strcat(char *dest, char *src);
char *_bin();
void execute_cmd(char **args);
char* find_in_path(char* command);
size_t _strcspn(const char *str1, const char *str2);
char *_strdup(char *str);
int _strncmp(char *dest, char *src, int n);
#endif
