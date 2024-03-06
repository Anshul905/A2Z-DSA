void fun(TreeNode* root,TreeNode* &pre){
    if(!root)
        return ;
    fun(root->right,pre); 
    fun(root->left,pre); 
    root->right = pre ;
    root->left = nullptr ;
    pre = root ;
}
void flatten(TreeNode* root) {
        TreeNode* pre = nullptr ;
        fun(root,pre);
}



TC -> n 
SC -> n


order of linked list hosuld be same as pre-order ( Root left right )
 1
2  3
pre-order = [ 1 2 3 ]
linked list should be like 1->2->3 ( right link ) and left link to null 

Root -> left -> right 
so  better if we traverse right first and make linked list from right subtree ( join left to right ) and then complete left ( join root to left subtree )





