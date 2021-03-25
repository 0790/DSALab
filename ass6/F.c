#include<stdio.h>
int main(){
    int n , t;
    scanf("%d" ,&n) ;
    scanf("%d" , &t) ;
    const int N= n ;
    const int T = t ;
    int a[N] , b ;
    for(int i = 0 ;i < N ; i++){
        scanf("%d" , &a[i]) ;
    }
    for(int i = 0 ;i < T ; i++){
        scanf("%d" , &b) ;
        for(int j= 0 ; j < b ; j++ ){
            int temp = a[0] ;
            int k = 1 ;
            while(k < n)
            {
                a[k-1] = a[k] ;
                k++;
            }
            a[k-1] = temp ;
                       
        }
         printf("%d %d" , a[0] , a[n-1]) ;
            if(i <= T-2)printf("\n") ;

    }
    return 0 ;
}