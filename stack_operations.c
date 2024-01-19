#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

typedef struct {
    int stack[STACK_SIZE];
    int top;
} MontyStack;

extern MontyStack montyStack;

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

void stack() {
    montyStack.isQueueMode = 0;
}

