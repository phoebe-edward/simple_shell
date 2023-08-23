#include "main.h"
/**
 * main - Entry point of the simple shell.
 *
 * Return: Always 0.
 */
int main(void) {
    while (1) {
        char prompt[] = "$ ";
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
        char *input = custom_getline();

        if (input == NULL)
            break;

        // Process the input here

        free(input);
    }

    return 0;
}
