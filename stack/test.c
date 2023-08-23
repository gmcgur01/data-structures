#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

int main() {
    Stack_T stack = Stack_new();

    printf(Stack_is_empty(stack) ? "empty!\n" : "not empty!\n");

    Stack_free(&stack);

    return 0;
}