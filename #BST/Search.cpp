TreeNode* searchBST(TreeNode* root, int val) {
    if(!root)
        return nullptr;
    if( root->val==val )
        return root;
    if( root->val > val )
        return searchBST(root->left,val);
    return searchBST(root->right,val);
}


TreeNode* searchBST(TreeNode* root, int val) {
    while(root && root->val!=val){
        root = root->val>val ? root->left : root->right ; 
    }
    return root;
}

