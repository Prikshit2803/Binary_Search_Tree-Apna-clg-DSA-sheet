// My approach where I traverse the entire BST
class Solution{
public:

int cnt=0;
 void solve(Node * root,int l,int h){
     if(!root)
     return ;
     
     if(root->data>=l && root->data<=h)
     cnt++;
     
     solve(root->left,l,h);
     solve(root->right,l,h);
 }
    int getCount(Node *root, int l, int h)
    {
       solve(root,l,h);
       
       return cnt;
    }
};

// A much more optimised approach
// if l<=root->data<=h go both sides of root but if  l>root->data  traverse only right or h<root->data  traverse only left
class Solution{
public:

int cnt=0;
 void solve(Node * root,int l,int h){
     if(!root)
     return ;
     
     if(root->data>=l && root->data<=h){
     cnt++;
     
     solve(root->left,l,h);
     solve(root->right,l,h);
     }
     
     else if(root->data<l)
      solve(root->right,l,h);
      
      else
      solve(root->left,l,h);
      
 }
    int getCount(Node *root, int l, int h)
    {
       solve(root,l,h);
       
       return cnt;
    }
};

// similar approach but int is returned
int getCount(Node *root, int l, int h) {
        if(!root) 
            return 0;
        if(root->data >= l && root->data <= h) {
            return 1 + getCount(root->left,l,h) + getCount(root->right,l,h);
        }
        else if(root->data < l)
            return getCount(root->right,l,h);
        else
            return getCount(root->left,l,h);
    }
