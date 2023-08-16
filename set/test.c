#include "stdlib.h"
#include "stdio.h"
#include "set.h"

int main() {
    Set_T set = Set_new();

    for (int i = 0; i < 100; i++) {
        Set_add(set, i);
    }
    Set_print(set);
    Set_remove(set, 50);
    Set_print(set);
    printf(Set_in(set, 50) ? "true!\n" : "false!\n"); 
    Set_free(&set);
}