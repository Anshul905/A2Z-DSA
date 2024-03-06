bool isSameTree(TreeNode* p, TreeNode* q) {

    // if( (p && !q) || (!p && q) )
    //     return false;
    // if( !p && !q )
    //     return true;
    if( !p || !q )
        return p==q;

    if( p->val != q->val)
        return false;

    bool l = isSameTree(p->left,q->left);
    bool r = isSameTree(p->right,q->right);

    return l && r;           
}