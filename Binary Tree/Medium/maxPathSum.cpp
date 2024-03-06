int check(TreeNode* root , int& pathSum){
    if(!root)
        return 0;
    // taking negative will reduce the sum 
    int ls = max(0,check(root->left, pathSum));
    int rs = max(0,check(root->right, pathSum));
    pathSum = max(pathSum , root->val+ls+rs );
    return root->val+max(ls,rs);
}


int maxPathSum(TreeNode* root) {
    int pathSum = INT_MIN;
    check(root,pathSum);
    return pathSum;

}



// ignore negative sum if left or right is returning 