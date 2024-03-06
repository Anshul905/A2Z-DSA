TreeNode* fun(vector<int>& preorder, int preStart, int preEnd ,  unordered_map<int, int> &m,
                    vector<int>& inorder, int inStart, int inEnd) {
    if ( inStart>inEnd || preStart>preEnd   )
        return nullptr;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int ind = m[root->val];
    int leftSize = ind-inStart;

    root->left = fun(preorder, preStart+1, preStart+ leftSize , m, inorder, inStart, ind - 1);
    root->right = fun(preorder,  preStart+ leftSize+1 , preEnd , m, inorder, ind + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> m;
    for (int i = 0; i < preorder.size(); i++)
        m[inorder[i]] = i;

    return fun(preorder, 0, preorder.size()-1, m, inorder, 0, inorder.size() - 1);
}


// leftSize = m[root->data] - inStart 
// left  --->>> preStart + 1                     to    preStart + leftSize  
// right  --->>> preStart + leftSize  + 1        to     preEnd
