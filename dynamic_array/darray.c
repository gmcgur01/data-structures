#include "darray.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

struct DArray {
    unsigned curr_size;
    unsigned max_size;
    void **data;
};

DArray_T DArray_new() {
    DArray_T darray = malloc(sizeof(*darray));
    assert(darray);

    darray->curr_size = 0;
    darray->max_size = 16;

    darray->data = malloc(darray->max_size * sizeof(void *));
    assert(darray->data);

    return darray;
}

void DArray_free(DArray_T *darray_p) {
    assert(darray_p);
    free((*darray_p)->data);
    free(*darray_p);
}

void DArray_push(DArray_T darray, void *elem) {
    assert(darray);

    if (darray->curr_size == darray->max_size) {
        darray->max_size *= 2;
        darray->data = realloc(darray->data, darray->max_size * sizeof(void *));
    }

    darray->data[darray->curr_size++] = elem;
}
unsigned DArray_size(DArray_T darray) {
    assert(darray);
    return darray->curr_size;
}
void *DArray_get(DArray_T darray, int index) {
    assert(darray);
    assert(index < (int)darray->curr_size);
    assert(index > ((int)(-1 * darray->curr_size) - 1));

    if (index < 0) {
        return darray->data[darray->curr_size + index];
    }
    return darray->data[index];
}

void DArray_set(DArray_T darray, int index, void *elem) {
    assert(darray);

    if (index == darray->curr_size) {
        DArray_push(darray, elem);
        return;
    }
    assert(index < (int)darray->curr_size);
    assert(index > ((int)(-1 * darray->curr_size) - 1));

    if (index < 0) {
        darray->data[darray->curr_size + index] = elem;
    } else {
        darray->data[index] = elem;
    }
}