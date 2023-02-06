#include <stdio.h>
int bin_search(int arr[], int target, int n)
{
  int low = 0;
  int high = n - 1;
  while (low < high)
  {
    int mid = (low + high) / 2;
    int res = arr[mid];
    if (target == res)
    {
      return mid;
    }
    else if (target > arr[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int printarray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
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
  int res = bin_search(arr, target, n);
  if (res == -1)
  {
    printf("\n!!!!Element Not Found!!!!");
  }
  else
  {
    printf("\nElement Found At :%d", res);
  }
}
