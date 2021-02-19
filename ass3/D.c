#include<stdio.h>
void count(int n , int x[] , int y[] , int k1 ,int k2){
    int c = 0 ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++)
        {
          
            if((x[i]+x[j] +k1) > (y[i] +y[j] +k2) ){
                c++ ;
                
            }
        }
    }
    
    printf("%d" , c) ;
}
int main(){
    int n , k1 ,k2 ;
    scanf("%d" , &n) ;
    scanf("%d" , &k1) ;
    scanf("%d" , &k2) ;
    const int N = n ;
    int x[N] , y[N] ;
    for(int i = 0 ; i< N ; i++)
    {
        scanf("%d" , &x[i]) ;
    }
    for(int i = 0 ; i< N ; i++)
    {
        scanf("%d" , &y[i]) ;
    }
    count(n ,x,y,k1,k2);
    return 0 ;
}