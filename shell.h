#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

/* Utility functions */
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

#endif /* SHELL_H */
