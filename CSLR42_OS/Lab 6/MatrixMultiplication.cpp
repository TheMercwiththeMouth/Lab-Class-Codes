#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX 10
#define MAX_THREAD 10

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i=0;
void* multiply(void *arg)
{
    int i=step_i++;
    for(int j=0; j<MAX; j++)
    {
        for(int k=0; k<MAX; k++)
        {
            matC[i][j]+= matA[i][k] * matB[k][j];    
        }
    }
    return NULL;
}

void displayMatrix(int mat[MAX][MAX])
{
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //generating the matrices A and B using random values
    srand(time(NULL));
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            matA[i][j]=rand()%10;
            matB[i][j]=rand()%10;
        }
    }
    //displaying the matrices A and B
    cout<<"Matrix A "<<endl;
    displayMatrix(matA);
    cout<<"Matrix B"<<endl;
    displayMatrix(matB);

    //declaring the number of threads
    pthread_t threads[MAX_THREAD];
    //creating threads
    for(int i=0; i<MAX_THREAD; i++)
    {
        int *p;
        pthread_create(&threads[i], NULL, multiply, (void*)(p));
    }
    //joining the threads
    for(int i=0; i<MAX_THREAD; i++)
    {
        pthread_join(threads[i], NULL);
    }
    cout<<endl;
    cout<<"The Resultant Matrix C is :\n";

    displayMatrix(matC);
    return 0;
}