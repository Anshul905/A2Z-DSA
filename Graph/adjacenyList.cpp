#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}


// vector<vector<int>> graph
for(auto e: graph)
{
    adj[e[0]-1].push_back(e[1]-1);
    adj[e[1]-1].push_back(e[0]-1);
}

// 2d array 
vector<int> adj[n];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(graph[i][j]==1)  
            adj[i].push_back(j);
    }
}


// vector of vector to array of vector 
vector<int> adj[n];
for(int i=0;i<n;i++){
    for(auto  x:graph[i] )
    adj[i].push_back(x);
}

