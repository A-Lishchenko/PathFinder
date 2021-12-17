#include "../inc/libmx.h"


void mx_push_back(t_list **list, void *data) {
    if (*list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    t_list *temp_list = *list;
    while (temp_list->next != NULL) {
        temp_list = temp_list->next;
    }
    t_list *temp = mx_create_node(data);
    temp_list->next = temp;

}



