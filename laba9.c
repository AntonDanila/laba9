#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <queue>
using namespace std;

int **createG(int size) {
    int **G = (int**)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++) {
        G[i] = (int *)malloc(size * sizeof(int));
    }
    for(int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            G[i][j] = rand() % 2;
            if(i == j) G[i][j] = 0;
            G[j][i] = G[i][j];
        }
    }
    return G;
}

void printG(int **G, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void BFS(int **G, int size, int *dist, int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0; 
    while (!q.empty()) {
        s = q.front();
        printf("%d ", s);
        q.pop();
        
        for (int i = 0; i < size; i++) {
            if (G[s][i] == 1 && dist[i] == -1) { 
                q.push(i);
                dist[i] = dist[s] + 1; 
            }
        }
    }
}

int main() {
    int **G = NULL;
    int size = 5;
    int s = 1;

    printf("Введите кол-во вершин: ");
    scanf("%d", &size);
    G = createG(size);
    printG(G, size);
    printf("Введите начальную вершину: ");
    
    int *dist = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) dist[i] = -1; 

    scanf("%d", &s);
    printf("Обход графа:\n");
    BFS(G, size, dist, s);
    
    printf("\nПоиск расстояний: \n");
    for (int i = 0; i < size; i++) {
        printf("Расстояние до %d вершины = %d\n", i, dist[i]);
    }
    

    for(int i = 0; i < size; i++) {
        free(G[i]);
    }
    free(G);
    free(dist);

    return 0;
}
