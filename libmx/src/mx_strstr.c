#include "../inc/libmx.h"


char *mx_strstr(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    if (!mx_strlen(s2))
        return (char*) s1;
    for (int i = 0; i <= mx_strlen(s1) - mx_strlen(s2); i++) 
        if (!mx_strncmp(&s1[i], s2, mx_strlen(s2)))
            return (char*) &s1[i];   
    return NULL;
}



