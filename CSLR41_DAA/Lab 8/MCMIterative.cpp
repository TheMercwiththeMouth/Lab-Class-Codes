#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 100
int M[SIZE][SIZE];
// A   *   B   *   C   *   D
//2*3     3*3     3*4     4*5
//Dimensions of the matrix vector
vector<int> dim;
int MCM(vector<int>&dim){
    int n = dim.size() - 1;
    vector<vector<int>> m(n+1, vector<int>(n+1, 0));
    for(int i=0; i<=n;i++){
        m[i][i]=0;
    }
       for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k+1][j] + dim[i-1] * dim[k] * dim[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n];
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
    cout<<"The minimum number of matrix multiplications required is: "<< MCM(dim);
}


// int recursiveSolution(vector<int>& p, int i, int j) {
//     if (i == j) {
//         return 0;
//     }

//     int minCost = INT_MAX;

//     for (int k = i; k < j; ++k) {
//         int cost = recursiveSolution(p, i, k) +
//                    recursiveSolution(p, k+1, j) +
//                    p[i-1] * p[k] * p[j];
//         if (cost < minCost) {
//             minCost = cost;
//         }
//     }

//     return minCost;
// }

// int recursiveMemoization(vector<int>& p, int i, int j, vector<vector<int>>& memo) {
//     if (i == j) {
//         return 0;
//     }

//     if (memo[i][j] != -1) {
//         return memo[i][j];
//     }

//     int minCost = INT_MAX;

//     for (int k = i; k < j; ++k) {
//         int cost = recursiveMemoization(p, i, k, memo) +
//                    recursiveMemoization(p, k+1, j, memo) +
//                    p[i-1] * p[k] * p[j];
//         if (cost < minCost) {
//             minCost = cost;
//         }
//     }

//     memo[i][j] = minCost;
//     return minCost;
// }

// int main() {
//     vector<int> p = {30, 35, 15, 5, 10, 20, 25};

//     // Iterative solution
//     cout << "Iterative solution: " << iterativeSolution(p) << endl;

//     // Recursive solution
//     cout << "Recursive solution: " << recursiveSolution(p, 1, p.size()-1) << endl;

//     // Recursive solution with memoization
//     vector<vector<int>> memo(p.size(), vector<int>(p.size(), -1));
//     cout << "Recursive solution with memoization: " << recursiveMemoization(p, 1, p.size()-1, memo) << endl;

//     return 0;
// }
