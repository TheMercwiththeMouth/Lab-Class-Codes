#include<iostream>
#include<limits.h>
using namespace std;
#define V 5
#define V1 7

int mindist(int dist[],bool sset[]){
    int min =INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(sset[v]==false &&dist[v]<=min){
            min=dist[v],min_index=v;
        }
    }
    return min_index;
}
void printsol(int dist[]){
    cout<<"Vertex \t distance from source"<<endl;
    for(int i=0;i<V;i++){
        cout<<i << " \t\t\t\t"<<dist[i]<<endl;

    }
}

void dijkstra (int graph[V][V],int src){
    int dist[V];
    bool sset[V];
    for (int i=0;i<V;i++){
        dist[i]= INT_MAX,sset[i]=false;
        

    }
    dist[src]=0;
    
    for(int count=0;count<V-1;count++){
        int u = mindist(dist,sset);
        sset[u]=true;
        for(int v=0;v<V;v++){
            if(!sset[v]&& graph[u][v]&&dist[u]!=INT_MAX &&dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
       
    }
     printsol(dist);
}

void dijkstra2 (int graph[V1][V1],int src){
    int dist[V1];
    bool sset[V1];
    for (int i=0;i<V1;i++){
        dist[i]= INT_MAX,sset[i]=false;
        

    }
    dist[src]=0;
    
    for(int count=0;count<V1-1;count++){
        int u = mindist(dist,sset);
        sset[u]=true;
        for(int v=0;v<V1;v++){
            if(!sset[v]&& graph[u][v]&&dist[u]!=INT_MAX &&dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
       
    }
     printsol(dist);
}

int main(){
    /*int v;
    cout<<"ENter number of vertices in the graph: ";
    cin>>v;*/

    int graph[V][V]=
    {
        {0,10,3,0,0},
        {0,0,1,2,0},
        {0,4,0,8,2},
        {0,0,0,0,7},
        {0,0,0,9,0}
    };

    int graph2[V1][V1]={
        {0,2,6,0,0,0,0},
        {2,0,0,5,0,0,0},
        {6,0,0,8,0,0,0},
        {0,5,8,0,10,15,0},
        {0,0,0,10,0,6,2},
        {0,0,0,15,6,0,6},
        {0,0,0,0,2,6,0}
    };
    int start;
    cout<<"ENter start node ";
    cin>>start;
    
    
    
    
    dijkstra(graph,start);
    cout<<endl<<endl;
    dijkstra2(graph2,start);




                                                                                                                             
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
 
void addEdge(vector<pair<int, int> > adj[], int u, int v,
             int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
 
void shortestPath(vector<pair<int, int> > adj[], int V,
                  int src)
{
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
 
    vector<int> dist(V, INF);
 
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
 
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
int main()
{
    int V = 9;
    vector<pair<int,int>> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
 
    shortestPath(adj, V, 2);
 
    return 0;

