vector<int> inorderTraversal(TreeNode* root) {

    vector<int> ans;
    TreeNode* node = root ;
    stack<TreeNode*> st;

    while(true){
        if(node){
            st.push(node);
            node = node->left ;
        }else{
            if(st.empty()) break;
            node = st.top();
            ans.push_back(node->val);
            st.pop();
            node = node->right;
        }
    }
    return ans;
}


// while true
// not null --> PUSH in the stack and go to LEFT 
// null     --> 
//     check if empty , if yes BREAK 
//     else PRINT answer ans go to RIGHT  

// Observation : jab kisi ka left nahi hota , to wahi top me hota hai and wahi pop out hota hai then we go to usi ( st.top() ) ke right ko and if right nahi hai to uska parent pop out hota hai

// left me jaate jao , agar nahi to top ko pop out karke top ke right me jao because top me wahi hota hai jiska left nahi mila hai 

