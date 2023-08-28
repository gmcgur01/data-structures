#include "stdio.h"
#include "stdlib.h"
#include "heap.h"

int cmp_int(void *elem1, void *elem2) {
    return *(int *)elem1 - *(int *)elem2;
}


int main() {

    Heap_T heap = Heap_new(cmp_int);
    Heap_free(&heap);

    printf("Hello world!\n");
    return 0;
}