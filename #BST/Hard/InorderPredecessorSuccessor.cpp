int findPredecessor(TreeNode *root, int& pre , int key){
    // if(!root)
    //     return pre;
    // if( root->data >= key )
    //     findPredecessor(root->left, pre, key);
    // else{
    //     pre = root->data ;
    //     findPredecessor(root->right, pre, key);
    // }
    
    while(root){
        if( root->data >= key )
            root = root->left;
        else{
            pre = root->data ;
            root = root->right;
        }
    }
    return pre;
}
int findSuccessor(TreeNode *root, int& suc , int key){
    // if(!root)
    //     return suc;
    // if( root->data <= key )
    //     findSuccessor(root->right, suc, key);
    // else{
    //     suc = root->data ;
    //     findSuccessor(root->left, suc, key);
    // }

    while(root){
        if(root->data <= key )
            root = root->right;
        else{
            suc = root->data ;
            root = root->left;
        }
    }
    return suc;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int suc = -1 ;
    int pre = -1 ;
    return { findPredecessor(root,pre,key) , findSuccessor(root,suc,key)  } ;
}



// Brute Force : ( n , n )
//     store the inorder and find the predecessor/successor from array 
//     TC : n == traverse ( n ) + find( n or logn )
//     SC : n 

// Better : ( n , 1 )
//     traverse inorder tree and get the predecessor/successor of node 
//     TC : n == traverse ( n ) 
//     SC : 1 ( morris ) or O(height of tree )

// Optimal : ( height , 1 )
//     use variable and call for both parallely  

