#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#define MAX_ARGS 10

/* Declare the environment variables manually */
extern char **environ;

#define MAX_COMMAND_LENGTH 100
int Hundle(void);
int prompt(void);
int Path(void);
/* put task number 4 here */
int enve(void);
int string_equal(const char *s1, const char *s2);
char *custom_getline(void);
//void write_string(int fd, const char *str)

#endif
