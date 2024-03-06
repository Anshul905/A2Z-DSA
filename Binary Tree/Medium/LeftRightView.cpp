vector<int> rightSideView(TreeNode* root) {
    map<int,int > m;
    vector<int> ans;
    queue< TreeNode* > q;
    
    if(root)
        q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            TreeNode* cur = q.front() ;
            q.pop();

            //left view 
            if(i==0) // i==n-1 for right view 
                ans.push_back(cur->val);
            
            
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    return ans;
}


// simple level order with for loop wala 
// i==0 --> push , Left view 
// i==n-1 --> push , Right view 
