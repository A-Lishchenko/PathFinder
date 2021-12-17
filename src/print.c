#include "../inc/pathfinder.h"

void print (int **arr, int first, int second, char **islands, int *path, int size) {
    
    for (int i = 0; i < 40; i++)
        mx_printchar('=');    
    mx_printstr("\n");

    mx_printstr("Path: ");
    mx_printstr(islands[first]);
    mx_printstr(" -> ");
    mx_printstr(islands[second]);
    mx_printstr("\n");  

    mx_printstr("Route: ");
    bool first_it = true;
    for (int i = 0; i < size; i++) {
        if (path[i] != -1) {
            if (!first_it) mx_printstr(" -> ");
            first_it = false;
            mx_printstr(islands[path[i]]);
        }            
        else
            break;
    }
    mx_printstr("\n");

    mx_printstr("Distance: ");
    int sum = 0;
    first_it = true;
    for (int i = 0; i < size - 1; i++) {
        if (path[i] != -1 && path[i + 1] != -1) {
            if (!first_it) mx_printstr(" + ");
            first_it = false;
            mx_printint(arr[path[i]][path[i + 1]]);
            sum += arr[path[i]][path[i + 1]];
        }
        else
            break;
    }
    if (size > 2 && path[2] != -1) {
        mx_printstr(" = ");
        mx_printint(sum);
    }
        mx_printstr("\n");

    for (int i = 0; i < 40; i++)
        mx_printchar('=');
    mx_printstr("\n");
}


