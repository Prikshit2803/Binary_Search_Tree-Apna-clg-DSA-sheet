// Form an array of inorder traversal and find pre and suc of key

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void inorder(Node *root,vector<Node *> &ans){
        if(!root)
        return;
        
        inorder(root->left,ans);
        ans.push_back(root);
         inorder(root->right,ans);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        vector<Node *> ans;
        pre=NULL;
        suc=NULL;
        
        inorder(root,ans);
        int n=ans.size()-1;
        
        if(key>ans[n]->key){ //edge case
            pre=ans[n];
            return;
        }
        
        if(key<ans[0]->key){ // edge case
            suc=ans[0];
            return;
        }
        
        if(key==ans[n]->key){ //edge case
            pre=ans[n-1];
            return;
        }
        
        if(key==ans[0]->key){ //edge case
            suc=ans[1];
            return;
        }
        
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]->key > key){
                suc=ans[i];
                if(ans[i-1]->key!=key)
                pre=ans[i-1];
                
                else
                pre=ans[i-2];
                
                break;
            }
            
        }
        return;
    }
};
