#include <stdio.h>
int partition(int arr[], int lb, int ub)
{
  int pivot = arr[lb];
  int i = lb + 1;
  int j = ub;
  do
  {
    while (arr[i] <= pivot && i <= ub)
    {
      i++;
    }
    while (arr[j] > pivot && j >= lb)
    {
      j--;
    }
    if (i < j)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  } while (i < j);
  int temp = arr[lb];
  arr[lb] = arr[j];
  arr[j] = temp;
  return j;
}
void quicksort(int arr[], int lb, int ub)
{
  if (lb < ub)
  {
    int loc = partition(arr, lb, ub);
    quicksort(arr, lb, loc - 1);
    quicksort(arr, loc + 1, ub);
  }
}
int main()
{
  int arr[7] = {9, 8, 7, 6, 5, 4, 1};
  quicksort(arr, 0, 6);
  for (int i = 0; i < 7; i++)
  {
    printf("%d ", arr[i]);
  }
}