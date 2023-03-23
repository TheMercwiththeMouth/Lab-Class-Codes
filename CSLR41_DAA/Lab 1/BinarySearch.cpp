#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
    clock_t start, end;
    double exec_time;
    int n, i, search, key=0;
    cout<<"Enter the number of elements in the array:\n";
    cin>>n;
    int array[n];
    for(i=0; i<n; i++)
    {
        array[i]=i+1;
    }
    start=clock();
    cout<<"Enter the element youd like to search:\n";
    cin>>search;
    int low, high, mid;
    low=array[0];
    high=array[n];
    while(low<high)
    {
        mid=(high+low)/2;
        if(mid==search){
            key=1;
            break;
        }
        else if (search<mid)
        high=mid-1;
        else
        low=mid+1;
    }
    end=clock();
    exec_time=((double)(end-start));
    if(key==1)
    cout<<"Element is found"<<endl;
    else
    cout<<"Element is not found"<<endl;
    cout<<"the execution time is "<<exec_time;

    return 0;
}