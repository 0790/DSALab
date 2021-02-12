#include<stdio.h>
int main(){
    int n , c ;
    scanf("%d" , &n) ;
    scanf("%d" , &c) ;
    const int N = n ; 
    int flag[26] = {[0 ... 25] 0};
    char a[N][20] ;
    for(int i = 0 ; i < N ; i++){
        scanf("%s" , a[i]) ;
        flag[a[i][0] - 65]++ ;
    }
    int sum = 0 ; 
    for(int i = 0 ; i < 26 ; i++){
        sum += flag[i] / c ; 

    }
    printf("%d" , sum ) ;
    return 0 ;
}