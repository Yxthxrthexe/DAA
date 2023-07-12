#include <limits.h>
#include <stdbool.h>
#include <iostream>
#include <sys/time.h>

#define V 4000

int **randomGraph() {
    int **a = new int*[V];
    for (int i = 0; i < V; i++) {
        a[i] = new int[V];
        for (int j = 0; j < V; j++) {
            int k = (rand() % (9 - 0 + 1)) + 0;
            a[i][j] = k;
        }
    }
    return a;
}

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int **graph) {
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}

void primMST(int **graph) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    //printMST(parent, graph);
}

int main() {
    struct timeval t1, t2;
    struct timezone z1, z2;
    int **graph = randomGraph();
    gettimeofday(&t1, &z1);
    primMST(graph);
    gettimeofday(&t2, &z2);
    std::cout << "Seconds : " << t2.tv_sec - t1.tv_sec << ", Microseconds : " << t2.tv_usec - t1.tv_usec << "\n";
    return 0;
}
