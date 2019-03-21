//https://practice.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1
/*
Given a single linked list of size N, your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller list. The sublists should be made from alternating elements from the original list.

Original linked List: 5 4 3 2 1 0
Resultant Linked List 'a' 5 3 1
Resultant Linked List 'b' 4 2 0
Note: the sublist should in the order with respect to original list. 
Input:
The function takes three inputs, reference pointer to the head of the original list (headRef) and two NULL reference pointer to the head of the two sublist's (aRef and bRef).
There will be multiple test cases and for each test thi function will be called seperately.

Output:
For each test case print the two sublists head1 and head2.

*/
#include <iostream>
#include <stdio.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void append(struct node** headRef, int newData)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}
void printList(struct node *node)
{
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
} 
void alternatingSplitList(struct node* headRef, struct node** aRef, struct node** bRef); 
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--)
    {
        struct node* head = NULL;
        struct node* a = NULL;
        struct node* b = NULL;
        int n, k;
        cin>>n;
        while(n--)
        {
            cin>>k;
            append(&head, k);
        }
        alternatingSplitList(head, &a, &b);
        printList(a);
        printList(b);
    }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of node is as
struct node
{
	int data;
	struct node* next;
};
*/
void alternatingSplitList(struct node* headRef, struct node** aRef, struct node** bRef)
{
    // Code here
    struct node *temp = headRef;
    int i=1;
    
    *aRef = NULL;
    *bRef = NULL;
    
    while(temp)
    {
        if(i%2==1)
        {
            append(aRef,temp->data);
        }
        else
        {
            append(bRef,temp->data);
        }
        temp=temp->next;
        i++;
    }
}