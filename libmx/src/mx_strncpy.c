#include "../inc/libmx.h"


char* mx_strncpy(char* dst, const char* src, int len)
{
    char* pointer = dst;
    while (*src && (len--) > 0)
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return pointer;
}


