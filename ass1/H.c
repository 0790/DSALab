#include<stdio.h>
void rotate(int a[], int n) {
    int temp ; 
    temp = a[n-1] ;
    for(int i = n-1 ; i > 0 ; i--  ){
        a[i] = a[i-1] ;
    }
    a[0] = temp ;
}
int cal(int a[], int n) {
    int sumo = 0 , sume = 0 ;
    rotate(a,n) ;
    for(int i = 0 ; i < n ; i++ ){ 
        if(i % 2 == 0) sume += a[i]*a[i] ;
        else sumo+= a[i]*a[i]*a[i] ;
 
    }
    return (sume - sumo) ;
}
void compare(int a[] , int n)
{
        int min = -10000 , max = 10000 , sum ;
        for(int i = 0 ; i < n ; i++)
        {
            
            sum = cal(a, n) ;
            if(i == 0 ) min = max = sum ;
            if(sum < min )min = sum ;
            else if(sum > max) max = sum ;

        }
        printf("%d" , max-min ) ;

}
int main()
{
    int n ;
    scanf("%d" ,&n) ;
    const int N = n ;
    int arr[N] ;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d" , &arr[i]) ;
    }
    compare(arr, n) ;
    return 0 ;
}