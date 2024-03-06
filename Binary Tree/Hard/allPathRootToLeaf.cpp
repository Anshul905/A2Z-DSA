void check( Node* root , vector<vector<int>> &ans , vector<int> path ){
    if(!root)
        return;
    if( !root->left && !root->right ){
        path.push_back(root->data);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(root->data);
    check(root->left, ans, path );
    check(root->right, ans, path );
    path.pop_back();
}


vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans ;
    vector<int> path;
    check(root,ans,path);

    return ans;
}