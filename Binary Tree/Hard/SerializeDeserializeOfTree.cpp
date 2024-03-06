string serialize(TreeNode* root) {
    if(!root)
        return "";

    string s = "" ;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur){
            s.append(to_string(cur->val)+',');
            q.push(cur->left);
            q.push(cur->right);
        }else
            s.append("#,");
    }

    return s ;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size()==0)
        return nullptr;
    stringstream s(data);
    string str;

    getline(s,str,',');
    TreeNode* root = new TreeNode(stoi(str));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#"){
            cur->left = nullptr ;
        }else{
            TreeNode* leftTree = new TreeNode(stoi(str));
            cur->left = leftTree ;
            q.push(leftTree);
        }

        getline(s,str,',');
        if(str=="#"){
            cur->right = nullptr ;
        }else{
            TreeNode* rightTree = new TreeNode(stoi(str));
            cur->right = rightTree ;
            q.push(rightTree);
        }
    }
    return root;
}

// Your Codec object will be instantiated and called as such:
// TreeNode* ans = deserialize(serialize(root));


// stringstream s(data);
// string str;
// getline(s,str,',');

// data ko s me dala and comma separater se value nikalte gaye which is stored in str 




