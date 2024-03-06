int widthOfBinaryTree(TreeNode* root) {
    
    queue<pair<TreeNode*,long long int>> q;
    if(root)
        q.push({root,1});
    
    int ans=1;
    while(!q.empty()){

        int  n = q.size();
        int  minN = 0;
        int  maxN = 0;

        int minNO = q.front().second;

        for( int i=0;i<n;i++){
            TreeNode* cur = q.front().first ;
            long long int no = q.front().second-minNO ;
            q.pop();
            
            if(i==0)
                minN = no;
            if(i==n-1)
                maxN = no;

            if(cur->left)
                q.push({cur->left,(2*no)+1});
            if(cur->right)
                q.push({cur->right,(2*no)+2});
        }
        ans = max(ans,maxN-minN+1);
    }
    return ans;
}
