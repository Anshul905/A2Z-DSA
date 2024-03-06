void rightBoundary(TreeNode<int>* root,vector<int> &ans){
    if(!root)
        return ;
    if(!root->left && !root->right)
        return ;
    if(root->right)
        rightBoundary(root->right,ans);
    else
        rightBoundary(root->left,ans);
    ans.push_back(root->data);
} 

void leftBoundary(TreeNode<int>* root,vector<int> &ans){
    if(!root)
        return ;
    if(!root->left && !root->right)
        return ;

    ans.push_back(root->data);
    if(root->left)
        leftBoundary(root->left,ans);
    else
        leftBoundary(root->right,ans);
} 



void leaf(TreeNode<int>* root,vector<int> &ans){
    if(!root)
        return ;
    if(!root->left && !root->right)
        ans.push_back(root->data);
    leaf(root->left,ans);
    leaf(root->right,ans);
}


vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;

    if(root)
        ans.push_back(root->data);

    leftBoundary(root->left,ans);
    leaf(root,ans);
    rightBoundary(root->right,ans);
    return ans;
}


// left me check if its null or leaf node , if its do nothing else store it and go on left n left if not left then go right 
// leaf me kuch bhi lagao , store when its a leaf
// left me check if its null or leaf node , if its do nothing else go on right n right if not go right then go left and store it  
