#ifndef PATH
#define PATH

#include "../libmx/inc/libmx.h"

int main (int argc, char* argv[]);
int **errors(int argc, char* argv[], char ***name_islands, int *size);
void print (int **arr, int first, int second, char **islands, int *path, int size);
void colission (int **floyd, int **arr, int size, int begin, int index, int end, char **islands, int **all_path);
int **floyd_algorithm (int **graph, int size);
void sort_path (int **arr, int first, int second, char **islands, int **all_path, int size);

#endif
