#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
int adj[max][max];
int n;

void create_graph()
{
  int i, max_edges, origin, destin;

  printf("Enter number of nodes : ");
  scanf("%d", &n);
  max_edges = n * n;

  for (i = 1; i <= max_edges; i++)
  {
    printf("Enter edge %d( 0 0 ) to quit : ", i);
    scanf("%d %d", &origin, &destin);
    if ((origin == 0) && (destin == 0))
      break;
    if (origin > n || destin > n || origin <= 0 || destin <= 0)
    {
      printf("Invalid edge!\n");
      i--;
    }
    else
      adj[origin][destin] = 1;
  }
}

void display()
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%4d", adj[i][j]);
    printf("\n");
  }
}
int main()
{
  int choice;
  // int node, origin, destin;
  create_graph();
  while (1)
  {
    printf("1.Dispaly\n");
    printf("2.Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      display();
      break;
    case 2:
      exit(0);
    default:
      printf("Wrong choice\n");
      break;
    }
  }
  getch();
}
