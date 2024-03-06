BinaryTreeNode<int>* makeParent(BinaryTreeNode<int>* root  , unordered_map< BinaryTreeNode<int>* , BinaryTreeNode<int>* > &parent , int start){

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* ans ;
    while(!q.empty()){
        auto cur = q.front() ;
        q.pop();
        
        if(start==cur->data)
            ans = cur;

        if(cur->left){
            q.push(cur->left);
            parent[cur->left] = cur;
        }
        if(cur->right){
            q.push(cur->right);
            parent[cur->right] = cur;
        }
    }

    return ans;
}



int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    unordered_map< BinaryTreeNode<int>* , BinaryTreeNode<int>* > parent ;

    BinaryTreeNode<int>* target = makeParent(root,parent,start);


    unordered_map< BinaryTreeNode<int>* , bool > vis ;
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    vis[target]=true;

    int level=0;
    while(!q.empty()){
        int n = q.size();
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
        if(q.size())
            level++;
    }
 
    return level;
}

// similar to ( get the nodes at k distance )
// but we want the no. of level here , so we wont break but count the level and return it 