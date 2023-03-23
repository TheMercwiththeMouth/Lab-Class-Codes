#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <time.h>
#include <math.h>
using namespace std;
#define N1 2
#define N2 100000000

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
    int n, i, val, search, check=0;
    printf("Enter the number of elements in the array:\n");
    cin>>n;
    int num[n];

    rand_arr(num, n);
    
    for (i = 0; i < n; i++)
    {
        cout << num[i] << ", ";
    }
    printf("Enter the element to be found:\n");
    cin>>search;
    start=clock();
    for(i=0; i<n; i++)
    {
        if(num[i]==search)
        {
            check=i;
            break;
        }
    }
    end=clock();
    exec_time=((double)(end-start))/(CLOCKS_PER_SEC);
    if(check==0)
    printf("Element is not found. :(");
    else
    cout<<"Element is found at position "<<check+1;
    printf("the execution time is %lf.\n", exec_time);
    return 0;
}

    