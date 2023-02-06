#include <stdio.h>
int linear_search(int arr[], int target, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
    {
      printf("Element Found At Index :%d", i);
    }
  }
  return 0;
}

int printarray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
}
int main()
{
  int n;
  printf("\nEnter Total No of Elements :");
  scanf("%d", &n);
  int arr[n];
  printf("\nEnter %d Elements :", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("\nThe array :");
  printarray(arr, n);
  int target;
  printf("\nEnter Element to Search :");
  scanf("%d", &target);
  linear_search(arr, target, n);
}