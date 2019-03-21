#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    if(!head->next)
    {
      return true;
    }
    if(!head->next->next)
    {
      if(head->next->data==head->data)
      {
        return true;
      }
      return false;
    }
    int n=0;
    Node *t=head;
    while(t)
    {
      t=t->next;
      n++;
    }
    //cout<<n<<endl;
    //Your code here
    Node *slow=head;
    Node *fast=head;
    int count=0;
    Node *prev=NULL;
    while(fast && fast->next)
    {
        prev=slow;
        count++;
        slow=slow->next;
        fast=fast->next->next;
    }
    //cout<<count<<endl;
    //cout<<slow->data<<endl;
    Node *h1 , *h2;
    //h2=slow;
    h1=head;
  if(n%2==0)
  {
    h2=slow;
    prev->next=NULL;
  }
  else{
    h2=slow->next;
    slow->next=NULL;
  }
    
    
    //cout<<h1->data<<endl;
    //cout<<h2->data<<endl;
    Node *curr, *prev1, *next;
    curr=h1;
    prev1=NULL;
    
    while(curr)
    {
        next=curr->next;
        curr->next=prev1;
        prev1=curr;
        curr=next;
    }
    h1=prev;
    
    while(h1!=NULL || h2!=NULL)
    {
        if(h1->data!=h2->data)
        {
            return false;
        }
        h1=h1->next;
        h2=h2->next;
    }
    if(h1==NULL && h2==NULL)
    {
        return true;
    }
}