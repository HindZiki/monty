#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

typedef struct {
    int stack[STACK_SIZE];
    int top;
    int isQueueMode;
} MontyStack;

extern MontyStack montyStack;

void pushToQueue(int value) {
    // Shift elements to make space for the new element at the front
    for (int i = montyStack.top + 1; i > 0; i--) {
        montyStack.stack[i] = montyStack.stack[i - 1];
    }
    montyStack.stack[0] = value;
    montyStack.top++;
}

void queue() {
    montyStack.isQueueMode = 1;
}

