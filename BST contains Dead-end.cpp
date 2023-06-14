// My simple approach using inorder traversal and leaf nodes 
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

void inorder(Node * root, vector<int> & ans){
    if(!root)
    return;
    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    
    
}

bool solve(Node * root, vector<int> & ans){
    if(!root)
    return false;
    
    if(root->left==NULL && root->right==NULL){
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1 && ans[i+1]==2 && root->data==1)
            return true;
            
            else if(ans[i]==root->data && ans[i-1]==root->data-1 && ans[i+1]==root->data+1)
            return true;
            
        }
        
        return false;
    }
    return (solve(root->left,ans)||solve(root->right,ans));
}
bool isDeadEnd(Node *root)
{
    vector<int> ans;
    
    inorder(root,ans);
    
    
    return solve(root,ans);
    
}

// optimised approach
bool ispossible(Node* root,int ll,int rl){
    if(root==NULL)return false;
    if(ll>=rl)return true;
    return ispossible(root->left,ll,root->data-1) || ispossible(root->right,root->data+1,rl);
}
bool isDeadEnd(Node *root)
{
    if(root==NULL)return false;
    return ispossible(root,1,INT_MAX);
}

