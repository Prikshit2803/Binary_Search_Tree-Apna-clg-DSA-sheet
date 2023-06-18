class Solution{
public:


Node * pretoBST(int pre[],int &index,int mini,int maxi,int size){
    if(index>=size)
    return NULL;
    
    int x=pre[index];
    
    
    if(x<mini||x>maxi)
    return NULL;
    
    Node * root = newNode(x);
    index++;
    
    root->left=pretoBST(pre,index,mini,x,size);
    root->right=pretoBST(pre,index,x,maxi,size);
    
    return root;
    
}

    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        
       
        int index=0;
        
        Node * root = pretoBST(pre,index,INT_MIN,INT_MAX,size);
        
        return root;
    }
};
