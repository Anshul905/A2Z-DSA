void inorder(TreeNode* root,int& cnt ,int k,int& ans){
    if(!root)
        return ;
    inorder(root->left,cnt,k,ans);
    cnt++;
    if(cnt==k)
        ans = root->val ;
    inorder(root->right,cnt,k,ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans=0,cnt=0;
    inorder(root,cnt,k,ans);
    return ans;        
}


// if find largest --> using one loop get the n and then find (n-k)th smallest  