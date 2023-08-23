#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void display_prompt() {
    printf("#cisfun$ ");
}

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == 0) {
        
        execlp(command, command, (char *)NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
       
        waitpid(pid, NULL, 0);
    }
}

