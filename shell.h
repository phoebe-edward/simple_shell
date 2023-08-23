#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
<<<<<<< HEAD
int prompt(void);
=======
extern char **environ;
>>>>>>> 061d962d6608d6d42265c450f95b61d2c905eb8d
void task_0(void);
int task_1(char **argv);
int _fork_fcn(char *line, char **args, int status, char **argv);
char *_strcspn(char *str);
#endif
