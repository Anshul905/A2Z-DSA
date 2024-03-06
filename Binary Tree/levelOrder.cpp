// return vector<vector<int>>

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root)
        q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            TreeNode* cur = q.front() ;
            q.pop();
            level.push_back(cur->val);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        ans.push_back(level);
    }
    return ans;
    
}



// return vector<int>

vector<int> levelOrder(TreeNode<int> * root){
    vector<int> ans;
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        auto cur = q.front() ;
        q.pop();
        ans.push_back(cur->data);
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }
    return ans;
}
