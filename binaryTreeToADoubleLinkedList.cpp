struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; 
// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list
void BToDLL(Node *root, Node **head_ref)
{
    static Node *prev=NULL;
    
    if(!root)
    {
        return;
    }
    
    BToDLL(root->left,head_ref);
    
    if(!(*head_ref))
    {
        *head_ref=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    
    BToDLL(root->right,head_ref);
}