#include "../inc/pathfinder.h"

int **floyd_algorithm (int **graph, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            if(graph[i][j] == 0 && i != j) {
                graph[i][j] = 2147483647;
            }
        }        
    }
    
    int **dist = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        dist[i] = malloc(sizeof(int) * size);
    }
   
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dist[i][j] = graph[i][j];
   
    for (int k = 0; k < size; k++) {        
        for (int i = 0; i < size; i++) {           
            for (int j = 0; j < size; j++) {
                if ((unsigned long long int)(dist[i][k] + dist[k][j]) < (unsigned long long int)dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            if(graph[i][j] == 2147483647 && i != j) {
                graph[i][j] = 0;
            }
        }        
    }
    return dist;
}



