#include<stdio.h>
int main(){
    int n , m ;
    scanf("%d" ,&n) ;
    double i , precision = 0.000001;
//   if(n < 0) i = -1 ;
  // else i = 1 ;
  if(n<0) m = -1*n ;
  else m = n ;
   for(i =1 ; (i*i*i) <= m; ++i);  
   for(--i; (i*i*i) < m; i += precision);
   if(n < 0) i*= -1 ;
   printf("%d" , (int)i ) ;  
    return 0;
}