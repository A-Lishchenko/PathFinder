#include "../inc/pathfinder.h"


void mx_push_all_back (int **all_path, t_list *path, int size) {
    int i;
    for (i = 0; i < size * size; i++) {
        if (all_path[i][0] == -1) {
            break;
        }
    } 
    t_list *temp = path;
    int j = 0;
    while (temp) {
        all_path[i][j] = *((int *)temp->data);
        temp = temp->next;
        j++;
    }
}



t_list *path = NULL;
void colission (int **floyd, int **arr, int size, int begin, int index, int end, char **islands, int **all_path) {
    if (path == NULL) {
        mx_push_front(&path, &index);
    }
    for (int i = 0; i < size; i++) {
        if (arr[i][index] != 0 && i != index) {
            if ((floyd[begin][i] + arr[i][index]) == floyd[begin][index]) {           
                int a = i;
                mx_push_front(&path, &a);
                if (i == begin) {      
                    mx_push_all_back(all_path, path, size);
                    mx_pop_front(&path);
                    continue;
                }              
                colission(floyd, arr, size, begin, i, end, islands, all_path);
                mx_pop_front(&path);
            }
        }
    }
}


