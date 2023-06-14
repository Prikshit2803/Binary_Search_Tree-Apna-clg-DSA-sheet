/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
        return NULL;


        if(root->val==p->val||root->val==q->val)
        return root;

        TreeNode * l=solve(root->left,p,q);
        TreeNode * r=solve(root->right,p,q);

        if(l==NULL && r){
            return r;

        }


         else if(r==NULL && l){
            return l;
            
        }

        else if(l && r)
        return root;


        return NULL;

         
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

     TreeNode * ans=solve(root,p,q);

     return ans;
        
    }
};




// Original striver approach
class Solution
{
    public:
    
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root )
       return NULL;
       
       if(root->data==n1 || root->data==n2)
       return root;
       
       Node * left=lca(root->left,n1,n2);
       Node * right=lca(root->right,n1,n2);
       
      if(left==NULL)
      return right;
      
      else if(right==NULL)
      return left;
      
      else 
       return root;
      
       
       
    }
};
