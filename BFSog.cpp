#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;
#define N 1000

int Queue[10000];

int front = 0, rear = 0;

void Enqueue(int var)
{
    Queue[rear] = var;
    rear++;
}

void Dequeue()
{
    Queue[front] = 0;
    front++;
}

int visited[N] = {0};

int main()
{
    int graph[N][N];
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
            int k = rand() % 2;
            graph[i][j] = k;
            graph[j][i] = k;
        }   
    }

  
    gettimeofday(&t1, &z1);
    Enqueue(1);
    visited[0] = 1;

    while (front != rear)
    {
        int curr = Queue[front];
        Dequeue();
         
        for (int i = 0; i < N; i++)
        {
            if ((graph[curr - 1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1;
                Enqueue(i + 1);
                //cout<<i+1<<"  ";
            }
        }
    }
    gettimeofday(&t2, &z2);
    
    cout<<"\nSeconds : "<< t2.tv_sec - t1.tv_sec<< "Microseconds : "<<  t2.tv_usec - t1.tv_usec;
    return 0;
}
