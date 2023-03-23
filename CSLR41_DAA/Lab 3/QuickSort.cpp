#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define N1 2
#define N2 10000
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int fp = low-1;

    for (int i=low; i<high; i++) {
        if (arr[i] < pivot) {
            fp++; swap(&arr[i], &arr[fp]);
        }
    }
    swap(&arr[fp+1], &arr[high]);
    return fp+1;
}

void qSort(int arr[], int low, int high) {
    if (low < high) {
        int piv = partition(arr, low, high);
        qSort(arr, low, piv-1);
        qSort(arr, piv+1, high);
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
    qSort(arr, 0, n-1);
    end = clock();
    exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nThe sorted array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    printf("The execution time is %lf", (double)exec_time);
}
