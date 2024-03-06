TreeNode* findLastNode( TreeNode* root ){
    while(root->right)
        root = root->right;
    return root;
}
TreeNode* helper( TreeNode* root ){
    if(!root->left){
        return root->right;
    }else if(!root->right){
        return root->left;
    }else{  
        TreeNode* rightSide = root->right;
        TreeNode* lastNode = findLastNode(root->left) ;
        lastNode->right = rightSide;
        return root->left;
    }
}
TreeNode* deleteNode(TreeNode* root, int key) {

    if(!root)
        return nullptr;
    if(root->val == key)
        return helper(root);

    TreeNode* dummy = root ;
    while(root){
        if( root->val > key ){
            if( root->left && root->left->val==key ){  
                root->left = helper(root->left);
                break;
            }else{
                root = root->left ;
            }
        }else{
            if( root->right && root->right->val==key ){
                root->right = helper(root->right);
                break;
            }else{
                root = root->right ;
            }
        }
    }
    return dummy;
}


// simple 
// connect the right most from left to first of right side , so order will be maintained and remove the link of deleted node

// helper function --> it connect right most guy from left subtree ( maximum from left ) to first of right subtree ( min from right )  
// return what need to be connected with root in order to remove the link 
