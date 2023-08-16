#ifndef SET_INCLUDED
#define SET_INCLUDED

#include "stdbool.h"

typedef struct Set *Set_T;

Set_T Set_new();
void Set_free(Set_T *set_p);
bool Set_in(Set_T set, int elem);
void Set_add(Set_T set, int elem);
void Set_print(Set_T set);
void Set_remove(Set_T set, int elem);
unsigned Set_size(Set_T set);

#endif