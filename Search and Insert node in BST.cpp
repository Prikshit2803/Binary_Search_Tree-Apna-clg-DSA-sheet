// Function to insert a node in a BST.
//My soln

bool search(Node * root,int key){
    
    if(!root)
    return false;
    
    if(key==root->data)
    return true;
    
    if(key<root->data){
        if(search(root->left,key))
    return true;
    }
    
    
    else{
         if(search(root->right,key))
         return true;
    }
    
    return false;
    
}
 
 
  Node *  insrt(Node* root, int key){
       if(root==NULL){
         root=new Node(key);
         return root;
       }
       
       
       if(key<root->data)
       root->left=insert(root->left,key);
       
       else
       root->right=insert(root->right,key);
       
       return root;
       
   }
   
Node* insert(Node* root, int Key) {
           if(search(root,Key)==true)
          return root;
           
          else{
               Node * temp =insrt(root,Key);
               return temp;
           }
           
           
}


//Optimised approach
Node* f(Node* root,int a){
    if(root==NULL){
        Node* node=new Node(a);
        return node;
    }
    if(root->data==a) return root;
    if(root->data>a) root->left=f(root->left,a);
    else root->right=f(root->right,a);
    return root;
}
Node* insert(Node* root, int a) {
    // Your code here
    return f(root,a);
}
