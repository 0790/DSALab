#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char data;
    struct node * prev;
    struct node * next;
}*head, *last;
void createList(char* data ,int n)
{
    int i;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            
            

            head->data = data[0] - 48;
            head->prev = NULL;
            head->next = NULL;

            last = head;
            
            /*
             * Create rest of the n-1 nodes
             */
            for(i=1; i< n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                   
                    //scanf("%c", &data);

                    newNode->data = data[i]-48;
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
void LR(){
    last -> next = head ;
    head ->prev = last ;
    last = head ;
    head = head -> next ;
    last -> next = NULL ;
    head -> prev =NULL ;
}
void RR(){
    last -> next = head ;
    head ->prev = last ;
    head = last ;
    last = last -> prev ;
    last -> next = NULL ;
    head -> prev =NULL ;
    
}
void LS() {
    struct node *newNode;
    head = head -> next ;
    head -> prev = NULL ;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 0;
    newNode->prev = last; 
    newNode->next = NULL;
    last->next = newNode; 
    last = newNode;    
    

}
void RS(){
    struct node *newNode ;
    newNode->data = 0;
    newNode-> next = head ;
    newNode-> prev = newNode ;
    head-> prev = NULL ;
    head = newNode ;
    last = last -> prev ;
    last-> next = NULL ;



}
void INC(){
    int i = last -> data ;
    i = i+ 1 ;
    int c = i/2 ;
    last -> data = i%2 ;
    struct node *temp = last ;
    while(c != 0 && temp -> prev != NULL)
    {
        temp = temp -> prev ;
        i = temp -> data ;
        i = i + 1 ;
        c = i / 2 ;
        temp -> data = i%2 ;
        
    }

}
void DEC(){
    if(last-> data == 1) last -> data = 0;
    else{
        struct node *temp = last-> prev ; 
        int flag = 0 ; last-> data = 1 ; 
        while(temp->prev != NULL && flag == 0 ) 
        {
            if(temp->data == 1) {
                temp->data = 0 ;
                flag = 1 ;}
            else{
                temp->data = 1 ; 
            }
            temp = temp -> prev ;
        }
        if(flag == 0 ) head-> data = 1; 

    }
}
void printList()
{
    struct node* nod = head;
    while (nod != NULL) {
        printf("%d", nod->data);
        nod = nod->next;

    }
 
    
}
 
int main ()
{
    char bitarray[1000] ;
    scanf("%s" , bitarray) ;
    int i = 0 ; 
    for(; bitarray[i]!= '\0' ; i++  ) ;
    createList(bitarray, i) ;
    int n ; char temp , choice[4];
    scanf("%d" , &n) ; scanf("%c" , &temp) ;
    for(int j = 0 ; j < n ; j++) 
    {
        scanf("%s", choice) ;
        if(strcmp(choice, "LR") ==0) LR();
        else if(strcmp(choice, "RR") ==0 ) RR();
        else if(strcmp(choice, "LS") ==0) LS();
        else if(strcmp(choice, "RS") ==0) RS();
        else if(strcmp(choice, "INC") ==0) INC();
        else if(strcmp(choice, "DEC") ==0) DEC();
     }
     printList() ;
    return 0 ;

}