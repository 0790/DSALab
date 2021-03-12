#include<stdio.h>
int n ;
char str[1000] ;
int max(int a , int b){
    if(a>b) return a;
    else return b ;
}
int areDistinct( int i, int j)
{
 
    // Note : Default values in visited are 0
    int visited[26];
    
    for (int k = i; k <= j; k++) {
        if (visited[(int)(str[k] - 'A')] == 1)
            return 0;
        visited[(int)(str[k] - 'A')] = 1;
    }
    return 1;
}

int longestUniqueSubsttr( )
{
    
    int res = 0; // result
    for (int i = 0; i < n; i++)
        { for (int j = i; j < n; j++)
           { 
              printf("" , i , j ) ;
              if (areDistinct( i, j) == 1 )
                      {  res = max(res, j - i + 1); 
                        // printf("res %d %c %c\n" , res , str[i] , str[j]) ;
                      }
            }
        }
    return res;
}
 
int main(){

    
    scanf("%d" , &n) ;
    char temp ; 
    scanf("%c" , &temp) ;
    
    for(int i = 0; i < n ; i++ ){
        scanf("%c" , &str[i]) ;
    }
    int count = longestUniqueSubsttr() ; 
    printf("%d" , count) ;
    return 0 ;
}