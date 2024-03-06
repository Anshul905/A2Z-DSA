void flatten(TreeNode* root) {
    TreeNode* cur = root ;
    while(cur){
        if(!cur->left){
            cur=  cur->right ;
        }else{
            //find right most node of left subtree 
            TreeNode* temp = cur->left ;
            while(temp->right)
                    temp = temp->right;

            //connect its right to cur's right and make cur's right left 
            temp->right = cur->right;
            cur->right = cur->left ;
            cur->left = nullptr;
            //move it to cur->right ( like i++ until cur->right is null ) 
            cur = cur->right ;
        }
    }
}




TC -> n 
SC -> 1 ( yes )

intution : 
    connect the right most node of the left subtree to the cur->right ( right_mode->right = cur->right )
        how to find right most node of the left suntree -->  go to cur->left  and apply loop in right side until it gets null  
        for this there must be left of cur ( or left subtree ) , if not cur->left , move cur = cur->right 
    and make the cur->left as cur->right ( cur->right = cur->left )

