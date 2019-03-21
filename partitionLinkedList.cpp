/*

Given a linked list and a value x, partition it such that all nodes less than x come first, 
then all nodes with value equal to x and finally nodes with value greater than or equal to x.
The original relative order of the nodes in each of the three partitions should be preserved. 
The partition must work in-place.
*/
Node *compute(Node *head)
{
// your code goes here
    Node *curr,*prev;
    curr=head;
    prev=NULL;
    bool notDone=true;
    while(notDone)
    {
        int i=0;
        curr=head;
        prev=NULL;
        while(curr && curr->next)
        {
            bool flag=false;
            if(curr->next->data > curr->data)
            {
                flag=true;
                if(prev)
                {
                    prev->next=curr->next;
                    curr=curr->next;
                }
                else
                {
                    head=curr->next;
                    curr=head;
                }
                i++;
            }
            if(!flag)
            {
                prev=curr;
                curr=curr->next;
            }
        }
        if(i==0)
        {
            notDone=false;
        }
    }
    return head;
    //return head;
}