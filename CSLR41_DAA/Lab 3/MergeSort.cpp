#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define N1 2
#define N2 10000
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int temp[N2 - N1 + 1];
    int i = l, j = mid + 1, idx = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[idx++] = arr[i];
            i++;
        }
        else
        {
            temp[idx++] = arr[j];
            j++;
        }
    }
    while (i <= mid)
    {
        temp[idx++] = arr[i];
        i++;
    }
    while (j <= r)
    {
        temp[idx++] = arr[j];
        j++;
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}

void m_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        m_sort(arr, l, mid);
        m_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
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
    m_sort(arr, 0, n - 1);
    end = clock();
    exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nThe sorted array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    printf("The execution time is %lf", (double)exec_time);
}
