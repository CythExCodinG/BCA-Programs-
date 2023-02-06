#include <stdio.h>

void swap_no(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertion_sort(int arr[], int n)
{
  int i, j = 0;
  for (i = 1; i < n; i++)
  {
    int key = arr[i];
    for (int j = i - 1; j >= 0; j--)
    {
      if (key < arr[j])
      {
        swap_no(&arr[j], &arr[j + 1]);
      }
    }
  }
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
  insertion_sort(arr, n);
  printf("\nThe array :");
  printf("\n");
  printarray(arr, n);
}

// int temp = arr[i];
// j = i - 1;
// while (j >= 0 && arr[j] > temp)
// {
//   arr[j + 1] = arr[j];
//   j--;
// }
// arr[j + 1] = temp;