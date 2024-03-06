int height( TreeNode *root ){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh,rh);
}
int maxDepth(TreeNode* root) {
    return height(root);
}

// root --> 1
// can also use level order traversal 

int heightOfBinaryTree(TreeNode<int> *root)
{
    if(!root)
        return 0;
    int lh = heightOfBinaryTree(root->left);
    int rh = heightOfBinaryTree(root->right);
    return 1+max(lh,rh);
}


// TC : O(n)
// SC : O(n)

