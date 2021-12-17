#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size <= 0 || fd <= 0) return -2;
    int count = 0;
    char c;
    bool first = true;
    while(read(fd, &c, 1)) {
        if (first) {            
            *lineptr = mx_realloc(*lineptr, 1);
            mx_memset(*lineptr, '\0', mx_strlen(*lineptr));
            first = false;
        }
        if (c == delim) return count;
        *lineptr = mx_realloc(*lineptr, count + 1);
        (*lineptr)[count] = c;
        count++;
    }
    return count == 0 ? -1 : count;
}


