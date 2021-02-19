#include<stdio.h>
int counting(int n , int a[]  , int m )
{
    int sum = 0 ;
    for(int i = 0 ; i< m ; i++){
        if(n>= a[i]) sum++ ;
    }
    return sum ;
}
int main(){

    int n , m ;
    scanf("%d" ,&m ) ;
    scanf("%d" , &n) ;
    const int N= n ;
    const int M = m ;
    int am[M] , an[N] ; 
    int count[N] ;
    for(int i = 0 ; i < m ; i++ ){
        scanf("%d" , &am[i]) ;
    }
    for(int i = 0 ; i < n ; i++ ){
        scanf("%d" , &an[i]) ;
        count[i] = counting(an[i] , am , m) ;
    }
    for(int i = 0 ; i< n ; i++ ){
        printf("%d" , count[i]) ;
        if(i != n-1) printf(" " ) ;
    }

    return 0 ;
}