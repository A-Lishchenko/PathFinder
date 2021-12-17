#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 != NULL)  {
        char *copy = mx_strnew(mx_strlen(s1));
        if (copy != NULL) {
            copy = mx_strncpy(copy, s1, n);
            return copy;
        }
        else return NULL;
    }
    else return NULL;
}



