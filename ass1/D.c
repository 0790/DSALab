#include <stdio.h> 
#include <math.h> 
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
  
void Set(int *set, int set_size, int budget) 
{ 
   
    const unsigned int pow_set_size = pow(2, set_size); 
    int counter, j; 
    int sum[pow_set_size] ;
  
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++) 
    { sum[counter] = 0 ;
    for(j = 0; j < set_size; j++) 
    { 
        
           // printf("%d ", 1<< j) ;
         if(counter & (1 << j)) {
             sum[counter] += set[j] ;
         }
         
    } 
   
    } 
    quickSort(sum, 0 , pow_set_size) ;
    int num = 0 , flag = 0 , check = 0 ;
    int  count1 = 0; 
    for(int i =0 ; i <pow_set_size && flag == 0; i++)
    {
        if(budget < sum[i] ) 
        {
            flag = 1 ;

        }
        else
        {
            count1 = 0 ;
            num = i ; 
            while (num > 0) {
                if (num & 1) {
                    count1++;
                }
                  num = num >> 1;
            }
            if(check < count1) check = count1 ;

        }
    }
       
    
    printf("%d" , count1) ;
    

} 
int main() 
{ 

    int n , budget ;
    scanf("%d" , &budget) ;
    scanf("%d" , &n) ;
    const int N = n ;
    int set[N] , temp , t = 0 ;
    for(int i =0 ; i < n ; i++)
    {
        scanf("%d", &temp ) ;
        if(temp <= budget){
            set[i] = temp ; 
            t++ ;
        }
    } 
    Set(set, t, budget); 
    return 0; 
} 