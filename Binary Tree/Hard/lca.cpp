TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(!root)
        return nullptr ;

    if( root==p || root==q ){
        return root;
    }

    TreeNode* l = lowestCommonAncestor(root->left,p,q);     
    TreeNode* r = lowestCommonAncestor(root->right,p,q);

    if(!l)
        return r;
    if(!r)
        return l;
    return root;
}


// if left is null  ( nothign in left side ) -> return right 
// if right is null ( nothign in right side ) -> return left 
// if both are not null --> that means we got lca and return root 

// base condition 
//     if got any value -> return that node , no need to go further ( as even if we didnt get other value from other side that means other value was down the returned node )

//     if node is null then return null 

