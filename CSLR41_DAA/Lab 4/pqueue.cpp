#include<bits/stdc++.h>
#include<time.h>

using namespace std;

int n;

void random(int num[], int n)
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

void heapify(int arr[], int N, int i)
{

	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < N && arr[l] > arr[largest])
		largest = l;
	if (r < N && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, N, largest);
	}
}

void reverse_heapify(int arr[], int n, int i)
{
    int par = (i - 1) / 2;
 
    if (arr[par] > 0) {
        if (arr[i] > arr[par]) {
            swap(arr[i], arr[par]);
            reverse_heapify(arr, n, par);
        }
    }
}

void Insertion(int arr[])
{
    int val;
    cout<<"Enter the val to insert : ";
    cin>>val; 
    n +=1;
    arr[n - 1] = val;
    reverse_heapify(arr, n, n - 1);
}

void Deletion(int arr[]){
    
    arr[0]=arr[n-1];
    n=n-1;
    heapify(arr,n,0);

}

void print(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}




int main(){
    
    int* arr;
    cout<<"Please enter the number of elements: ";
    cin>>n;
    arr= new int[1000000];
    random(arr,n);
    print(arr,n);
    

    for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

    printf("Successfully created the max heap:\n");


    print(arr,n);
    clock_t t= clock();

    Deletion(arr);
    t=clock()-t;
    double time=((double)t)/ CLOCKS_PER_SEC;

    print(arr,n);
    printf("Time taken in seconds : %f ",time);
    clock_t x= clock();
    Insertion (arr);
    print(arr,n);
    x= clock()-x;
    double time_taken =((double)x)/ CLOCKS_PER_SEC;
    printf("Time taken in seconds : %f ",time_taken);
    return 0;
}