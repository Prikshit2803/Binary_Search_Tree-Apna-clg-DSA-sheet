// Get inorder of Binary tree then sort it and then create a BST from it

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
  
  Node * buildtree(vector<int> ans,int start,int end){
      if(start>end)
      return NULL;
      
      int mid = (start + end)/2;
      Node * root = new Node(ans[mid]);
      
      root->left=buildtree(ans,start,mid-1);
      root->right=buildtree(ans,mid+1,end);
      
      return root;
      
  }
  void inorder(Node *root,vector<int> &ans){
      if(!root)
      return ;
      
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> ans;
        inorder(root,ans);
        
        sort(ans.begin(),ans.end());
        //cout<<ans[0]<<"";
        
       // Node * temp = buildtree(ans,0,ans.size()-1);
        
        return buildtree(ans,0,ans.size()-1);
    }
};
