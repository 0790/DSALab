#include<stdio.h>
int total(int a , int b[] , int g[] , int m ){
    int tot = 0 ;
    for(int  i = 0 ; i<m ; i++){
        if(a >= b[i])
        {
            tot += g[i] ;
        }
    }
    return tot ;
}
int main(){
    int n , m ;
    scanf("%d" ,&n) ;
    scanf("%d" , &m) ;
    const int N = n ;
    const int M = m ;
    int a[N] , b[M] , g[M] , t[N] ;
    for(int i= 0 ; i < N ; i++){
        t[i] = 0  ;
        scanf("%d" , &a[i] ) ;
    }
    for(int j = 0 ; j < M ; j++) 
    {
        scanf("%d" , &b[j] ) ;
        scanf("%d" , &g[j]) ;
    }
    for(int i =0 ; i < N ; i++){
        t[i] = total(a[i] , b , g , m) ;
        printf("%d" , t[i] ) ;
        if(i != N-1) printf(" ") ;
    }



    return 0 ;
}