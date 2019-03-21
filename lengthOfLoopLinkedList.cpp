int countNodesinLoop(struct Node *head)
{
     // Code here
     struct Node *slow=head;
     struct Node *fast=head;
     bool notDone=true;
     while(slow && fast && fast->next && notDone)
     {
         slow=slow->next;
         fast=fast->next->next;
         if(fast==slow)
         {
             notDone=false;
         }
     }
     if(fast==slow)
     {
         int count=0;
         bool notDone=true;
         struct Node *n=slow;
         while(notDone)
         {
             if(count>0 && n==slow)
             {
                 notDone=false;
             }
             else
             {
                 slow=slow->next;
                 count++;
             }
         }
         return count;
     }
     else
     {
         return 0;
     }
}