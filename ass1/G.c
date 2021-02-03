#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100
 
#define initial 1
#define waiting 2
#define visited 3
 
int n;    /*Number of vertices in the graph*/
int adj[500][500]; /*Adjacency Matrix*/
int state[500]; /*can be initial, waiting or visited*/
int label[500]; /*Denotes the Component Number*/
int compno[500];
 
void create_graph();
void BF_Traversal();
void BFS(int v, int component_Num);
 
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
 
int main()
{
        create_graph();
        BF_Traversal();
}/*End of main()*/
 
void BF_Traversal()
{
        int v, components = 0;
 
        for(v=0;v<n;v++)
                state[v] = initial;
 
        components++;
    BFS(0, components); /*start BFS from vertex 0*/
 
        for(v=0; v<n; v++)
        {
                if(state[v] == initial)
                {
                        components++;
                        BFS(v, components);
                }
        }
        printf("%d\n", components);
        int k ;
        for(int i = 0 ; i < n ; i++)
        {
            k = label[i] ;
            compno[k-1]++ ;
        }
        for(int i = 0 ; i< components ; i++)
        {
            printf("%d" , compno[i]) ;
            if(i+1 != components)printf(" ") ; 
        }
 
}/*End of BF_Traversal()*/
 
void BFS(int v, int component_Num)
{
        int i;
 
        insert_queue(v);
        state[v] = waiting;
 
        while(!isEmpty_queue())
        {
                v = delete_queue();
                state[v] = visited;
                label[v] = component_Num;
               // printf("\nVertex %d  Component = %d\n",v, label[v]);
 
                for(i=0; i<n; i++)
                {
                        /* Check for adjacent unvisited vertices */
                        if( adj[v][i] == 1 && state[i] == initial)
                        {
                                insert_queue(i);
                                state[i] = waiting;
                        }
                }
        }
        
}/*End of BFS()*/
 
void insert_queue(int vertex)
{
        if (rear == MAX-1)
                printf("Queue Overflow\n");
        else
        {
                if(front == -1)  /*If queue is initially empty */
                        front = 0;
                rear = rear+1;
                queue[rear] = vertex ;
        }
}/*End of insert_queue()*/
 
int isEmpty_queue()
{
        if(front == -1 || front > rear )
                return 1;
        else
                return 0;
}/*End of isEmpty_queue()*/
 
int delete_queue()
{
        int del_item;
        if (front == -1 || front > rear)
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
 
        del_item = queue[front];
        front = front+1;
        return del_item;
 
}/*End of delete_queue() */
 
void create_graph()
{
        int i,max_edges,origin,destin;

        scanf("%d",&n);
        scanf("%d" ,&max_edges ) ; /*Undirected graph*/
 
        for(i=1;i<=max_edges;i++)
        {
                //printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
                scanf("%d %d",&origin,&destin);
 
                
                        adj[origin][destin]=1;
                        adj[destin][origin]=1;
                
        }
}