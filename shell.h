#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
void task_0(void);
int task_1(char **argv);
int _fork_fcn(char *line, char **args, int status, char **argv);
char *_strcspn(char *str);
#endif
