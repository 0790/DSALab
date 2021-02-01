#include <stdio.h> 
void largest(int arr[], int n, int max[]) 
{ 
    int i; 
     
    // Initialize maximum element 
    
    max[0]= arr[0]; 
  
    // Traverse array elements from second and 
    // compare every element with current max   
    for (i = 1; i < n; i++) 
        if (arr[i] > max[0]) 
            {max[0] = arr[i]; 
            max[1] = i ; } 
    
    
} 
void primeInRange(int L, int R) 
{ 
    int M ;
    int i, j,k ,  flag; if (L == 1|| L == 0) i = 2 ;else i = L ;
    int arr[10] ={[0 ... 9] 0 } ;
    for (; i <= R; i++) {  
        
        flag = 1;// printf("number %d\n ", i) ;
        for (j = 2; j <= i / 2 && flag ; ++j) { 
            if (i % j == 0) { 
                flag = 0; 
                
            } 
        }
        if (flag == 1) 
            //printf("%d ", i);
            {
                k = i ;
                while(k > 0)
                {
                    M = k%10 ;
                    arr[M]++ ;
                    k = k/10 ;
                }
            } 
    } 
   // quickSort(arr , 0 , 10) ;
   int a[2]; largest(arr,10,a ) ;
    printf("%d %d" , a[1] , a[0] ) ;
} 
  
// Driver Code 
int main() 
{ 
    // Given Range 
    int L ;
    scanf("%d" , &L ) ; 
    int R ; scanf("%d" , &R ) ; 
   
    primeInRange(L, R); 
  
    return 0; 
}
