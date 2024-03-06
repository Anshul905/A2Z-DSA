int spanningTree(int n, vector<vector<int>> graph[])
{
    int sum=0;
    vector<int> vis(n,0);

    // {w,{n,p}}
    // O(E)
    priority_queue< pair<int,pair<int,int>> , vector< pair<int,pair<int,int>> > , greater< pair<int,pair<int,int>> > >q;
    q.push( {0,{0,-1}} );
    
    // E log E + E log E == E log E
    // E
    while(!q.empty()){
        
        // log E , E is max size in priority queue
        int w=q.top().first;
        int cur=q.top().second.first;
        int par=q.top().second.second;
        q.pop();
        
        
        if(vis[cur]==1)//if already part of the MST 
            continue;
        //add it to MST
        sum+=w;
        vis[cur]=1;
        
        
        // E log E
        // E
        for(auto child:graph[cur]){
            int cn = child[0] ;
            int ew = child[1] ;
            if(!vis[cn]){
                // log E
                q.push( {ew,{cn,cur}} );
            }
        }
    }

    return sum;
}
