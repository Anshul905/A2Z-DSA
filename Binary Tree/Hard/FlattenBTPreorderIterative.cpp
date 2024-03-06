void flatten(TreeNode* root) {
    if(!root)
        return ;

    stack<TreeNode*> st;
    if(root)
        st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        if(root->right)
            st.push(root->right);
        if(root->left)
            st.push(root->left);

        if(!st.empty())
            root->right = st.top();
        root->left = nullptr ;
    }
}



TC -> n 
SC -> n

use stack 
push the root node in stack 
    pop it , check if right present put it then check for left and put it ( putting left after right so in stack left one will on the top )  and then check if stack is not empty if it is attach cur->right = s.top() [ it would be left wala child if not left then  right wala child if not right then sibling if not sibling in other side but it would always be someone which comes in preorder ]
    and attach cur->left = null ;




