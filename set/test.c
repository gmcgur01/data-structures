#include "stdlib.h"
#include "stdio.h"
#include "set.h"

int main() {
    Set_T set = Set_new();
    printf(Set_in(set, 0) ? "true!\n" : "false!\n");
    Set_free(&set);
}