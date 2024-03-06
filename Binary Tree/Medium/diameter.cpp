// pair<int,int> check( TreeNode *root ){
//     if(!root)
//         return {0,0};
//     auto l = check(root->left);
//     auto r = check(root->right);
//     int lh= l.first;
//     int lhm = l.second;
//     int rh= r.first;
//     int rhm = r.second;

//     int h = 1+max(lh,rh);
//     int d = max( lh+rh+1,max(lhm,rhm) );
//     return {h,d};
// }


int check( TreeNode *root,int& diameter ){
    if(!root)
        return 0;
    int lh = check(root->left,diameter);
    int rh = check(root->right,diameter);
    diameter = max(diameter,lh+rh+1);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode *root){
    // return check(root).second-1;

    int diameter=0;
    check(root,diameter);
    return diameter-1;
}


naive O(n*n)
    at each node , max(lh+rh) from all the nodes is the answer

best is to use pair and contain height and max_diameter of each node and then at last you will get height and max_diameter once node can have 
OR 
pass one varible and keep updating it 