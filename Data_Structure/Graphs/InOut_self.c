#include <stdio.h>
#include <stdlib.h>

int readgraph(int adj[50][50], int n)
{
  int i, j;
  char reply;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
      {
        adj[i][j] = 0;
      }
      else
      {
        printf("\nEnter vertices %d and %d are adjacent[Y/N]:", i, j);
        scanf(" %c", &reply);
        if (reply == 'y' || reply == 'Y')
        {
          adj[i][j] = 1;
        }
        else
        {
          adj[i][j] = 0;
        }
      }
    }
  }
}

int dirgraph()
{
  int adj[50][50];
  int n;
  int in_deg, out_deg;
  printf("\nEnter No of vertices:");
  scanf("%d", &n);

  readgraph(adj, n);
  printf("\n\n vertices   in_deg\t    out_deg\t  total_degree");
  for (int i = 1; i <= n; i++)
  {
    in_deg = out_deg = 0;
    for (int j = 1; j <= n; j++)
    {
      if (adj[j][i] == 1)
        in_deg++;
      if (adj[i][j] == 1)
        out_deg++;
    }
    // for (int j = 1; j <= n; j++)
    // {
    //   if (adj[i][j] == 1)
    //     out_deg++;
    // }
    printf("\n\n%5d\t\t%d\t\t%d\t\t%d", i, in_deg, out_deg, in_deg + out_deg);
  }
}
int main()
{
  int choice;
  printf("MENU :\n");
  printf("1. Directed Graph\n");
  printf("2. Un_Directed Graph\n");
  while (1)
  {
    printf("\nEnter Choice From MENU Above:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      dirgraph();
      break;
      // case 2:
      // u
    default:
      break;
    }
  }
}