#include<stdio.h>
#include<math.h>
int main()
{
    int n , m ;
    scanf("%d" ,&n) ;
    scanf("%d" , &m) ;
    const int N= n , M = m ;
    long long int P[N] , Mul[M] ;
    for(int  i = 0 ; i < N ; i++ ){
        scanf("%lld" , &P[i] ) ;
    } 
    for(int i = 0 ; i< M ; i++){
        scanf("%lld" , &Mul[i]) ;

    }
    for(int i = 0 ; i <= N -M ; i++){
        for(int j = 0 ; j< M ; j++){
            P[j+i] *= Mul[j] ;
         }
    }
    for(int  i = 0 ; i < N ; i++ ){
        printf("%lld" , (P[i] % (long long int)(pow(10,9) + 7))) ;
        if(i != N-1) printf(" ") ;
    } 
    return 0 ; 
}