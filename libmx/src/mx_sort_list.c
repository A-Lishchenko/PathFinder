#include "../inc/libmx.h"


t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *a, void *b)) {
    t_list *temp = lst;
    if (lst == NULL)
        return NULL;
    while (temp->next != NULL) {
        if (cmp(temp->data, temp->next->data)) {
            void *dt = temp->data;
            temp->data = temp->next->data;
            temp->next->data = dt;
            temp = lst;
        }
        else 
            temp = temp->next;
    }
    return lst;
}



