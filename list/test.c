#include "stdlib.h"
#include "stdio.h"
#include "list.h"

void apply_print(int index, List_T list, void *curr_elem, void *cl) {
    (void) index;
    (void) list;
    (void) cl;
    printf("%d\n", *(int *)curr_elem);
}

int main () {

    List_T list = List_new();

    int a = 8;
    int b = 7;

    List_push(list, &a);
    List_push(list, &b);

    List_print(list);

    List_push(list, &a);
    List_delete(list, 1);

    List_print(list);

    printf("%d\n", List_size(list));

    printf("%d\n", *(int *)List_get(list, 0));
    printf("%d\n", *(int *)List_get(list, -1));

    int nums[100];
    for (int i = 0; i < 100; i++) {
        nums[i] = i;
        List_set(list, i + 2, &nums[i]);
    }

    List_print(list);

    List_map(list, apply_print, NULL);
    
    List_free(&list);

    return 0;
}