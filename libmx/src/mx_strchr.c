#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    if (s == NULL)
        return NULL;
    while(*s != '\0'){
        if(*s == c) return (char *)s;
    
        s++;
    }
    return NULL;
}

