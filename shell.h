#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int prompt(void);
void task_0(void);
int task_1(char **argv);
char *_strcspn(char *str);
#endif
