#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
#define N1 2
#define N2 10000
int prqueue[1000];
int size=-1;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[max])
        max = l;
 
    if (r < n && arr[r]> arr[max])
        max = r;
 
    if (max != i) {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}
void insertElement(int value)
{
    size+=1;
    prqueue[size]=value;
    //prqueue[size].priority=priority;
    heapify(prqueue, size);
}
int deleteElement()
{
    int delement=prqueue[0];
    for(int i=0; i<size; i++)
    {
        prqueue[i]=prqueue[i+1];
    }
    size--;
    return delement;
}
int findMax()
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
    int n, i, j;
    printf("Enter the number of elements in the array:\n");
    cin >> n;
    int arr[n];
    rand_arr(arr, n);
    cout<<"Elements to be inserted into the queue:\n";
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<", ";
    }
    start = clock();
    cout<<"The Priority Queue:\n";
    for (i = 0; i < n; i++)
    {
       insertElement(arr[i]); 
    }
    heapify(prqueue, n);
    
    for(i=0; i<=size; i++)
    {
        cout<<prqueue[i]<<", ";
    }
    cout<<"Enter an element to be inserted into the priority queue:\n";
    cin>>j;
    insertElement(j);

    for(i=0; i<=size; i++)
    {
        cout<<prqueue[i]<<", ";
    }
    cout<<"Dequeuing the Queue:\n";
    cout<<deleteElement()<<endl;

    
   
    cout<<"The min element in the priority queue is "<<prqueue[0]<<endl;
    cout<<"The max element in the priority queue is "<<deleteElement()<<endl;
    end = clock();
    exec_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    
    printf("The execution time is %lf", (double)exec_time);
}
