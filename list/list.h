#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct List *List_T;

List_T List_new();
void List_free(List_T *list_p);
void List_push(List_T list, void *elem);
unsigned List_size(List_T list);
void *List_get(List_T list, int index);
void List_set(List_T list, int index, void *elem);
void List_print(List_T list);
void List_delete(List_T list, int index); 
void List_map(List_T list, 
    void apply(int index, List_T list, void *curr_element, void *cl),
    void *cl);

#endif