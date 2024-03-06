#include <iostream>
#include <vector>
using namespace std;

void bfs(){

}
void dfs(){

}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Connected Component
    int vis[n+1] = {0};
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            // bfs(i);
            // dfs(i);
        }
    }


    return 0;
}