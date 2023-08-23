#include "shell.h"
int main() {
    char input[BUFFER_SIZE];

    while (1) {
        display_prompt();
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
 
            printf("\n");
            break;
        }
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue;
        }

        execute_command(input);
    }

    return (0);
}
