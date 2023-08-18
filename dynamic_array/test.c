#include "stdlib.h"
#include "stdio.h"
#include "darray.h"

int main () {

    DArray_T darray = DArray_new();

    int a = 8;
    int b = 7;

    DArray_push(darray, &a);
    DArray_push(darray, &b);

    printf("%d\n", DArray_size(darray));

    printf("%d\n", *(int *)DArray_get(darray, 0));
    printf("%d\n", *(int *)DArray_get(darray, -1));
    
    DArray_free(&darray);

    return 0;
}