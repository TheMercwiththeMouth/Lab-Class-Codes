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

float profit_calc(struct Bag bags[], int n, int m)
{
    int i;
    float maxProfit=0.0;
    for(i=0; i<n; i++)
    {
        if(m>=bags[i].weight)
        {
            m=m-bags[i].weight;
            maxProfit+=(float)bags[i].profit;
        }
        else
        break;
    }
    maxProfit+= (bags[i].ratio)*m;
    return maxProfit;
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
        bags[i].ratio=((float)bags[i].profit/bags[i].weight);
    }
    cout<<"Enter the total allowable weight by the knapsack:\n";
    cin>>m;

    start=clock();

    sort(bags, bags+n, sortBag);

    cout<<"The sorted price ratio array is:\n";
    for(int i=0; i<n; i++)
    {cout<<bags[i].ratio<<", ";}

    cout<<"\nThe total maximum profit obtained is "<<profit_calc(bags, n, m);
    end=clock();
    exec_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nThe execution time is %lf", (double)exec_time);
    return 0;
}