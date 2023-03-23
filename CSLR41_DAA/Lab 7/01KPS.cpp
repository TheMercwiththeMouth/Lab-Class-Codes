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
int KPS(struct Bag bags[], int n, int w){
    int A[n+1][w+1];
    for(int i=0; i<=w; i++){
        A[0][i]=0;
    }
    for(int i=0; i<=n; i++){
        A[i][0]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if((bags[i-1].weight<=j) &&(bags[i-1].profit+A[i-1][j-bags[i-1].weight]>A[i-1][j])){
                A[i][j]=bags[i-1].profit+A[i-1][j-bags[i-1].weight];
            }
            else
            A[i][j]=A[i-1][j];
        }
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