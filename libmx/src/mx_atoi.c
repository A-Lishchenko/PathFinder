#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int nachalo = -1, konets = -1, znak = 0, result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '-') && (mx_isdigit(str[i + 1]) == true)) {
            znak = 1;
            continue;
        }
        if ((mx_isspace(str[i]) == false) && (nachalo == -1))
            nachalo = i;
        if ((nachalo > -1) && (mx_isdigit(str[i]) == false) && (konets == -1))
            konets = i;
    }

    if (konets == -1)
        for (int i = nachalo; str[i] != '\0'; i++)
            result = 10 * result + (int)str[i] - 48;
    else
        for (int i = nachalo; i < konets; i++)
            result = 10 * result + (int)str[i] - 48;

    return znak == 0 ? result : -1 * result;
}





