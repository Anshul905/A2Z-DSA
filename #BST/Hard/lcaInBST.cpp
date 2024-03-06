TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(!root)
        return nullptr;
    if( root->val > p->val && root->val > q->val )
        return lowestCommonAncestor(root->left,p,q);
    if( root->val < p->val && root->val < q->val )
        return lowestCommonAncestor(root->right,p,q);

    return root;
}


// if both smaller move left , if both bigger move right 
// else cases are 
//     one one in diff side --> return root 
//     root is the one , and one in left or right --> return root 

// so just check for when to move left and right
