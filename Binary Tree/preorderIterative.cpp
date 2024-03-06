vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> ans;
    if(root)
        st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->val);
        if(root->right)
            st.push(root->right);
        if(root->left)
            st.push(root->left);
    }
    return ans;
}

// until empty 
//     get the top of stack and print 
//     if right , push it 
//     if left , push it 

// R lr
// print , 
// push right wale pehle because ye stack ke niche rahenge then , 
// left wale  