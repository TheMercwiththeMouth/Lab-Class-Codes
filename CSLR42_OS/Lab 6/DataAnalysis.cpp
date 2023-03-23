#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define MAX 50
#define MAX_THREAD 10
int arr[MAX];
int sum[10] = {0};
int square_sum[10] = {0};
int part1 = 0;
int part2 = 0;
float mean, median, std_dev, var, mode;
int range;

void *sum_array(void *arg)
{

    int thread_part = part1++;
    for (int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++)
    {
        sum[thread_part] += arr[i];
    }
    return NULL;
}
void *square_sumArr(void *arg)
{
    int thread_part = part2++;
    for (int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++)
    {
        square_sum[thread_part] += arr[i] * arr[i];
    }
    return NULL;
}
void display(int arr[MAX])
{

    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i] << ", ";
    }
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {

        arr[i] = rand() % 10;
    }

    // displaying the array
    cout << "The input set of data is :\n";
    display(arr);
    pthread_t threads1[MAX_THREAD], threads2[MAX_THREAD];

    // THREAD 1 FOR THE SUM OF THE ARRAY
    for (int i = 0; i < MAX_THREAD; i++)
    {
        pthread_create(&threads1[i], NULL, sum_array, (void *)(NULL));
    }

    for (int i = 0; i < MAX_THREAD; i++)
    {
        pthread_join(threads1[i], NULL);
    }

    int total_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
    {
        total_sum += sum[i];
    }

    // THREAD 2 FOR THE SUM OF THE SQUARES
    for (int i = 0; i < MAX_THREAD; i++)
    {
        pthread_create(&threads2[i], NULL, square_sumArr, (void *)(NULL));
    }

    for (int i = 0; i < MAX_THREAD; i++)
    {
        pthread_join(threads2[i], NULL);
    }

    int sq_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
    {
        sq_sum += square_sum[i];
    }

    // Calculating the mean of the data set

    mean = (float)total_sum / MAX;

    sort(arr, arr + MAX);
    cout << "The sorted array is" << endl;
    display(arr);

    if (MAX % 2 == 0)
        median = (float)(arr[MAX / 2] + arr[(MAX / 2) + 1]) / 2;
    else
        median = (float)(arr[(MAX + 1) / 2]);

    range = arr[MAX - 1] - arr[0];
    float sq_mean= (float)sq_sum/MAX;
    
    mode=(3*median)-(2*mean);

    var = sq_mean- (mean * mean);
    std_dev = (float)sqrt(var);

    cout << "The mean of the data set is " << mean << endl;
    cout << "The median of the data set is " << median << endl;
    cout << "The range of the data set is " << range << endl;
    cout << "The standard deviation of the data set is " << std_dev << endl;
    cout << "The variance of the data set is " << var << endl;
    cout << "The mode of the data set is " << mode << endl;

    return 0;
}