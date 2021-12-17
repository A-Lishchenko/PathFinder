#include "../inc/pathfinder.h"

bool need_to_sort (int *arr1, int *arr2, int index) {
    for (int i = 0; i < index; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

void sort_path (int **arr, int first, int second, char **islands, int **all_path, int size) {
    for (int j = 0; j < size * size; j++) {
        for (int i = 0; i < (size - 1) * size; i++) {
            if (all_path[i][j] > all_path[i + 1][j] && all_path[i + 1][j] != -1 && need_to_sort(all_path[i], all_path[i + 1], j)) {
                int *temp = all_path[i];
                all_path[i] = all_path[i + 1];
                all_path[i + 1] = temp;
                i = size; j = -1 ;
            }
        }
    }
    for (int i = 0; i < size * size; i++) {
        if (all_path[i][0] != -1) {
            print(arr, first, second, islands, all_path[i], size);
        }
    }
    for (int i = 0; i < size * size; i++) {
        for (int j = 0; j < size * size; j++) 
            all_path[i][j] = -1;
    }
}
