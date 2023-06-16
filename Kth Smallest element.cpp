class Solution {
public:

void inorder(TreeNode * root,vector<int> &ans){
    if(!root)
    return ;

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);

}
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
        return true;

        vector<int> ans;

       inorder(root,ans);

       int ap;

       return ans[k-1];
    }
};
//Another approach
//AS far as I can see it is an recursive inorder traversal where i increases till it reaches actual value
class Solution {
public:
    vector<int> v;
    int solve(TreeNode* root,int &i,int k){
        if(root==NULL)return -1;
        int left=solve(root->left,i,k);
        if(left!=-1)return left;
        i++;
        if(i==k)return root->val;
        return solve(root->right,i,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        return solve(root,i,k);
    }
};

//similar but better explained approach
// (3) Optimal Approach: O(N) time and O(1) space:
// Approach 2 is fine, but there we are still creating an extra vector to store the node values. We can avoid it so that our space complexity further boils down to O(1).

// Intuition:
// We need the kth smallest element. And, we know that our inorder traversal will first give the 1st smallest element, then 2nd smallest element ... and so on.
// So, instead of storing the node values inside a vector, we can maintain a 'cnt' variable to keep track if we have reached kth smallest value or not in the inorder traversal. And then, we can return the value once cnt reaches k value.

// Algorithm:
// Initialize a variable, cnt = 0;
// Do an Inorder traversal and instead of saving node->val in vector do a cnt++, denoting that we have encountered cnt th smallest element.
// Return node->val once cnt == k.
// Complexity:
// Time complexity: O(n)O(n)O(n)
// O(n) for traversing the Tree consisting of n nodes.
// Space complexity:O(1)O(1)O(1) + recursive stack space
// Code:
class Solution {
public:
    void solve(TreeNode* root, int &cnt, int &ans, int k){
        if(root == NULL)    return;
        //left, root, right 
        solve(root->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;        
        int ans;
        solve(root, cnt, ans, k);
        return ans;
   
