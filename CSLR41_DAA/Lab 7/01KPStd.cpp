#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Bag{
    int weight;
    int profit;
    float ratio;
};
bool sortBag(Bag a, Bag b)
{
    if(a.ratio>b.ratio)
      return true;
    return false;
}
int maxProfit(int a, int b){
    if(a>b)
    return a;
    else
    return b;
}
int KPS(struct Bag bags[], int n, int w){
    int A[n+1][w+1];
    if(n==0 || w==0){
        return 0;
    }
    else if(bags[n-1].weight>w){
        A[n][w]=KPS(bags, n-1, w);
    }
    else
    {
        A[n][w]= maxProfit(bags[n-1].profit+KPS(bags,n-1, w-bags[n-1].weight),KPS(bags, n-1, w));
    }
    return A[n][w];
}
int main()
{
    clock_t start, end;
    double exec_time;
    int m, n;
    
    cout<<"Enter the total number of bags to choose from:\n";
    cin>>n;
    struct Bag bags[n];

    cout<<"Enter the weight and profit obtained from each bag:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Bag "<<i+1<<endl;
        cin>>bags[i].weight>>bags[i].profit;
    }
    cout<<"Enter the total allowable weight by the knapsack:\n";
    cin>>m;

    start=clock();
    cout<<"The maximum profit that can be obtained is "<< KPS(bags,n,m);

    end=clock();
    exec_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nThe execution time is %lf", (double)exec_time);
    return 0;
}