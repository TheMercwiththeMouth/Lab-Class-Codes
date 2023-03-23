
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int n=6;
struct vertex{
    int index;
    int key;
    struct vertex* parent;
};

struct vertex* createGraph(int index,int key,struct vertex* parent){
    struct vertex* t=malloc(sizeof(struct vertex));
    t->key=key;
    t->index=index;
    t->parent=parent;
    return t;
}
//Priority Queue functions: START
void heapify(struct vertex* a[], int n, int i){
    int left, right;
    left=2*i+1;
    right=2*i+2;
    int min=i;

    if (left<n && a[left]->key<a[min]->key){
       min=left;
    }
    if (right<n && a[right]->key<a[min]->key){
       min=right;
    }
    if(min!=i){
        struct vertex* temp;
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        heapify(a,n,min);
    }
}
//inserting an element into the PQ
void insert(struct vertex* a[], int n, struct vertex* el){
    a[n]=el;
    int p;
    p=(n-1)/2;
    heapify(a,n+1,p);
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n+1,i);
    }
}
//finding the minimum element in the PQ
struct vertex* findMin(struct vertex* a[]){
    return a[0];
}
//extracting the minimum element in the PQ
struct vertex* extractMin(struct vertex* a[], int n){
    struct vertex* min=findMin(a);
    a[0]=a[n-1];
    heapify(a,n-1,0);
    return min;
}
//check if the element in present in the PQ. if yes return its index else -1
int presentPQ(struct vertex* a[],int n, int index){
    for(int i=0;i<n;i++){
        if (a[i]->index==index){
            return i;
        }
    }
    return -1;
}
void prims(int m[n][n], struct vertex* v[], struct vertex* vertices[], int n, int r){
    v[r]->key=0;
    vertices[r]->key=0;
    int count=n;
    int mstlength=0;

    for(int i=0;i<n;i++){
        heapify(vertices,n,i);}

    while(count>0){
        struct vertex* u=extractMin(vertices,count);
        printf("%d(key: %d)",u->index+1, u->key);
        mstlength+=u->key;
        count--;
        for(int i=0;i<n;i++){
            if(m[u->index][i]>0){
                    if(presentPQ(vertices,count,i)>-1 && m[u->index][i]<v[i]->key){
                        vertices[presentPQ(vertices,count,i)]->key=v[i]->key=m[u->index][i];
                        vertices[presentPQ(vertices,count,i)]->parent=v[i]->parent=u;
                    }
            }
            for(int i=0;i<n;i++){
            heapify(vertices,count,i);
        }
        }
    }
    printf("The length of the minimum spanning tree for the given graph is %d.", mstlength);
}


int main(){
    printf("implementing prim's algorithm to find minimum spanning tree\n");
    int n;
    n=6;
    
    //int m[n][n];
    int m[6][6]={{0,13,0,0,0,15},
            {13,0,7,5,0,0},
            {0,7,0,0,9,0},
            {0,5,0,0,8,11},
            {0,0,9,8,0,10},
            {15,0,0,11,10,0}};

    struct vertex* v[n];
    struct vertex* vertices[n];

    for(int i=0;i<n;i++){
        struct vertex* temp=createGraph(i,INT16_MAX,NULL);
        v[i]=temp;
        vertices[i]=temp;
    }

    printf("enter start node: ");
    int r;
    scanf("%d",&r);
    prims(m, v, vertices,  n, r);
    printf("\n");
    return 0;
}
