#ifndef HEAP_INCLUDED
#define HEAP_INCLUDED

#include "stdbool.h"

typedef struct Heap *Heap_T;


/*
    We are going to need a way to compare elements in a heap, but that's not
    super simple if elements are stored as void pointers (for the sake of 
    polymorphism). So users can give a compare function themselves that does
    the comparison. 

    The cmp function should return a value greater than 0 if elem1 has a 
    higher priority than elem2 (i.e. lower index in the heap), less than 0 if
    elem2 has higher priority, and zero if they are equal. Note how a user
    can specify min or max heap via their cmp function. 
*/
Heap_T Heap_new(int cmp(void *elem1, void *elem2));
void Heap_free(Heap_T *heap_p);
bool Heap_is_empty(Heap_T heap);
unsigned Heap_size(Heap_T heap);
void *Heap_top(Heap_T heap);
void *Heap_pop_top(Heap_T heap);
void Heap_add(Heap_T heap, void *elem);

#endif