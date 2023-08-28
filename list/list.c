#include "list.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

// TODO: add a remove element function

// The way I'm thinking of implementing would be O(n), but I wonder if there's 
// a cleverer way to do it

struct List {
    unsigned curr_size;
    unsigned max_size;
    void **data;
};

List_T List_new() {
    List_T list = malloc(sizeof(*list));
    assert(list);

    list->curr_size = 0;
    list->max_size = 16;

    list->data = malloc(list->max_size * sizeof(void *));
    assert(list->data);

    return list;
}

void List_free(List_T *list_p) {
    assert(list_p);
    free((*list_p)->data);
    free(*list_p);
}

void List_push(List_T list, void *elem) {
    assert(list);

    if (list->curr_size == list->max_size) {
        list->max_size *= 2;
        list->data = realloc(list->data, list->max_size * sizeof(void *));
    }

    list->data[list->curr_size++] = elem;
}
unsigned List_size(List_T list) {
    assert(list);
    return list->curr_size;
}
void *List_get(List_T list, int index) {
    assert(list);
    assert(index < (int)list->curr_size);
    assert(index > ((int)(-1 * list->curr_size) - 1));

    if (index < 0) {
        return list->data[list->curr_size + index];
    }
    return list->data[index];
}

void List_set(List_T list, int index, void *elem) {
    assert(list);

    if (index == list->curr_size) {
        List_push(list, elem);
        return;
    }
    assert(index < (int)list->curr_size);
    assert(index > ((int)(-1 * list->curr_size) - 1));

    if (index < 0) {
        list->data[list->curr_size + index] = elem;
    } else {
        list->data[index] = elem;
    }
}

void List_print(List_T list) {
    assert(list);

    printf("Current Size: %u\nMax Size: %u\nElements:\n", list->curr_size, list->max_size);

    for (int i = 0; i < list->curr_size; i++) {
        printf("%llx\n", (long long unsigned)list->data[i]);
    }
}

// shifts down elements
void List_delete(List_T list, int index) {
    assert(list);
    assert(index < (int)list->curr_size);
    assert(index > ((int)(-1 * list->curr_size) - 1));
    
    if (index < 0) {
        index = list->curr_size + index;
    }

    for (;index < list->curr_size - 1; index++) {
        list->data[index] = list->data[index + 1];
    }

    list->curr_size--;
}

void List_map(List_T list, 
    void apply(int index, List_T list, void *curr_element, void *cl),
    void *cl) {
    assert(list);

    for (int i = 0; i < list->curr_size; i++) {
        apply(i, list, list->data[i], cl);
    }
}

List_T List_copy(List_T list) {
    assert(list);

    List_T new_list = malloc(sizeof(*new_list));
    assert(new_list);

    new_list->curr_size = list->curr_size;
    new_list->max_size = list->max_size;

    new_list->data = malloc(new_list->max_size * sizeof(void *));
    assert(new_list->data);

    for (int i = 0; i < list->curr_size; i++) {
        new_list->data[i] = list->data[i];
    }

    return new_list;
}

List_T List_append(List_T list1, List_T list2) {
    assert(list1 && list2);

    List_T new_list = malloc(sizeof(*new_list));
    assert(new_list);

    new_list->curr_size = list1->curr_size + list2->curr_size;
    new_list->max_size = list1->max_size + list2->max_size;

    new_list->data = malloc(new_list->max_size * sizeof(void *));
    assert(new_list->data);

    for (int i = 0; i < list1->curr_size; i++) {
        new_list->data[i] = list1->data[i];
    }

    for (int i = 0; i < list2->curr_size; i++) {
        new_list->data[list1->curr_size + i] = list2->data[i];
    }

    return new_list;
}