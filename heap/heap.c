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

    heap->curr_size = 1;
    heap->max_size = 16;
    heap->cmp = cmp;

    heap->data = malloc(sizeof(void *) * heap->max_size);
    assert(heap->data);

    heap->data[0] = NULL;

    return heap;
}

void Heap_free(Heap_T *heap_p) {
    assert(heap_p);
    free((*heap_p)->data);
    free(*heap_p);
}

bool Heap_is_empty(Heap_T heap) {
    assert(heap);

    return heap->curr_size == 1;
}

void *Heap_top(Heap_T heap) {
    assert(heap);
    assert(!Heap_is_empty(heap));
    return heap->data[1];
}

unsigned Heap_size(Heap_T heap) {
    assert(heap);
    return heap->curr_size - 1;
}

void float_up(Heap_T heap, int index) {
    assert(heap);
    assert(index > 0 && index < heap->curr_size);
    if (index == 1) {
        return;
    }

    if (heap->cmp(heap->data[index], heap->data[index/2]) > 0) {
        void *temp = heap->data[index/2];
        heap->data[index/2] = heap->data[index];
        heap->data[index] = temp;
        float_up(heap, index/2);
    }
}

void Heap_add(Heap_T heap, void *elem) {
    assert(heap);

    if (heap->curr_size == heap->max_size) {
        heap->max_size *= 2;
        heap->data = realloc(heap->data, sizeof(void *) * heap->max_size);
        assert(heap->data);
    }

    heap->data[heap->curr_size] = elem;
    float_up(heap, heap->curr_size++);
}

void sink_down(Heap_T heap, int index) {
    assert(heap);
    assert(index > 0 && index < heap->curr_size);

    if (2 * index >= heap->curr_size) {
        return;
    }

    int new_index;

    if ((2 * index) + 1 == heap->curr_size) {
        new_index = 2 * index;
    } else {
        void *left = heap->data[2 * index];
        void *right = heap->data[(2 * index) + 1];
        new_index = heap->cmp(left, right) >= 0 ? 2 * index : (2 * index) + 1;
    }

    if (heap->cmp(heap->data[new_index], heap->data[index]) > 0) {
        void *temp = heap->data[new_index];
        heap->data[new_index] = heap->data[index];
        heap->data[index] = temp;
        sink_down(heap, new_index);
    }
}

void *Heap_pop_top(Heap_T heap) {
    assert(heap);
    assert(!Heap_is_empty(heap));

    void *ret = heap->data[1];
    heap->curr_size--;

    if (heap->curr_size > 1) {
        heap->data[1] = heap->data[heap->curr_size];
        sink_down(heap, 1);
    }

    return ret;
}

