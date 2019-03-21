/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
};*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node *array[n*n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            Node *temp=(Node *)malloc(sizeof(Node));
            temp->data=mat[i][j];
            temp->right=temp->down=NULL;
            array[k++]=temp;
        }
    }
    k=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==n-1)
            {
                array[k]->right=NULL;
            }
            else
            {
                array[k]->right=array[i*n + j+1];
            }
            
            if(i==n-1)
            {
                array[k]->down=NULL;
            }
            else
            {
                array[k]->down=array[i*n + j+n];
            }
            k++;
        }
    }
    
    Node *head=array[0];
}