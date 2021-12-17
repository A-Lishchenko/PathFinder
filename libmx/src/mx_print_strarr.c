#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (arr != NULL && delim != NULL) {
        while (mx_strcmp(*arr,"\0") != 0)
        {
            mx_printstr(*arr);
            arr++;
            if (mx_strcmp(*arr,"\0") != 0)
                mx_printstr(delim);
        }
        mx_printchar('\n');    
    }
}


