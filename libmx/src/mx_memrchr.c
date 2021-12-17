#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	unsigned char *ptr = (unsigned char *)s + mx_strlen(s);

	for (size_t i = 0; i < n; i++) {
		if (*ptr == (unsigned char)c)
			return ptr;
		ptr--;
	}
	return NULL;
}

