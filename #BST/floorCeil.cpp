int findCeil(BinaryTreeNode<int> *root, int x){
    int ceil = -1;
    while(root){
        if( root->data==x){
            return x;
        }else if( root->data > x ){
            ceil = root->data;
            root = root->left ;
        } else {
            root = root->right;
        }
    }
    return ceil;
}



int Floor(BinaryTreeNode<int> *root, int x)
{
    int floor = -1;
    while(root){
        if( root->data==x){
            return x;
        }else if( root->data < x ){
            floor = root->data;
            root = root->right ;
        } else {
            root = root->left;
        }
    }
    return floor;
}
