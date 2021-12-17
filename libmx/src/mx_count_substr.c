#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    if (!str || !sub)
        return 0;
    char *tmp = mx_strstr(str, sub);
    while (tmp != NULL) { 
        tmp++;
        tmp = mx_strstr(tmp, sub);
        count++;
    }

    return count;
}



