#include<bits/stdc++.h>
using namespace std;
#define n 5
#define m 3
int allocation[n][m];
int maxi[n][m];
int need[n][m] ;
int available[m];
bool bankers()
{
    int flag=0;
    bool finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i]=false;
    }
    vector<int> safeSeq;
    // int work[m];
    // for(int i=0; i<m; i++){
    //     work[i]=available[i];
    // }
    int count = 0;
    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == false)
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if (j == m)
                {
                    for (int k = 0; k < m; k++)
                    {
                        available[k] += allocation[i][k];
                    }
                    safeSeq.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (found == false)
        {
            cout << "The system is not in safe state" << endl;
            return false;
            
        }
    }
    cout << "The system is in safe state i.e. there are no deadlocks." << endl;
    cout << "The safe sequence is" << endl;
    for (int i = 0; i < safeSeq.size()-1; i++)
    {
        cout <<"P"<<safeSeq[i] << " -> ";
    }
    cout <<"P"<<safeSeq[safeSeq.size()-1]<<endl;
    cout<<"The final available instances in the memory is:\n";
    for(int i=0; i<m; i++){
        cout<<available[i]<<" ";
    }
    cout << endl;
    return true;
}
int main(void)
{
    // cout << "Enter the number of processes" << endl;
    // cin >> n;
    // cout << "Enter the number of resources" << endl;
    // cin >> m;
    cout << "Enter the allocation matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"For Process "<< i<<endl;
        for(int j=0; j<m; j++){
            cin>>allocation[i][j];
        }
    }
    cout << "Enter the maximum matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"For Process "<< i<<endl;
        for(int j=0; j<m; j++){
            cin>>maxi[i][j];
        }
    }
    cout << "Enter the available matrix" << endl;
    for (int i = 0; i < m; i++)
    {
       cin>>available[i];
    }


    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<m; j++){
            need[i][j]=maxi[i][j]-allocation[i][j];
        }
      
    }
    bankers();
    return 0;
}
