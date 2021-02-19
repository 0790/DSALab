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
    int n = high ;
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high); 
  
         
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
    
} 
int find(int l , int L[] , float n){
    int temp = L[l-1], flag = 0 ;
    if(L[l-1] < n ) return -1 ;
    for(int i = l-2 ; i >= 0 && flag==0 ; i--){
        if(L[i] < n && flag == 0 ){flag =1 ;
        temp = L[i+1] ; } 
        else temp = L[i] ;
    }
    return temp ;
    

}
int main()
{
    int n ,m , l ;
    int u , v , a , b , k ;
    scanf("%d" , &n) ; 
    scanf("%d" , &m) ; 
    scanf("%d" , &l) ; 
    scanf("%d" , &u) ; 
    scanf("%d" , &v) ; 
    scanf("%d" , &a) ; 
    scanf("%d" , &b) ; 
    scanf("%d" , &k) ; 
    float z ;
    
    int count = 0 , temp, j =0;
    if(v < u) {
        temp = u ;
        u = v ;
        v = temp ;
    }
    const int M = m ;
    const int L = l ; 
    int c[M] , g[L];
    int sum = 0 ;
    for(int i = 0  ; i < m ; i++){
        scanf("%d" , &temp) ;
        if(temp>= u && temp <= v) 
        {
            count++ ;
            c[j] = temp ; j++ ;

        } 
    }
    
    quickSort(c , 0 , count-1) ;
    
    //printf("AFter sort 1\n") ;
    
    quickSort(g , 0 , l-1) ; 
   // printf("after sort 2\n");
   int flag= 0 ;
    for(int i = 1 ; i < count && flag == 0 ; i++){
        int dif = c[i] - c[i-1] ;
        z = (dif - b)/(float)a ;
        
       if(z > g[l] ) {
           printf("NOT POSSIBLE") ;
           return 0 ;
       }
        int y = find(l , g, z) ;
       // printf("%d %f %d \n" ,dif , z , y ) ;
        sum += 10*y;

        


    }
    
    printf("%d" , sum ) ;
    return 0 ;
}