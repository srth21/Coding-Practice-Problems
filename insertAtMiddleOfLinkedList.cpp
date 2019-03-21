Node* insertInMiddle(Node* head, int x)
{
	// Cpde here
	if(head==NULL)
	{
    	Node *temp=(Node *)malloc(sizeof(Node));
        temp->data=x;
        temp->next=NULL;
        return head=temp;
	}
    Node *slow=head;
    Node *fast=head;
    Node *prev=NULL;
    while(fast && fast->next)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    
    if(fast!=NULL)
    {
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->data=x;
        temp->next=slow->next;
        slow->next=temp;
    }
    else
    {
        Node *temp=(Node *)malloc(sizeof(Node));
        temp->data=x;
        temp->next=slow;
        if(prev!=NULL)
            prev->next=temp;
    }
    return head;
}