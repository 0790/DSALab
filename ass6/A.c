#include<stdio.h>
int a[10000] ;
void insertionSort(int arr[], int n)
{
    int i, key, key2, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        key2 = a[i] ;
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            a[j+1] = a[j] ;
            j = j - 1;
        }
        arr[j + 1] = key;
        a[j+1] = key2;
    }
}
int main(){
    int n , k ;
    scanf("%d" ,&n);
    scanf("%d" , &k) ;
    const int N = n ;
    int b[N];
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &a[i] ) ;
        b[i] = a[i] % k ;
    }
    insertionSort(b, N) ;
    for(int i = 0 ; i < N ;i++){
        printf("%d" , a[i] ) ;
        if(i <= N-2) printf(" ") ;
    }
    return 0 ;
}