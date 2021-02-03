#include<stdio.h>
int G[500][500],x[500];
char v1[500] ; //G:adjacency matrix,x:colors
void next_color(int k){
   int i,j;
   x[k]=1;  //coloring vertex with color1
   for(i=0;i<k;i++){ //checking all k-1 vertices-backtracking
     if(G[i][k]!=0 && x[k]==x[i])  //if connected and has same color
       x[k]=x[i]+1;  //assign higher color than x[i]
   }
}

int main(){
  int n,e,i,j,k,l;
 
  scanf("%d",&n);  //total vertices

  scanf("%d",&e);  //total edges
 
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j]=0;  //assign 0 to all index of adjacency matrix
     
  
  for(i=0;i<e;i++){
    scanf("%d %d",&k,&l);
    G[k][l]=1;
    G[l][k]=1;
  }
 
  for(i=0;i<n;i++)
    next_color(i);  //coloring each vertex

  
  int flag = 0 ;
  
  for(i=0; i<n && flag == 0;i++)  //displaying color of each vertex
    {
      //printf("Vertex[%d] : %d\n",i+1,x[i]);
      if(x[i] >2 ) {
        printf("NEED MORE COLOURS") ;
        flag = 1 ;
      }
      else if(x[i] == 1) v1[i] = 'R' ; 
      else if(x[i] == 2) v1[i] = 'B' ;
      }
      for(int i = 0 ; i < n ; i++)
      {
        printf("%c",v1[i]);
      }
        return 0;
}