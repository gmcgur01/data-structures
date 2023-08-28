#include "heap.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

struct Heap {
    void **data;
    unsigned curr_size;
    unsigned max_size;
    int(*cmp)(void *elem1, void *elem2);
};

Heap_T Heap_new(int cmp(void *elem1, void *elem2)) {
    Heap_T heap = malloc(sizeof(*heap));
    assert(heap);

    heap->curr_size = 0;
    heap->max_size = 16;
    heap->cmp = cmp;

    heap->data = malloc(sizeof(void *) * heap->max_size);
    assert(heap->data);

    return heap;
}

void Heap_free(Heap_T *heap_p) {
    assert(heap_p);
    free((*heap_p)->data);
    free(*heap_p);
}

