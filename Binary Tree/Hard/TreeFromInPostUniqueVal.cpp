TreeNode* fun(vector<int>& postorder, int postStart, int postEnd ,  unordered_map<int, int> &m,
                    vector<int>& inorder, int inStart, int inEnd) {
    if ( inStart>inEnd || postStart>postEnd   )
        return nullptr;

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int ind = m[root->val];
    int leftSize = ind-inStart;

    root->left = fun(postorder, postStart, postStart+leftSize-1 , m, inorder, inStart, ind - 1);
    root->right = fun(postorder,  postStart+ leftSize , postEnd-1 , m, inorder, ind + 1, inEnd);

    return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> m;
    for (int i = 0; i < postorder.size(); i++)
        m[inorder[i]] = i;

    return fun(postorder, 0, postorder.size()-1, m, inorder, 0, inorder.size() - 1);
}


// leftSize = m[root->data] - inStart

// left  --->>>     postStart                to    postStart + leftSize - 1 
// right  --->>>    postStart + leftSize     to     postEnd - 1