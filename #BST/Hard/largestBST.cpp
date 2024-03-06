pair<int,pair<int,int>> fun(TreeNode* root){
    if(!root)
        return {0,{INT_MIN,INT_MAX}};
    
    auto l = fun(root->left);
    auto r = fun(root->right);
    int l_len = l.first , l_max = l.second.first ,  l_min = l.second.second   ;
    int r_len = r.first , r_max = r.second.first ,  r_min = r.second.second   ;

    if( l_max < root->data && root->data < r_min ){
        return { 1+l_len+r_len , { max(root->data,r_max) , min(root->data,l_min) } } ;
    }else{
        return { max(l_len,r_len) , { INT_MAX , INT_MIN } };
    }

}

int largestBST(TreeNode * root){
    return fun(root).first ;
}



Brute force : ( n*n , 1 )
    go to each node and check if it is BST 
    go to each node and if it  vakid BST , call and count the no. of node 

Better : ( n , 1 )
    traverse postorder --> left right ROOT 
    ROOT at last bevcause we need to decide lenght , min , max .... 

    maitain pair< length , < max , min > > 
    
    if null --> { 0 , { INT_MIN , INT_MAX} }
    left call 
    right call 
    if( root->data > max of left side && root->data < min of right side  ) --> valid bst 
        return {  1+left length + right length , {  max of tree , min of tree   } }
    else    
        retuen { max of left length or right length , { INT_MAX  , INT_MIN } }
        why max==INT_MAX --> so that this does not come in the calculation again 

