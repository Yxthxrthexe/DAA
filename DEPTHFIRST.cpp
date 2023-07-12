#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;
#define N 1000
 int graph[N][N];
int visited[N] = {0};
void Dfs(int x)
{
    visited[x]=1;
    for (int  i = 0; i < N; i++)
    {
        if(graph[x][i]==1 && !visited[i])
        {
            Dfs(i);
        }
    }
}

int main()
{
    struct timeval t1, t2;
    struct timezone z1, z2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
                continue;
            }
            int k = rand() %  2;
            graph[i][j] = k;
            graph[j][i] = k;
        }
    }
    gettimeofday(&t1, &z1);
    Dfs(1);
    gettimeofday(&t2, &z2);
    cout <<endl;
    cout <<"Seconds" << t2.tv_sec - t1.tv_sec <<"  Microseconds" << t2.tv_usec - t1.tv_usec<< endl;
    return 0;
}
