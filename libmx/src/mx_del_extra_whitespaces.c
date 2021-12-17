#include "../inc/libmx.h"


char *mx_del_extra_whitespaces(const char *str) {
    if (str == NULL) return NULL;  
    int i = 0, j = 0;
    char *tmp = mx_strnew(mx_strlen(str));
    while (str[i])  {
        if (!mx_isspace(str[i]))
            tmp[j++] = str[i];
        if (!mx_isspace(str[i]) && mx_isspace(str[i + 1]))
            tmp[j++] = ' ';
        i++;
    }    
    char *res = mx_strtrim(tmp);
    mx_strdel(&tmp);
    return res;    
}


