#include "stdio.h"
#include "stdlib.h"
#include "heap.h"
#include "assert.h"

int cmp_int(void *elem1, void *elem2) {
    return *(int *)elem1 - *(int *)elem2;
}


int main() {

    int *array = malloc(sizeof(int) * 100);
    assert(array);

    for (int i = 0; i < 100; i++) {
        array[i] = rand();
    }

    Heap_T heap = Heap_new(cmp_int);

    for (int i = 0; i < 100; i++) {
        Heap_add(heap, &array[i]);
    }

    int *sorted_array = malloc(sizeof(int) * 100);
    assert(sorted_array);

    int index = 0;
    while(!Heap_is_empty(heap)) {
        sorted_array[index] = *(int *)Heap_pop_top(heap);
        index++;
    }

    for (int i = 0; i < 100; i++) {
        printf("%d\n", sorted_array[i]);
    }

    Heap_free(&heap);

    free(array);
    free(sorted_array);

    return 0;
}