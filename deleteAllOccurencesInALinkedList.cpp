Node* deleteAllOccurances(Node *head,int x)
{
    //Your code here
    Node *curr=head;
    Node *prev=NULL;
    
    while(curr)
    {
        bool flag=false;
        if(curr->data==x)
        {
            if(!prev)
            {
                head=curr->next;
            }
            else
            {
                flag=true;
                prev->next=curr->next;
            }
        }
        if(flag)
        {
            curr=curr->next;
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}