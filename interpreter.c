#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1000

typedef struct {
    int stack[STACK_SIZE];
    int top;
} MontyStack;

MontyStack montyStack;

void push(int value) {
    if (montyStack.top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Stack overflow\n", montyStack.top + 1);
        exit(EXIT_FAILURE);
    }
    montyStack.stack[++montyStack.top] = value;
}

void pall() {
    int i;
    for (i = montyStack.top; i >= 0; i--) {
        printf("%d\n", montyStack.stack[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[100];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        if (line[0] == '\n' || line[0] == '#') {
            // Skip empty line and comment.
            continue;
        }

        char *opcode = strtok(line, " \t\n");
        if (strcmp(opcode, "push") == 0) {
            char *value_str = strtok(NULL, " \t\n");
            if (value_str == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                return EXIT_FAILURE;
            }
            int value = atoi(value_str);
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

