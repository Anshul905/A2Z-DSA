TreeNode *first , *middle , *last , *prev ;
void inorder(TreeNode* root){
    if(!root)
        return ;
    inorder(root->left);

    if( root->val < prev->val  ){
        if(!first){
            first = prev ;
            middle = root ;
        }else{
            last = root;
        }

    }
    prev = root ;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    first = middle = last = nullptr ;
    prev = new TreeNode(INT_MIN);
    
    inorder(root);

    if(first && last) swap(first->val,last->val);
    else if(first && middle)swap(first->val,middle->val);
}




Brute force : 
    TC : nlog == nlog+2n == n ( traverse and store ) + nlogn ( sort ) + n ( traverse and compare ) 
    SC : n 


Optimal : 
    when you traverse the BST keep the pointers like prev , ( first,middile,last) 
    why 3 pointers ( first,middile,last) -->
        there might be 2 cases 
            adjacent node might need to swaped --> no use of last ( so swap first and middile after traversing the whole BST )
            non-adjacent node might need to be swaped --> swap first and last after traversing the whole BST 

    10 15 4 3 20 21 25 30 7
          f m             l
   
    10 15 4 3 20 21 25 30 
          f m

    TC : n ( traverse )
    SC : 1 or stack space 
