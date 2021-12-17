#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) return NULL;
    char *res = NULL;
    while (*str != '\0') {
        if (mx_get_substr_index(str, sub) == 0) {
            res = mx_strjoin(res, replace);
            for (int i = 0; i < mx_strlen(sub); i++) {
                str++;
            }
        }
        else {
            char *temp = malloc(1);
            temp[0] = *str;
            res = mx_strjoin(res, temp);
            free(temp);
            str++;
        }
    }
    return res;
}



