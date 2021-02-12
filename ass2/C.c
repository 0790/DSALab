#include <stdio.h>
 int a[1000][1000] ;
int main(){
	int i,j,k,n,count=0 , e1, e2;
 
	
	scanf("%d",&n);
    const int N = n ;
   
    int indeg[N] ,flag[N] ,carry[N];
     for(int i = 0 ; i < n ; i++){
        indeg[i] = flag[i] =carry[i] = 0 ;
    }
	
	for(i=0;i<(n*(n-1)/2) -1;i++){
		//scanf("%d",&a[i][j]);
        scanf("%d" ,&e1) ;
        scanf("%d" , &e2) ; 
        a[e1-1][e2-1] = 1; 
	}
    
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
           { indeg[i]=indeg[i]+a[j][i]; 
                if(a[i][j] == 1){
                    carry[i]++ ;
                    carry[j]++ ;
                }
           }
 
    
    int y = 0 ;
    while(count<n){
        for(k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
               // printf("%d ",(k+1));
               if(carry[k] == N-2){
                   printf("%d" , k+1) ; y++ ;
                   if(y < 2) printf(" ") ;
               }
               
                flag[k]=1;
            }
 
            for(i=0;i<n;i++){
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
 
        count++;
    }
 
    return 0;
}