#include "../inc/pathfinder.h"

int main (int argc, char* argv[]) {
    char **islands = NULL;
    int size = 0;
    int **arr = errors(argc, argv, &islands, &size);    
    int **floyd = floyd_algorithm(arr, size);    
    int **all_path = malloc(sizeof(int*) * size * size);
    for (int i = 0; i < size * size; i++) {
        all_path[i] = malloc(sizeof(int) * size * size);
        for (int j = 0; j < size * size; j++)
            all_path[i][j] = -1;
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            colission(floyd, arr, size, i, j, j, islands, all_path);
            sort_path(arr, i, j, islands, all_path, size);
        }
    }


    mx_del_strarr(&islands);
    for (int i = 0; i < size; i++) {
        free(arr[i]);
        free(floyd[i]);
    }
    for (int i = 0; i < size * size; i++) {
        free(all_path[i]);
    }
    free(arr);
    free(floyd);
    free(all_path);
}

