#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
extern char **environ;
char *_getenv(char *name);
char *_strcspn(char *str);
int _strncmp(char *s1, char*s2, unsigned int n);
char *_strcat(char *dest, char *src);
int _check_slash(char *command);
char *_search_PATH(char *command);
char *_strdup(char *str);
#endif
