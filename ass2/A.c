#include<stdio.h>
#include<math.h>
int f(int n)
{
    int flag = 0 ,  sum = 0 ;
    for(int i =2 ; i<= sqrt(n) && flag != 2 ; i++){
        if(n%i == 0){
            sum+= f(n/i) ; 
            
            flag++ ; 
        }
    }
    if(flag == 0 || flag == 1) return n ;
    else return sum ;
}
int main()
{
    int n , ans;
    scanf("%d" , &n) ;
    ans = f(n) ;
    printf("%d" , ans) ;
    return 0 ;
}