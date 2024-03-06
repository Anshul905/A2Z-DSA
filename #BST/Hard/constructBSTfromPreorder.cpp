TreeNode* fun2(vector<int>& pre, int& ind, int r) {
    if (ind == pre.size() || pre[ind] >= r) {
        return NULL;
    }
    TreeNode* root = new TreeNode(pre[ind++]);
    root->left = fun2(pre, ind, root->val);
    root->right = fun2(pre, ind, r);
    return root;
}

TreeNode* fun(vector<int>& pre, int& ind, int l, int r) {
    if (ind == pre.size() || pre[ind] <= l || pre[ind] >= r) {
        return NULL;
    }
    TreeNode* root = new TreeNode(pre[ind++]);
    root->left = fun(pre, ind, l, root->val);
    root->right = fun(pre, ind, root->val, r);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& pre) {
    int ind = 0;
    return fun(pre, ind, INT_MIN, INT_MAX);
    // return fun2(pre, ind, INT_MAX); // using max bound only 
}









// Brute Force : ( n*n , 1 ) [ insert all node ]
//     pick a number from preorder array and insert it at correct position ( basically we will create new tree )
//     TC : n*n = n ( node ) * n ( insert , worst case if the tree is skew [ here if proorder array is sorted in any ways ] )
//     SC : 1 ( tree space is needed so considering it )


// Better : ( nlogn , n) [ using preorder and inorder ]
//     make inorder array , sorted form of preorder 
//     then just make unique tree from preorder and inorder 
//     TC : nlogn = nlogn ( sort  ) + n ( construct tree )
//     SC : n ( inorder vector )


// optimal : ( n , 1 ) [ no need of inorder array ]
//     assigning node with preorder[ind++] to the right place based on bst node range condition 

