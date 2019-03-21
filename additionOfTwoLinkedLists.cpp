/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
/*

Given two numbers represented by two linked lists, write a function that returns sum list. 
The sum list is linked list representation of addition of two input numbers. 
It is not allowed to modify the lists.


*/

//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second){
  // Code here
  Node *head;
  head=NULL;
  
  int carry=0;
  
  while(first && second)
  {
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->next=NULL;
    
    int ele=first->data+second->data+carry;
    
    if(ele>9)
    {
        carry=ele/10;
        ele=ele%10;
    }
    else
    {
        carry=0;
    }
    temp->data=ele;
    
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node *t=head;
        while(t->next)
        {
            t=t->next;
        }
        t->next=temp;
    }
    first=first->next;
    second=second->next;
  }
  
  while(first)
  {
    //cout<<"First not null"<<endl;
      Node *temp=(Node *)malloc(sizeof(Node));
      temp->next=NULL;
      int ele;
      if(carry)
      {
        ele=first->data+carry;
        if(ele>9)
        {
            carry=ele/10;
            ele=ele%10;
        }
        else
        {
            carry=0;
        }
      }
      else
      {
          ele=first->data;
      }
      temp->data=ele;
      if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node *t=head;
        while(t->next)
        {
            t=t->next;
        }
        t->next=temp;
    }
      first=first->next;
  }
  while(second)
  {
    //cout<<"Second not null"<<endl;
      Node *temp=(Node *)malloc(sizeof(Node));
      temp->next=NULL;
      int ele;
      if(carry)
      {
        ele=second->data+carry;
        if(ele>9)
        {
            carry=ele/10;
            ele=ele%10;
        }
        else
        {
            carry=0;
        }
      }
      else
      {
          ele=second->data;
      }
      temp->data=ele;
      second=second->next;
      //cout<<"adding ele "<<ele<<" because of  "<<second->data<<endl;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node *t=head;
        while(t->next)
        {
            t=t->next;
        }
        t->next=temp;
    }
      
  }
  if(carry)
  {
      Node *temp=(Node *)malloc(sizeof(Node));
      temp->next=NULL;
      temp->data=carry;
      
      if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node *t=head;
        while(t->next)
        {
            t=t->next;
        }
        t->next=temp;
    }
      
      
  }

    return head;
}