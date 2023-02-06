
#include <stdio.h>

int n, i, j, visited[10], queue[10], front = 0, rear = -1;
int adj[10][10];

void bfs(int v)
{
  for (i = 1; i <= n; i++)
    if (adj[v][i] && !visited[i])
      queue[++rear] = i;
  if (front <= rear)
  {
    visited[queue[front]] = 1;
    bfs(queue[front++]);
  }
}

void main()
{
  int v;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    queue[i] = 0;
    visited[i] = 0;
  }
  printf("Enter graph data in matrix form:    \n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", &adj[i][j]);
  printf("Enter the starting vertex: ");
  scanf("%d", &v);
  visited[v] = 1;
  bfs(v);
  printf("\nThe node which are reachable are:\n");
  int count = 0;
  for (i = 1; i <= n; i++)
  {
    if (visited[i])
    {
      printf("\nAccessible VERTEX => %d\t", i);
      count++;
    }
    else
      printf("\nBFS is not possible VERTEX=>%d not accesible", i);
    if (count == n)
    {
      printf("\nBFS traversal is possible");
    }
  }
}