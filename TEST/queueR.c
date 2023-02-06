#include <stdio.h>
#include <stdlib.h>
int read_graph();
int dir_graph();
int undir_graph();
int read_graph(int adj_mat[50][50], int n)
{
  int i, j;
  char reply;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (i == j)
      {
        adj_mat[i][j] = 0;
        continue;
      }
      printf("\nvertices %d & %d are adjacent?(Y/N):", i, j);
      fflush(stdin);
      scanf("%c", &reply);
      if (reply == 'Y' || reply == 'y')
        adj_mat[i][j] = 1;
      else
        adj_mat[i][j] = 0;
    }
  }
}
int dir_graph()
{
  int adj_mat[50][50];
  int n;
  int in_deg, out_deg, i, j;
  printf("how many vertices:");
  scanf("%d", &n);
  read_graph(adj_mat, n);
  printf("\nvertex\t in_degree\tout_degree\ntotal_degree");

  for (i = 1; i <= n; i++)
  {
    in_deg = out_deg = 0;
    for (j = 1; j <= n; j++)
    {
      if (adj_mat[j][i] == 1)
        in_deg++;
    }
    for (j = 1; j <= n; j++)
      if (adj_mat[i][j] == 1)
        out_deg++;

    printf("\n\n%5d\t\t%d\t\t%d\t\t%d\n\n", i, in_deg, out_deg, in_deg + out_deg);
  }
}
int undir_graph()
{
  int adj_mat[50][50];
  int i, j, n, deg;
  printf("how many vertices:");
  scanf("%d", &n);
  read_graph(adj_mat, n);
  printf("\nvertex\tdegree");
  for (i = 1; i <= n; i++)
  {
    deg = 0;
    for (j = 1; j <= n; j++)
      if (adj_mat[i][j] == 1)
        deg++;

    printf("\n\n%5d\t\t%d\n\n", i, deg);
  }
}
void main()
{
  int ch;
  do
  {
    printf("program to represent graph using an:");
    printf("adjacency matrix method\n");
    printf("\n1.directed graph\n");
    printf("\n2.undirected graph\n");
    printf("\n3.exit\n");
    printf("enter your choice:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      dir_graph();
      break;
    case 2:
      undir_graph();
      break;
    case 3:
      exit(0);
    }
  } while (1);
}