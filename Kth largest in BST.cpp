class Solution
{
    public:
    
    void inorder(Node *root,vector<int> &ans){
      if(!root)
      return ;
      
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
  
    int kthLargest(Node *root, int K)
    {
       vector<int> ans;
       
       inorder(root,ans);
       
       return ans[ans.size()-K]; // as ans is in ascending order
    }
};

// ANother approach where ans is in descending order but it is  o(nlogn) time complexity but above soln is o(n) 
 vector<int> ans;
    void transversal(Node* &root)
    {
        if(root==NULL) return ;
        
        ans.push_back(root->data);
        transversal(root->left);
        transversal(root->right);
      
        
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        transversal(root);
        sort(ans.begin(),ans.end(),greater<>());
        return ans[K-1];
        
    }
};
