int heightLeft(TreeNode* root){
    int cnt=0;
    while(root){
        cnt++;
        root = root->left;
    }
    return cnt;
}
int heightRight(TreeNode* root){
    int cnt=0;
    while(root){
        cnt++;
        root = root->right;
    }
    return cnt;
}

int countNodes(TreeNode* root) {
    if(!root)
        return 0;

    int lh = heightLeft(root);
    int rh = heightRight(root);
    if(lh==rh)
        return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}

// its not O(n) but log(n)*log(n)
// heightLeft or heightRight takes log(n) time and 
// maximum no. of node you will travel is log(n)+few nodes of right side [ extreme left side + not complete right part   ] 

