#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        ptr = malloc(size);
        return ptr;
    }

    if (size < malloc_size(ptr))
        return ptr;
    void *res = malloc(size);
    mx_memmove(res, ptr, malloc_size(ptr));
    free(ptr);
    return res;     
}

