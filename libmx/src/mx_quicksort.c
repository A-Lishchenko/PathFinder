#include "../inc/libmx.h"


int mx_quicksort(char **arr, int left, int right) {
    int res = 0;
    if (arr == NULL) return -1;
    if (left < right) {
        char *piv = arr[(right + left) / 2];
        int left_pointer = left, right_pointer = right;
        while (left_pointer < right_pointer) {
            while (mx_strlen(arr[left_pointer]) < mx_strlen(piv)) {
                left_pointer++;
            }
            while (mx_strlen(arr[right_pointer]) > mx_strlen(piv)) {
                right_pointer--;
            }
            if (left_pointer < right_pointer) {
                if (mx_strlen(arr[left_pointer]) != mx_strlen(arr[right_pointer])) {
                    char *tmp = arr[left_pointer];
                    arr[left_pointer] = arr[right_pointer];
                    arr [right_pointer] = tmp;
                    res++;
                }
            }
            left_pointer++;
            right_pointer--;
        }    
        res += mx_quicksort(arr, left, right_pointer);
        res += mx_quicksort(arr, left_pointer, right);
    }
    return res;
}

