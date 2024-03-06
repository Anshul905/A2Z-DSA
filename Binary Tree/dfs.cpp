void preorder(TreeNode* root,vector<int> &ans){
    if(!root)
        return ;
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
}

void inorder(TreeNode* root,vector<int> &ans){
    if(!root)
        return ;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

void postorder(TreeNode* root,vector<int> &ans){
    if(!root)
        return ;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
}




vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root,ans);
    return ans;
}


