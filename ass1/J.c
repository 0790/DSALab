#include <stdio.h>
// using namespace std;

#define endl "\n"

int main()
{
	
  int n;
  printf("Enter the number of vertices \n");
  scanf("%d",&n);
  printf("Enter the adjacency matrix\n");
  // cin>>n;
  int a[n][n],s=0,m=0,adj[n][n+1];
  for (int i = 0; i < n; ++i)
  {
    adj[i][n]=0;
    /* code */
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      scanf("%d",&a[i][j]);

      if(a[i][j]==1)
      {
        adj[i][adj[i][n]++]=j;
   
      }
      /* code */
    }

    /* code */
  }

  int V=n;
  int result[V]; 
  result[0]  = 0;
  for (int u = 1; u < V; u++) 
    result[u] = -1;  
  int available[V];
  for (int i = 0; i < V; ++i)
  {
    available[i]=0;
     /* code */
  } 
  for (int u = 1; u < V; u++) 
  { 

    for (int i=0; i <adj[u][n]; ++i) 
      if (result[adj[u][i]] != -1) 
        available[result[adj[u][i]]] = 1; 

      int cr; 
      for (cr = 0; cr < V; cr++) 
        if (available[cr] == 0) 
          break; 
        
        result[u] = cr; 

        for (int i = 0; i <adj[u][n]; ++i) 
          if (result[adj[u][i]] != -1) 
            available[result[adj[u][i]]] = 0; 
        } 

        for (int u = 0; u < V; u++) 
          printf("Vertex %d  :  Color %d\n",u,result[u]); 
        int c[n];
        for (int i = 0; i < n; ++i)
        {
          c[i]=0;
        /* code */
        }
        for (int i = 0; i < n; ++i)
        {
          c[result[i]]=1;
        /* code */
        }
        int ans=0;
        for (int i = 0; i < n; ++i)
        {
          if(c[i]==1)
            ans++;
        /* code */
        }
  
        printf("chromatic number = %d\n",ans);

        return 0;


      }
