vector<int> inorderTraversal(TreeNode* root) {    
    vector<int> ans;
    if(!root)
        return ans;

    TreeNode* cur = root;

    while(cur){
        if(!cur->left){
            ans.push_back(cur->val);
            cur = cur->right ;//to reach parent node , after that cur disconnect thread
        }else{
            //connect or disconnect the right most node of left subtree to cur 
            // reach to the right most guy
            TreeNode* temp = cur->left ;
            while(temp->right && temp->right!=cur){
                temp = temp->right;
            }
            // At this point ,  either temp->right==nullptr ( disconnected ) then connect the thread to cur
            // or else temp->right==cur ( connected ) then disconnect the thread 
            if(!temp->right){
                temp->right = cur;//connected
                ans.push_back(cur->val);
                cur = cur->left ;  // because we connected it before moving to the left subtree  
            }else{
                temp->right = nullptr;//disconnected
                cur = cur->right ;// left subtree is over , thats why there was thread ,now move to right subtree 
            }
        }
    }

    return ans;
}



TC : n(branch) + n(each node) ~~ n ( branch == finding the right most node , sometime it takes 1,2,3,4 summed nearly n )
SC : 1 ( normally n [stack,queue] )

uses Threaded Binary Tree 

In-order Morris Traversal:
🌳 1st case: if left is null, 
                print current node 
                and go right
🌳 2nd case: before going left, 
             make right most node on left subtree connected to current node ( right_most->right = cur ), 
             print the current node 
             then go left
🌳 3rd case: if thread is already pointed to current node, 
                then remove the thread


2nd case WHY -> 
if the right most node on left subtreee does not have thread to its root , how will it go to root so connect the thread and move left so that afterward you can directly come to the node ( no need of backtracking  ) 

WHY ARE WE CREATING THREAD WHEN WE ARE AT SOME NODE ?
because we are NOT going to COME on that node AGAIN so before moving to left go to right most node on left subtree and create the thread 

3rd case WHY --> 
if there is any thread that means we made it and we have traversed left subtree thats why there is a thread so now its time to remove the thread the thread and move to right subtree 