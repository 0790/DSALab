#include<stdio.h>
int findItems(int arr[], int n, int temp)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (temp/arr[i]);
    return ans;
}
 

int bs(int arr[], int n, int m, int high)
{
    int low = 1;
 
    // Doing binary search to find minimum
    // time.
    while (low < high)
    {
        // Finding the middle value.
        int mid = (low+high)/2;
 
        // Calculate number of items to
        // be produce in mid sec.
        int itm = findItems(arr, n, mid);
 
        // If items produce is less than
        // required, set low = mid + 1.
        if (itm < m)
            low = mid+1;
 
        //  Else set high = mid.
        else
            high = mid;
    }
 
    return high;
}
 
int minTime(int arr[], int n, int m)
{
    int maxval = -10000000;
 
    // Finding the maximum time in the array.
    for (int i = 0; i < n; i++)
       { if(maxval< arr[i])maxval = arr[i]; }

 
    return bs(arr, n, m, maxval*m);
}
int main(){
    int n , k ;
    scanf("%d" ,&n);
    scanf("%d" , &k) ;
    const int N = n ;
    int a[N];
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &a[i] ) ;
       
    }
   int A = minTime(a, N, k) ;
   printf("%d" , A) ;
}