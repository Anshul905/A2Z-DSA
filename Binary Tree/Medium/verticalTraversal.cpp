vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int,vector<pair<int,int>> > m;
    vector<int> ans;

    queue< pair<TreeNode<int>*,int> > q;
    if(root)
        q.push({root, 0});

    int level=0;
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode<int>* cur = q.front().first ;
            int w = q.front().second ;
            q.pop();
            m[w].push_back({level,cur->data});
            if(cur->left)
              q.push({cur->left, w-1});
            if (cur->right)
                q.push({cur->right,w+1});
        }
        level++;
    }

    for( auto &width_ :m ){
        int w = width_.first;
        vector<pair<int,int>> v = width_.second;
        sort(v.begin(),v.end());
        for( pair<int,int> n:v ){
            ans.push_back(n.second);
        }
    }
    return ans;
}







// dfs 



void preorder(TreeNode<int>* root,map<int,vector<pair<int,int>>> &m,int width,int height){
    if(!root)
        return ;
    m[width].push_back({height, root->data});
    preorder(root->left,m,width-1,height+1);
    preorder(root->right,m,width+1,height+1);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int,vector<pair<int,int>> > m;
    vector<int> ans;
    preorder(root, m, 0,0);

    for( auto &width_ :m ){
        int w = width_.first;
        vector<pair<int,int>> v = width_.second;
        sort(v.begin(),v.end());
        for( pair<int,int> n:v ){
            ans.push_back(n.second);
        }
    }
    return ans;

}

