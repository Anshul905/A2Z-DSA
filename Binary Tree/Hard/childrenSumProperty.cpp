int check(Node* root){
    if( !root )
        return 0;
    if( !root->left && !root->right )
        return root->data;

    int ls = check(root->left);
    if(ls==-1)return -1;
    int rs = check(root->right);
    if(rs==-1)return -1;

    if(  ls+rs==root->data)
        return root->data;
    return -1;

}

bool isParentSum(Node *root){
    return check(root)!=-1;

}