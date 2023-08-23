#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#include "stdbool.h"

typedef struct Stack *Stack_T;

Stack_T Stack_new();
void Stack_free(Stack_T *stack_p);
bool Stack_is_empty(Stack_T stack);
void Stack_push(Stack_T stack, void *elem);
void *Stack_pop(Stack_T stack);

#endif