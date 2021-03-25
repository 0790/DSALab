#include<stdio.h>
int main(){
    int n , k , X ;
    scanf("%d" ,&n);
    scanf("%d" , &k) ;
    scanf("%d" , &X) ;
    const int N = n ;
    const int K = k ;
    int S[N], r[K];
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &S[i] ) ;
       
    }
    for(int i = 0 ; i < K ; i++){
        scanf("%d" , &r[i]) ;
    }
    int sum = 0 ;
    for(int i = 0 ; i < N ; i++){
        int flag = 0 ; 
        for(int j =0 ; j < K && flag ==0 ; j++){
            if( i == r[j]) flag = 1 ;
        }
        if(flag == 0 )sum += S[i] ;
    }
    printf("%d " , sum) ;
    int max = 0 ;
    for(int j = 0 ; j < K ; j++){
        int count = 0 ; 
        for(int i = r[j] , k = 0 ; k < X && i < N ; i++ , k++){
                count+=   S[i] ;         
        }
        if(count> max) max = count ;
    }
    printf("%d" , max+sum) ;

    return 0 ;
}