bool fun(TreeNode* root, int l, int r) {
    if(!root)
        return true;
    if( root->val<l || root->val>r)
        return false;

    //avoid overflow range 
    if( root->val==INT_MIN  ){
        if(root->left)
            return false;
        return fun(root->right,root->val+1,r);
    }
    if( root->val==INT_MAX  ){
        if(root->right)
            return false;
        return fun(root->left,l,root->val-1);
    }

    return fun(root->left,l,root->val-1) && fun(root->right,root->val+1,r) ;
}
bool isValidBST(TreeNode* root) {
    return fun(root,INT_MIN,INT_MAX);
}


// -2^31 <= Node.val <= 2^31 - 1
// INT_MIN to INT_MAX

bool fun(TreeNode* root, long l, long r) {
    if(!root)
        return true;
    if( root->val<l || root->val>r)
        return false;
    return  fun(root->left,l,static_cast<long>(root->val)-1) && fun(root->right,static_cast<long>(root->val)+1,r) ;
}
bool isValidBST(TreeNode* root) {
    return fun(root,LLONG_MIN,LLONG_MAX);
}

