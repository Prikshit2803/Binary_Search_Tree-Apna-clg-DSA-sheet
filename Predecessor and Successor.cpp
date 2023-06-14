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

//Optimised approach
Node*p=NULL,*s=NULL;
    void ino(Node*root,int key){
        if(!root) return;
        ino(root->left,key);
        if(key>root->key) p=root;
        else if(key<root->key and !s) s=root;
        ino(root->right,key);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
       ino(root,key);
       pre=p,suc=s;
    }


//Improved version of my approach
class Solution
{
       void inorder(Node* root,vector<Node*> &v)
       {
           if(root==NULL)
           return ;
           
           inorder(root->left,v);
           v.push_back(root);
           inorder(root->right,v);
           
       }
    
    
    
    
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        
        vector<Node*> v;
        inorder(root,v);
        
        
        //  for(int i=0;i<v.size();i++)
        //  cout<<v[i]->key<<" ";
        //  cout<<endl;
        
          for(int i=v.size()-1;i>=0;i--)
           {  if(v[i]->key>key)
             suc=v[i];}
             
             
             for(int i=0;i<v.size();i++)
           {  if(v[i]->key<key)
             pre=v[i];}
             
             
             
             
        
    }
};
