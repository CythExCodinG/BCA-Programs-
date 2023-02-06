#include <stdio.h>
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int a[5] = {8, 3, 6, 5, 1};
    bubblesort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
}
