#include "set.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

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
