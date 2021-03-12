#include<stdio.h>
int n , q ;
int a[10000] ;
void sort(){
    int c ,d; int flag = 0 ; int t;
    for (c = 1 ; c <= n - 1; c++) {
    t = a[c];

    for (d = c - 1 ; d >= 0; d--) {
      if (a[d] > t) {
        a[d+1] = a[d];
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      a[d+1] = t;
  }
}
void binary(int search){
   int first = 0;
 int last = n - 1;
 int middle = (first+last)/2;

  while (first <= last) {
    if (a[middle] < search)
      first = middle + 1;
    else if (a[middle] == search) {
      printf("YES" );
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("NO");
}
int main(){

    scanf("%d" , &n) ;
    scanf("%d" , &q ) ;
    int k ;
    for(int i = 0 ; i < n ; i++ ){
        scanf("%d" , &a[i]) ;
    }
    sort() ;
    for(int i = 0 ; i < q ; i++) {
        scanf("%d" , &k) ;
        binary(k) ;
        if( i != q-1) printf("\n" ) ;
    }

    return 0 ;
}