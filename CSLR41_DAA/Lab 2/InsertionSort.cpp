#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
void iSort(int arr[], int n)
{
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void rand_arr(int num[], int n)
{
    int len = n, i, r, temp;

    for (temp = 0, i = 1; temp < len; i++, temp++)
    {
        num[temp] = i;
    }
    srand(time(NULL));

    for (i = len - 1; i > 0; i--)
    {
        r = rand() % i;
        temp = num[i];
        num[i] = num[r];
        num[r] = temp;
    }
}
int main()
{
    clock_t start, end;
    double exec_time;
    int n, i, j, val, search, check = 0;
    printf("Enter the number of elements in the array:\n");
    cin >> n;
    int arr[n];

    rand_arr(arr, n);

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }

    start = clock();
    iSort(arr, n);
    end = clock();
    exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nThe sorted array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    printf("The execution time is %lf", (double)exec_time);
}
