#include<stdio.h>
int count[1000] ;
int A[1000][1000] ;
int main()
{
    int a, p , c ;
    scanf("%d" , &a) ;
    scanf("%d" , &p ) ;
    scanf("%d" , &c) ;
    const int N = p ;
    const int M = a ;
    
    int P[N], e1, e2 ;
    for(int i = 0 ; i < p ; i++){
        scanf("%d" , &P[i]) ;
        count[P[i]]++ ; 

    }
    for(int i = 0 ; i < c ; i++)
    {
        scanf("%d" , &e1 ) ;
        scanf("%d" , &e2) ;
        A[e1][e2] = 1 ;
    }
    int indeg[N] ,flag[N] ,carry[N];
     for(int i = 0 ; i < N ; i++){
        indeg[i] = 0 ;
    }
    for(int i = 0 ; i < p ; i++){
        printf("%d " , indeg[i]) ;
        
    }
    printf("\n") ;
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++)
           { 
               indeg[i]=indeg[i]+A[j][i]; 
                
           }
    }
    int tot[M]; 
    for(int i = 0 ; i < a ; i++){
        tot[i] = p-1 ;
        printf("%d " , count[i]) ;
    }
    printf("\n") ;
    for(int i = 0 ; i < p ; i++){
        printf("%d " , P[i]) ;
        
    }
    printf("\n") ;
    for(int i = 0 ; i < p ; i++){
        printf("%d " , indeg[i]) ;
        
    }
    printf("\n") ;
    for(int i = 0 ; i < N ; i++){
        if(indeg[i] >= count[P[i]]){
            int max = indeg[i] ;
            if(max < tot[P[i]])tot[P[i]] = max ;
 
        }
        if(indeg[i] < count[P[i]]) tot[P[i]] = 0 ;
    }
    for(int i = 0 ; i < a ; i++){
        printf("%d" , tot[i]);
        if(i != a-1)printf(" ") ;
    }
    
    return 0 ;
}