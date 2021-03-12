#include<stdio.h>
int n , e ,s ;
int e1, e2;
double w ; 
struct edge{
    int start;
    int end ;
    double p ;
} graph[10000] ; 
int vis[10000] = {[0 ... 9999] 0} ;
int main(){
    scanf("%d" , &n ) ;
    scanf("%d" , &e ) ;
    scanf("%d" , &s ) ;
    for(int i = 0 ; i < e ; i++){
        scanf("%d" , &e1 ) ;scanf("%d" , &e2 ) ;scanf("%lld" , &w ) ;
        graph[i].start = e1 ;
        graph[i].end = e2 ;
        graph[i].p = w ;
    }


    return 0 ;
}