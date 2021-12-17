#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    if (str  == NULL) return -1;
    int words = 0;
    for (int i = 0; i < mx_strlen(str) - 1; i++) {
        if (words == 0 && str[i] != delimiter) words++;
        if (str[i] == delimiter && str[i + 1] != delimiter)
            words++;
    }
    return words;
}
