#include <stdio.h>
#include <stdlib.h>

// Maximum number of environment variables
#define MAX_ENV_VARS 100

// Function to implement the "env" command
void execute_env(char **envp) {
    for (int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }
}

int main(int argc, char *argv[], char *envp[]) {
    char *command;

    while (1) {
        printf("$ ");
        // Assuming you have a function to read user input and tokenize it into command and arguments
        command = read_input();

        // Check if the command is "env"
        if (strcmp(command, "env") == 0) {
            execute_env(envp);
        } else if (strcmp(command, "exit") == 0) {
            // Assuming you have an exit function to terminate the shell
            exit_shell();
        } else {
            // Handle other commands using execve() and fork()
            // ...

            // Print an error message for unsupported commands
            printf("Command not found: %s\n", command);
        }

        // Free memory allocated for command
        free(command);
    }

    return 0;
}
