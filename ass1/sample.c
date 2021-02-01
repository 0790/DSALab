#include<stdio.h>
void main()
{
    char arr[10]  ;
    scanf("%s" , arr) ;
    int a[10] ;
    for(int i = 0 ; arr[i] != '\0' ; i++) 
    {
        a[i] = arr[i] -48 ;
        printf("%d ", a[i]) ;

    }
    printf("\n%s" , arr) ;
}