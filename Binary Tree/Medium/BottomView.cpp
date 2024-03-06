vector <int> bottomView(Node *root) {
    map<int,int > m;
    vector<int> ans;
    queue< pair<Node*,int> > q;
    
    if(root)
        q.push({root, 0});

    while(!q.empty()){
        Node* cur = q.front().first ;
        int w = q.front().second ;
        q.pop();

        //update always 
        m[w]=cur->data;
        
        if(cur->left)
            q.push({cur->left, w-1});
        if (cur->right)
            q.push({cur->right,w+1});
    }

    for( auto it :m ){
        ans.push_back(it.second);
    }
    return ans;
}

same as Top order ( but update map[w] always )