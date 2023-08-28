#include "stdlib.h"
#include "stdio.h"
#include "list.h"
#include "stdbool.h"

typedef struct is_equal_cl {
    List_T list;
    bool is_equal;
} is_equal_cl;

void apply_print(int index, List_T list, void *curr_elem, void *cl) {
    (void) index;
    (void) list;
    (void) cl;
    printf("%d\n", *(int *)curr_elem);
}

void apply_is_equal(int index, List_T list, void *curr_elem, void *cl) {
    (void) list;
    ((is_equal_cl *)cl)->is_equal &= List_get(((is_equal_cl *)cl)->list, index) == curr_elem;
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

    List_T new_list = List_copy(list);

    is_equal_cl cl = {list, true};

    List_map(new_list, apply_is_equal, &cl);
    printf(cl.is_equal ? "The copy is equal!\n" : "The copy is not equal!\n");

    int c = 18;

    List_set(new_list, 0, &c);

    List_map(new_list, apply_is_equal, &cl);
    printf(cl.is_equal ? "The copy is equal!\n" : "The copy is not equal!\n");

    List_T big_list = List_append(list, new_list);

    List_map(big_list, apply_print, NULL);
    
    List_free(&list);
    List_free(&new_list);
    List_free(&big_list);

    return 0;
}