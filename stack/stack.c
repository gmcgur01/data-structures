#include "stack.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

struct Stack {
    void **data;
    unsigned curr_size;
    unsigned max_size;
};

Stack_T Stack_new() {
    Stack_T stack = malloc(sizeof(*stack));
    assert(stack);

    stack->curr_size = 0;
    stack->max_size = 16;

    stack->data = malloc(sizeof(void *) * stack->max_size);
    assert(stack->data);

    return stack;
}

void Stack_free(Stack_T *stack_p) {
    assert(stack_p);

    free((*stack_p)->data);
    free(*stack_p);
}

bool Stack_is_empty(Stack_T stack) {
    return !stack->curr_size;
}