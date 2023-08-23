<<<<<<< HEAD
#ifndef SHELL_H
#define SHELL_H
=======
#ifndef MAIN_H
#define MAIN_H
>>>>>>> 349e35e52b353a65ad97a50dce47a88438c87420
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
<<<<<<< HEAD
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
extern char **environ;
char *_getenv(char *name);
char *_strcspn(char *str);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strcat(char *dest, char *src);
int _check_slash(char *command);
char *_search_PATH(char *command);
char *_strdup(char *str);
=======
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024

// Function declarations
void display_prompt();
void execute_command(char *command);

>>>>>>> 349e35e52b353a65ad97a50dce47a88438c87420
#endif
