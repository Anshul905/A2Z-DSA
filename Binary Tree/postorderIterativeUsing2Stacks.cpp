vector<int> postorderTraversal(TreeNode* root) {
    
    vector<int> ans;
    stack<TreeNode*> st;
    stack<int> st2;

    if(root)
        st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        st2.push(root->val);

        if(root->left)
            st.push(root->left);
        if(root->right)
            st.push(root->right);

    }

    while(!st2.empty()){
        ans.push_back(st2.top());
        st2.pop();
    }
    return ans;
}


// until empty 
//     get the top of stack and PUSH IT IN ANOTHER STACK (STK2) 
//     if left , push it 
//     if right , push it 
// then pop out from STK2 and push in vector and vector will be answer 


// lr R
// Root last me chahiye so dusre STACK me daalo and taki baad me niklega 
// for lr , 
//     1
//   2   3
//   post --> 2 3 1 
    
// Insertion at stack 1 : R l r 
// Removal at stack 1   : R r l 
// Insertion at stack 2 : R r l 
// Removal at stack 1   : l r R 

// https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/
// https://www.youtube.com/watch?v=2YBhNLodD8Q&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=82

    





