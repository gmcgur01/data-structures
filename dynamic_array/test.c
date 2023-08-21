#include "stdlib.h"
#include "stdio.h"
#include "darray.h"

int main () {

    DArray_T darray = DArray_new();

    int a = 8;
    int b = 7;

    DArray_push(darray, &a);
    DArray_push(darray, &b);

    DArray_print(darray);

    DArray_push(darray, &a);
    DArray_delete(darray, 1);

    DArray_print(darray);

    printf("%d\n", DArray_size(darray));

    printf("%d\n", *(int *)DArray_get(darray, 0));
    printf("%d\n", *(int *)DArray_get(darray, -1));

    int nums[100];
    for (int i = 0; i < 100; i++) {
        nums[i] = i;
        DArray_set(darray, i + 2, &nums[i]);
    }

    DArray_print(darray);
    
    DArray_free(&darray);

    return 0;
}