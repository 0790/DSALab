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
int prob[10000] = {[0 ... 9999] 1} ;
double stack[10000] ; int nstack ;
void calc(int k){
    for(int i = 0 ; i < nstack ; i++){
        prob[k] *= stack[i] ;
    }
}
void DFS(int s , int e){
    stack[nstack] = s ;
    if()



}
void DFSCall(int s, int i){
    for(int i = 0 ; i < n ; i++)
    {
        vis[i] = 0 ;
    }
    nstack = 0 ;
    DFS(s,i) ;
}
int main(){
    scanf("%d" , &n ) ;
    scanf("%d" , &e ) ;
    scanf("%d" , &s ) ;
    for(int i = 0 ; i < e ; i++){
        scanf("%d" , &e1 ) ;scanf("%d" , &e2 ) ;scanf("%lld" , &w ) ;
        graph[i].start = e1 ;
        graph[i].end = e2 ;
        graph[i].p = w ;
        prob[(int)(graph[i].start)] -= w ; 
    }

    for(int i = 0 ; i < n ; i++){
        if(i != s)DFSCall(s,i) ; 
    }

    return 0 ;
}