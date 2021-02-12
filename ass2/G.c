#include<stdio.h>
#include<stdio.h> 
  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];  
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
       
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
      
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int findPairs(int arr[],int n,int x, int flag[]) 
{ 
    int l = 0, r = n-1; 
    int result = 0; 
  
    while (l < r) 
    { 
   
        if (arr[l] + arr[r] <= x && flag[l] == 0 && flag[r] == 0 ) 
        { 
            result++; 
            flag[l] = 1 ;
            flag[r] = 1 ; //printf("%d , %d \n " , arr[l] , arr[r]) ;
            l++; 
        } 
  
        // Move to smaller value 
        else
            r--; 
    } 
  
    return result; 
} 
  
int main()
{
    int n , B ;
    scanf("%d" , &n ) ;
    const int N = n ;
    int arr[N] ,flag[N] ;

    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &arr[i] ) ;
        flag[i] = 0 ;
        
    }
    scanf("%d" , &B) ;
    quickSort(arr, 0, N-1) ;
    int m = findPairs(arr,N,B, flag) ;
    printf("%d" , m ) ;
    return 0 ;
}