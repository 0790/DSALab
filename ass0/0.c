#include<stdio.h>
void main()
{
    
    char c[1000] , d[1000] ;
    int i , j , k = 0 ;
    scanf("%s" , c) ;
    scanf("%s" , d) ;
    for(i = 0 ; c[i] != '\0' ; i++) ; 
    const int N = i+1 ;
    for(j = 0 ; d[j] != '\0' ; j++) ; 
    char sum[N] ; int s = 0 ;
    int carry = 0 ;
    for(i = N - 2 , j = j-1 ; i>= 0 && j >= 0 ; i-- , j--)
    {
      // printf("entered loop   " , i) ;
       s = (c[i]-'0') + (d[j]-'0') + carry ;
       sum[k] = s%10 + '0'  ;
       carry = s/10 ;

       k++ ;
    }
   // printf("first loop over\n" ) ;
    while(i>= 0 )
    {
        s = (c[i] -'0') + carry ;
       sum[k] = s%10 +'0' ; 
       carry = s/10 ;
       k++ ; i-- ;
    }
    if(carry != 0 )
    {
        sum[k] = carry +'0' ;
        k++ ;
    }
    sum[k] ='\0' ;
   
    for (k = k-1 ; k>=0 ; k--)
    {
        printf("%c" , sum[k]);
    }
} 
