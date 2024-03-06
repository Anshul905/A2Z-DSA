void makeParent(TreeNode* root  , unordered_map< TreeNode* , TreeNode* > &parent ){

queue<TreeNode*> q;
q.push(root);

while(!q.empty()){
    auto cur = q.front() ;
    q.pop();
    if(cur->left){
        q.push(cur->left);
        parent[cur->left] = cur;
    }
    if(cur->right){
        q.push(cur->right);
        parent[cur->right] = cur;
    }
}
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {

    unordered_map< TreeNode* , TreeNode* > parent ;

    makeParent(root,parent);

    unordered_map< TreeNode* , bool > vis ;
    queue<TreeNode*> q;
    q.push(target);
    vis[target]=true;

    int level=0;
    while(!q.empty()){
        int n = q.size();
        if(level==K)
            break;
        for(int i=0;i<n;i++){
            auto cur = q.front() ;
            q.pop();
            if(cur->left && !vis[cur->left]){
                q.push(cur->left);
                vis[cur->left] = true;
            }
            if(cur->right && !vis[cur->right]){
                q.push(cur->right);
                vis[cur->right] = true;
            }
            if(parent[cur] && !vis[parent[cur]]){
                q.push(parent[cur]);
                vis[parent[cur]] = 1;
            }
        }
        level++;
    }

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back( q.front()->val );
        q.pop();
    }


    return ans;
    
}



// normay tree child --> downward hote hai 
// but iske parents ko bhi child jaise treat karna hoga 
// then only we can get answer 

// so first points the nodes to parent --> get the parent array 
// then push the target node ( that is given in the question ) in the queue and find all the nodes that are present at distance K ( that is K level if starts from 0 ) , once you reach k level , break it and whatever element are there in the queue is your answer 