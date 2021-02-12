#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *next ;
}*head[1000];
int func(struct node *a){
    if(a == NULL) return 0 ;
    int s1 = func(head[a->data]->next) , s2 =func(a->next) ;
    if(s1 > s2) return s1 +1 ;
    else return s2 + 1 ;
    
}
int main(){
    int v , e , e1 , e2; 
    scanf("%d" , &v) ;
    scanf("%d" , &e) ;
   
    struct node *temp =NULL , *temp1  ;
    for(int i = 0 ; i < v ; i++){
        
         head[i] = (struct node*)malloc(sizeof(struct node)) ;
        head[i] -> next = NULL ;
        head[i] -> data = i ;
    }
     
    for(int i =0 ; i < e ; i++){
        scanf("%d" , &e1 ) ;
        scanf("%d" , &e2 ) ;
        
            temp = head[e1 -1] ;
            while(temp -> next != NULL) {
                temp =temp -> next ;
            }
            temp1 = (struct node*)malloc(sizeof(struct node)) ;
            temp1 -> next = NULL ;
            temp1 -> data = e2 -1 ;
            temp -> next = temp1 ;
    }
    int sum = 0 , max = 0 ;
    for(int i = 0 ; i < v ; i++) {
        sum =func(head[i] -> next) ; 
        
        if(max < sum ) max = sum ;

    }
    printf("%d" , max ) ;
    return 0 ;
}