#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
void selSort(int arr[], int n)
{
    int i, j, min_idx;
    for(i=0; i<n-1; i++)
    {
        min_idx=i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
            
        }
        if(min_idx!=i)
        {
            int temp=arr[min_idx];
            arr[min_idx]=arr[i];
            arr[i]=temp;
        }
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
    selSort(arr, n);
    end = clock();
    exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\nThe sorted array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    printf("The execution time is %lf", (double)exec_time);
}
