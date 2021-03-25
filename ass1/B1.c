#include <stdio.h>
#include <stdlib.h>


struct node {
    char data;
    struct node * prev;
    struct node * next;
}*head, *last;
void createList(int n);
void displayListFromFirst();
void displayListFromEnd();


int main()
{
    int n;
    char choice;

    head = NULL;
    last = NULL;
    
    
    scanf("%d", &n);
    scanf("%c" , &choice);

    createList(n); // Create list of n nodes
    displayListFromFirst() ;
    
    

    

    return 0;
}


void createList(int n)
{
    int i;
    char data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            
            scanf("%c", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;
            
            /*
             * Create rest of the n-1 nodes
             */
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                   
                    scanf("%c", &data);

                    newNode->data = data;
                    newNode->prev = last; // Link new node with the previous node
                    newNode->next = NULL;

                    last->next = newNode; // Link previous node with the new node
                    last = newNode;          // Make new node as last/previous node
                }
                else
                {
                    
                    break;
                }
            }

        }
        
    }
}



void displayListFromFirst()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
       return ;
    }
    else
    {
       
        

        while(head != last)
        {
            if(head->data != last->data){
                printf("NOT A PALINDROME") ; return ;
            }

            n++;
            
            /* Move the current pointer to next node */
            head = head->next;
            last = last->prev; 
        }
        printf("PALINDROME") ;
        
    }
    
}


