int check( TreeNode *root ){
    if(!root)
        return 0;
    int lh = check(root->left);
    if(lh==-1)return -1;
    int rh = check(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    return 1+max(lh,rh);
}

bool isBalancedBT(TreeNode* root){
    return check(root)!=-1;
}

// TC : O(n)
// SC : O(n)

// height wale me check karlo , if diff is more than 1 --> return -1 
// at last if it return -1 then not balanced tree else it is 