vector<vector<int>> getTreeTraversal(TreeNode *root){

vector<int> preOrder;
vector<int> inOrder;
vector<int> postOrder;

stack< pair<TreeNode*,int> > st;
if(root)
    st.push({root,1});

while(!st.empty()){
    auto it = st.top();
    st.pop();
    root = it.first;

    if(it.second==1){
        preOrder.push_back(root->data);
        it.second++;
        st.push(it);
        if(root->left)
            st.push( {root->left,1} );
    }else if(it.second==2){
        inOrder.push_back(root->data);
        it.second++;
        st.push(it);
        if(root->right)
            st.push( {root->right,1} );
    }else{
        postOrder.push_back(root->data);
    }
}

// ans.push_back(inOrder);
// ans.push_back(preOrder);
// ans.push_back(postOrder);

// vector<vector<int>> ans = { inOrder,preOrder,postOrder } ;

return { inOrder,preOrder,postOrder };
}





// if num==1
//     preorder 
//     ++
//     if left , push 
// if num==2
//     inorder 
//     ++
//     if right , push 
// if num==3
//     postOrder

