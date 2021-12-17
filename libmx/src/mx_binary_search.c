#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int start = 0, end = size - 1;
    while(start <= end) {
        *count += 1;
        int middle = (start + end) / 2;
        if (mx_strcmp(arr[middle], s) == 0){
            return middle;
        }
        else if (mx_strcmp(arr[middle], s) < 0) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }
    *count = 0;
    return -1;
}




