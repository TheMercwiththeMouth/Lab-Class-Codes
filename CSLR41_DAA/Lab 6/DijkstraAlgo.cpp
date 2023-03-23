#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define MAX 7

/*adjMat:   0   1   2   3   4   5
        0   0   5  10   0   0   0
        1   0   0   0   7   9   0
        2   0  15   0  20   0   0
        3   0   0   0   0   0  10
        4   0   0   0   8   0   0
        5   0   0   0   0  11   0
*/
vector<int>shpath;
int adjMat[MAX][MAX]={{0,2,6,0,0,0,0},
        {2,0,0,5,0,0,0},
        {6,0,0,8,0,0,0},
        {0,5,8,0,10,15,0},
        {0,0,0,10,0,6,2},
        {0,0,0,15,6,0,6},
        {0,0,0,0,2,6,0}};
int vertex_dist[MAX];
int visited [MAX];
int total_dist=0;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

void initialize(int start){
    for (int i = 0; i < MAX; i++)
    {
        if (i != start)
        {
            vertex_dist[i]= INT_MAX;
            visited[i]=0;
            pq.push(make_pair(vertex_dist[i], i));
        }
        if (i == start){
            vertex_dist[start]= 0;
            visited[start]=1;
            pq.push(make_pair(vertex_dist[i], i));
        }
    }
}

void relaxEdges(int u, int v){
    if(visited[v]==0 && adjMat[u][v]!=0 && (vertex_dist[v]>vertex_dist[u]+adjMat[u][v])){
        vertex_dist[v]=vertex_dist[u]+adjMat[u][v];
        pq.push(make_pair(vertex_dist[v], v));

    }
        
}
void dijkstra(int start)
{
    shpath.push_back(start);
    visited[start]=1;
    while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    for(int i=0; i<MAX; i++){
        
        relaxEdges(u,i);
        
    }
    dijkstra(u);}
}
void display(){
    cout<<"The shortest path is:\n";
    for(int i=1; i<shpath.size()/2+1; i++){
        cout<<shpath[i]<<"->";
       
    }

}
int main(){
    int start;
    cout<<"Enter the start vertex:\n";
    cin>>start;

    initialize(start);
    dijkstra(start);
    display();
    cout<<"\nThe shortest path is: "<<total_dist;
    return 0;
}