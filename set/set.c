#include "set.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

// TODO: Implement the set using a hash table

struct Set {
    unsigned curr_size;
    unsigned max_size;
    int *data;
};

Set_T Set_new(){
    Set_T set = malloc(sizeof(*set));
    assert(set);

    set->curr_size = 0;
    set->max_size = 16;

    set->data = malloc(sizeof(int) * set->max_size);
    assert(set->data);

    return set;
}

void Set_free(Set_T *set_p) {
    assert(set_p);
    free((*set_p)->data);
    free(*set_p);
}

bool Set_in(Set_T set, int elem) {
    assert(set);

    for (int i = 0; i < set->curr_size; i++) {
        if (elem == set->data[i]) {
            return true;
        }
    }
    return false;
}

void Set_add(Set_T set, int elem) {
    assert(set);

    for (int i = 0; i < set->curr_size; i++) {
        if (set->data[i] == elem) {
            return;
        } 
    } 

    if (set->curr_size == set->max_size) {
        set->max_size *= 2;
        set->data = realloc(set->data, sizeof(int) * set->max_size);
        assert(set->data);
    }
    set->data[set->curr_size++] = elem;
}

void Set_print(Set_T set) {
    assert(set);

    printf("Current Size: %u\nMax Size: %u\nElements:\n", set->curr_size, set->max_size);

    for (int i = 0; i < set->curr_size; i++) {
        printf("%d\n", set->data[i]);
    }

}

void Set_remove(Set_T set, int elem) {
    assert(set);

    for (int i = 0; i < set->curr_size; i++) {
        if (elem == set->data[i]) {
            set->data[i] = set->data[--set->curr_size];
        }
    }
}

unsigned Set_size(Set_T set) {
    assert(set);

    return set->curr_size;
}
