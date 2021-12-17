#include "../inc/libmx.h"


void mx_printchar(char c) {
    char* buffer = &c;
    write(1, buffer, 1);
    
}

