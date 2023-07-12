#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

int **randomGraph(int n)
{
    int **a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            int k = (rand() % ((n - 1) - 0 + 1)) + 0;
            a[i][j] = k;
        }
    }
    return a;
}

int comparator(const void *p1, const void *p2)
{
    const int(*x)[3] = (const int(*)[3])p1;
    const int(*y)[3] = (const int(*)[3])p2;
    return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[], int n)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int n, int **edge)
{
    qsort(edge, n, sizeof(edge[0]), comparator);
    int parent[n];
    int rank[n];
    makeSet(parent, rank, n);
    int minCost = 0;
    for (int i = 0; i < n; i++)
    {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];
        if (v1 != v2)
        {
            unionSet(v1, v2, parent, rank, n);
            minCost += wt;
        }
    }
}

int main()
{
    struct timeval t1, t2;
    struct timezone z1, z2;
    int n = 4000;
    int **edge = randomGraph(n);
    gettimeofday(&t1, &z1);
    kruskalAlgo(n, edge);
    gettimeofday(&t2, &z2);
    cout << "Seconds: " << t2.tv_sec - t1.tv_sec << ", Microseconds: " << t2.tv_usec - t1.tv_usec << endl;
    return 0;
}
