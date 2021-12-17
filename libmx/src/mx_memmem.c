#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {

	if (little_len <= big_len && big_len > 0 && little_len > 0) {
		unsigned char *res = (unsigned char *)big;
		while (*res) {
			if (mx_memcmp(res, (unsigned char *)little, little_len - 1) == 0)
				return res;
			res++;
		}
	}
	return NULL;
}


