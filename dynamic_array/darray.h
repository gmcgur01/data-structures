#ifndef DARRAY_INCLUDED
#define DARRAY_INCLUDED

typedef struct DArray *DArray_T;

DArray_T DArray_new();
void DArray_free(DArray_T *darray_p);
void DArray_push(DArray_T darray, void *elem);
unsigned DArray_size(DArray_T darray);
void *DArray_get(DArray_T darray, int index);
void DArray_set(DArray_T darray, int index, void *elem);
void DArray_print(DArray_T darray);
void DArray_delete(DArray_T darray, int index); 

#endif