#include<stdio.h>
#include<stdlib.h>
 
#define MAX 26
 
void create_graph();
void add(int vertex);
int del();
int isEmpty();
int find_indegree_of_vertex(int vertex);
 
int total_vertices;
int adjacent_matrix[MAX][MAX];
int queue[MAX];
int vertices[MAX]={ [0 ... MAX-1]  -1 } ;
int front = -1;
int rear = -1;

int main()
{
      int i, vertex, count, topological_sort[MAX], indegree[MAX];
      create_graph();
      for(i = 0; i < total_vertices; i++)
      {
            indegree[i] = find_indegree_of_vertex(i);
            if(indegree[i] == 0)
            {
                  add(i);
            }
      }
      count = 0;
      while(!isEmpty() && count < total_vertices)
      {
            vertex = del();
            topological_sort[++count] = vertex;
            for(i = 0; i < total_vertices; i++)
            {
                  if(adjacent_matrix[vertex][i] == 1)
                  {
                        adjacent_matrix[vertex][i] = 0;
                        indegree[i] = indegree[i] - 1;
                        if(indegree[i] == 0)
                        {
                              add(i);
                        }
                  }
            }
      }
      
      if(count < total_vertices)
      {
            printf("ALIENS BE CRAZY");
            return 0;
      }
      
      for(i = 1; i <= count; i++)
      {
          for(int j = 0 ; j < 26 ; j++){
              if(topological_sort[i] == vertices[j]) printf("%c" , (char)(j+65) ) ; 
          }
          
      }
      
      return 0;
}
 
void add(int vertex)
{
      if(rear == MAX - 1)
      {
            printf("Queue Overflow\n");
      }
      else
      {
            if(front == -1) 
            {
                  front = 0;
            }
            rear = rear + 1;
            queue[rear] = vertex ;
      }
}
 
int isEmpty()
{
      if(front == -1 || front > rear)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
 
int del()
{
      int element;
      if(front == -1 || front > rear)
      {
            printf("Queue Underflow\n");
            exit(1);
      }
      else
      {
            element = queue[front];
            front = front + 1;
            return element;
      }
}
 
int find_indegree_of_vertex(int vertex)
{
      int count, total_indegree = 0;
      for(count = 0; count < total_vertices; count++)
      {
            if(adjacent_matrix[count][vertex] == 1)
            {
                  total_indegree++;
            }
      }
      return total_indegree;
}
 
void create_graph()
{
      int count, maximum_edges, origin_vertex, destination_vertex;
      char origin, destin, temp;
     
      scanf("%d", &maximum_edges);
    
     
      for(count = 1; count <= maximum_edges; count++)
      {
          
          scanf("%c", &temp);  scanf("%c", &origin);
          
           scanf("%c", &temp); scanf("%c", &destin);
           
                   origin_vertex = (int)(origin) -65;
                   destination_vertex=(int)(destin) -65;
                  // printf("%d %d" , origin_vertex-65,destination_vertex-65) ;
                  if(vertices[origin_vertex] == -1){ vertices[origin_vertex] = total_vertices ;
                   total_vertices++ ;}
                   if(vertices[destination_vertex] == -1){
                   vertices[destination_vertex] = total_vertices ;
                   total_vertices++ ;}
                   //printf("%d %d\n" , vertices[origin_vertex] , vertices[destination_vertex]) ;
                   adjacent_matrix[vertices[origin_vertex]][vertices[destination_vertex]] = 1;
        }
      
     
      
}