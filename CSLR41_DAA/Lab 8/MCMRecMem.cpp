#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/* A   *   B   *   C   *   D
  2*3     3*3     3*4     4*5*/
//Matrices Dimensions Vector
vector<int> dim;

int recmemMCM(vector<int>& dim, int i, int j, vector<vector<int>>& memo) {
    if (i == j) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; ++k) {
        int cost = recmemMCM(dim, i, k, memo) +
                   recmemMCM(dim, k+1, j, memo) +
                   dim[i-1] * dim[k] * dim[j];
        if (cost < minCost) {
            minCost = cost;
        }
    }

    memo[i][j] = minCost;
    return minCost;
}


int main(){
    int n, d;
    cout<<"Enter the number of matrices to be multiplied:\n";
    cin>>n;
    cout<<"Enter the dimensions of the matrices as d0, d1,...dn etc where do*d1 is for A, d1*d2 is for B and so on:\n";
    for(int i=0; i<=n; i++){
        cout<<"d"<<i<<": ";
        cin>>d;
        dim.push_back(d);
    }
    vector<vector<int>> memo(dim.size(), vector<int>(dim.size(), -1));
    cout<<"The minimum number of matrix multiplications required is: "<< recmemMCM(dim, 1, n, memo);
}