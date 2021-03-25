#include<stdio.h>
int Bx[1000] , By[1000] ;
void insertionSort(int arr[], int n)
{
    int i, key, key2, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
  
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            
            j = j - 1;
        }
        arr[j + 1] = key;
       
    }
}
int main()
{
    int n, c, d, k ;
    scanf("%d" ,&n);
    scanf("%d" , &c) ;
    scanf("%d" , &d) ;
    scanf("%d" , &k) ;
    const int N = n  ;
    const int C = c  ;
    const int D = d  ;
    float a[N][2] ;
    int x, y;
    int L[N] , M[N];
    for(int i = 0 ; i < N ; i++){
        scanf("%f" , &a[i][0] ) ;
        scanf("%f" , &a[i][1] ) ; 
        x = (int)a[i][0] ;
        y = (int)a[i][1] ;
        Bx[x]++ ;
        By[y]++ ;
    }
    for(int i = 0 ; i  < N ; i++){
        x = (int)a[i][0] ;
        y = (int)a[i][1] ;
        L[i] = Bx[x] * By[y] ;
        M[i] = L[i] ;
    }
    insertionSort(L,N) ;
    
    for(int i = 0 ; i < k ; i++){
        int flag = -1 ; 
        int a = L[i] ;
        for(int j = 0 ; j < N && flag == -1 ; j++ ){
            if(a == M[j] )flag = j ;
        }
        printf("%d" , flag ) ;
        if(i <= k-2)printf(" ") ;
    }


    return 0 ;
}