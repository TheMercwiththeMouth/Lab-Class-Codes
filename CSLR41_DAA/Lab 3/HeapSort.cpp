#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyFunction(int arr[], int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[max])
        max = l;
 
    if (r < n && arr[r] > arr[max])
        max = r;
 
    if (max != i) {
        swap(&arr[i], &arr[max]);
        heapifyFunction(arr, n, max);
    }
}
 
void hSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyFunction(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapifyFunction(arr, i, 0);
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
    hSort(arr, n);
    end = clock();
    exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nThe sorted array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    printf("The execution time is %lf", (double)exec_time);
}
