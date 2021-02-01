#include<stdio.h>
void main(){

 int n ,temp = 0;
 char c ;
 int  m ,l, total = 0 ; 
 int arr[5000] = {[0 ... 4999] -50} ;
 scanf("%d" , &n) ;
 scanf("%c" , &c) ;
 for(int i = 0 ; i< n ; i++)
 {
     scanf("%c", &c  ) ;
     if(c=='L') 
     {
        scanf("%d" , &m) ;
        for(int k = 0 ; k< m ; k++) 
        {
            scanf("%d" , &l) ;
            arr[l-1] = 0 ;
         }
        scanf("%c" , &c) ;
     }
     else if(c == 'E')
     {
         scanf ("%d" , &m ) ; temp = 0 ;
        for(int i = 0 ; i < 5000 && temp < m ; i++ )
        {
            if(arr[i] == -50 || arr[i] == 0) {
            
                arr[i] = 1 ; temp++ ; 
                
            }
        }
        scanf("%c" , &c) ;
     }
    
 }  
 int i ;
 for(i = 0 ; arr[i] != -50 ; i++  ) ;
/* {
     printf("%d " , arr[i]) ;
 }
*/
 printf("\n%d" , i ) ; 
}