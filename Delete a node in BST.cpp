//My soln
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

void inorder(TreeNode * root,vector<int> &ans){
    if(!root)
    return ;

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);

}

TreeNode* buildtree(vector<int> &ans,int start,int end){


if(start>end)
return NULL;

  int mid=(start+end)/2;

  TreeNode* root= new TreeNode(ans[mid]);

  root->left=buildtree(ans,start,mid-1);
  root->right=buildtree(ans,mid+1,end);

  return root;


}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return NULL;

        vector<int> ans;

       inorder(root,ans);

       for(int i=0;i<ans.size();i++){
           if(ans[i]==key){
            //  ans.erase(i) ; 
            ans.erase(ans.begin() + i);
              break;
           }
        
       }

       return buildtree(ans,0,ans.size()-1);
    }
};

//Optimised soln
// Approach
// Recursively search for node to be deleted.

// Once we find the node to be deleted,

// If the root is a leaf node, then return NULL. (Base Case).
// Else if the root has only the left child, then we delete the root node and return its left child.
// Else if the root has only the right child, then we delete the root node and return its right child.
// Else, we find the inorder successor node, set the key of root with the key of the inorder successor, and delete the inorder successor. To find the inorder successor, we need to find the node with the minimum key in the right subtree.
// Complexity
// Time complexity:
// O(H)

// Space complexity:
// O(H)

// Code
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (!root) return root;
        
        if (val < root->val) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->val) {
            root->right = deleteNode(root->right, val);
        } else {
            if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            if (!root->left || !root->right) {
                TreeNode *ret = root->left ? root->left : root->right;
                delete(root);
                return ret;
            }
            if (root->left && root->right) {
                TreeNode *tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                // Here we call again to delete inorder successor
                root->right = deleteNode(root->right, tmp->val);
            }
        }
        return root;
    }
};
