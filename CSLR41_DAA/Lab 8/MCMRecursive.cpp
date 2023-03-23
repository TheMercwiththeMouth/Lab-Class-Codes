#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/* A   *   B   *   C   *   D
  2*3     3*3     3*4     4*5*/
//Matrices Dimensions Vector
vector<int> dim;

//Recursive Solution for the Matrix Chain Multiplication Program
int recMCM(vector<int>& dim, int i, int j) {
    if (i == j) {
        return 0;
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; ++k) {
        int cost = recMCM(dim, i, k) +
                   recMCM(dim, k+1, j) +
                   dim[i-1] * dim[k] * dim[j];
        if (cost < minCost) {
            minCost = cost;
        }
    }

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
    cout<<"The minimum number of matrix multiplications required is: "<< recMCM(dim, 1, n);
}