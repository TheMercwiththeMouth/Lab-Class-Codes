#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <math.h>
using namespace std;
#define N1 2
#define N2 100
void rand_arr(int num[], int n)
{
    int len=n, i, r, temp;

    for(temp=0, i=1; temp<len; i++, temp++)
    {
        num[temp]=i;
    }
    srand(time(NULL));

    for(i=len-1; i>0; i--){
        r=rand()%i;
        temp=num[i];
        num[i]=num[r];
        num[r]=temp;
    }
}
int main()
{
    clock_t start, end;
    double exec_time;
        int n, i, j, val, search, check=0;
    printf("Enter the number of elements in the array:\n");
    cin>>n;
    int arr[n];

    rand_arr(arr, n);
    
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
  
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
        }
    }
    end = clock();
    exec_time = ((double)(end - start))/CLOCKS_PER_SEC;
    cout << "\nThe sorted array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "the execution time is " << exec_time;
}
