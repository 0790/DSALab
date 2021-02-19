#include<stdio.h>
int ice(int a[], int s[] , int n , int m , int k , int f1[] , int f2[]){
    int flag = 0 , up, down ;
    for(int i = 0 ; i < n ; i++){
        down = a[i] - k ;
        up = a[i] + k;
        for(int j = 0 ; j < m && f1[i] == 0 ; j++){
            if(s[j] >= down && s[j] <= up && f2[j] == 0){
                flag++ ; f1[i] = 1;
                f2[j] = 1 ;
            }
        }
    }
    return flag ;
}
int main()
{
    int n,m,k ;
    scanf("%d", &n ) ;
    scanf("%d", &m ) ;
    scanf("%d", &k ) ;
    const int N = n ;
    const int M = m ;
    int a[N] ,f1[N] , s[M] ,f2[M];
    for( int i = 0 ; i < N ; i++)
    {
        scanf("%d" , &a[i]) ;f1[i] = 0 ;
    }
    for(int j = 0 ; j < M ; j++){
        scanf("%d" , &s[j] ) ;
        f2[j] = 0 ;
    }
    int ans = ice(a,s,n,m,k,f1,f2) ;
    printf("%d" , ans) ;

    return 0 ;
}