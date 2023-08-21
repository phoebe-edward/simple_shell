#include "main.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */

int compareStrings(const char *str1, const char *str2);

void executeCommand(char *cmd, char *args[]);

void token(char *command);
int main()
{
    char *input = NULL;
    size_t input_size = 0;
    ssize_t input_length;

    while (1)
    {
        write(STDOUT_FILENO, "hundle$ ", 8);

        input_length = getline(&input, &input_size, stdin);

        if (input_length == -1)
        {
            char error_msg[] = "getline error\n";
            write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
            break;
        }

        // Remove the newline character from the input
        if (input_length > 0 && input[input_length - 1] == '\n')
            input[input_length - 1] = '\0';

        if (compareStrings(input, "exit"))
        {
            char msg[] = "Exiting...\n";
            write(STDOUT_FILENO, msg, sizeof(msg) - 1);
            break;
        }

        token(input);
    }

    free(input); // Free memory allocated by getline
    return 0;
}

