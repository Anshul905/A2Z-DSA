// vector<vector<int>> zigZagTraversal(Node* root)
vector <int> zigZagTraversal(Node* root)
{
    // vector<vector<int>> ans;
    vector<int> ans;
    bool lTor = true;
    queue<Node*> q;
    if(root){
        q.push(root);
    }

    while(!q.empty()){
        int sz = q.size();
        vector<int> temp(sz);
        
        for(int i=0;i<sz;i++){
            Node* cur = q.front();
            q.pop();
            
            int ind = lTor?i:sz-1-i; 
            temp[ind]=cur->data;
            
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }

        lTor = !lTor;

        // ans.push_back(temp);
        for(int i=0;i<sz;i++)
            ans.push_back(temp[i]);
        temp.clear();
    }
    return ans; 
}
