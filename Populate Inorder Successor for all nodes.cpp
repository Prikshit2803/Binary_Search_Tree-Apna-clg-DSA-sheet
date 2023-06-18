class Solution
{
public:

void inorder(Node * root,vector<Node *> &ans){
    if(!root)
    return ;
    
    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
}

    void populateNext(Node *root)
    {
        vector<Node *> ans;
        inorder(root,ans);
        
        for(int i=0;i<ans.size()-1;i++)
        ans[i]->next=ans[i+1];
        
    }
};

//optimised approach
void helper(Node * root, Node * &prev){
    if(!root)
    return;
    
    helper(root->left,prev); //similar to inorder 1ist step
    
    if(prev!=NULL){
        prev->next=root; // inorder 2nd step
    }
    
    prev=root;
    
     helper(root->right,prev); // inorder 3rd step
    
}
    void populateNext(Node *root)
    {
        // vector<Node *> ans;
        // inorder(root,ans);
        
        // for(int i=0;i<ans.size()-1;i++)
        // ans[i]->next=ans[i+1];
        
        Node * prev = NULL;
        helper(root,prev);
    }
};
