#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ;
    struct node* next ; 
} *head = NULL , *tail = NULL ; 
int main() {
    
    head = (struct node*)malloc(sizeof(struct node) ) ;
    head -> next = NULL ; tail = head ;
    int n ; scanf("%d" , &n) ; if(n == -1) return 0 ;
    head->data = n ;
    struct node *temp = (struct node*)malloc(sizeof(struct node) ) ; temp -> next = NULL ;
    scanf("%d" , &n ) ;
    while(n != -1)
    {
        temp -> data = n ;
        tail ->next = temp ;
        tail = temp ;
        scanf("%d" , &n) ;
        temp = (struct node*)malloc(sizeof(struct node) ) ; temp -> next = NULL ;
        
    } 
    if(head-> next != NULL) {
    struct node *cur ,*left , *right ;
        cur = head -> next ;
    left = head ;
    right = cur -> next ; head -> next = NULL ;
    
    while (right != NULL) 
    {
        
        cur -> next = left ;
        left = cur ;
        cur = right ;
        right = cur -> next ;
    }
    
    cur ->next = left ; 
    head = cur ;
    }
    temp = head ;
    while(temp != NULL) 
    {
        printf("%d " , temp->data) ; temp = temp -> next ;
    }
    return 0 ;
}