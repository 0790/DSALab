#include<stdio.h>
int t, n ;
struct coord{
    int x ,y , a;
}coor[10000] , c1[1000] , c2[1000] ;
int n1 , n2 ; 
void split(){
    int leftSum = 0, rightSum = 0, i, j;
    if( n == 1){
        n1 = 0 ; n2 = 0 ;
        return ;
    }
    for(i=0, j=n-1; i<=j ;){
      if(leftSum <= rightSum){
         leftSum+=coor[i].a;
         c1[n1].x = coor[i].x ;
         c1[n1].y = coor[i].y ;
         c1[n1].a = coor[i].a  ;
         n1++ ;
         i++;
      }else{
         rightSum+=coor[j].a;
         c2[n2].x = coor[j].x;
         c2[n2].y = coor[j].y;
         c2[n2].a = coor[j].a ;
         n2++ ;
         j--;
      }
  }
  if(leftSum!=rightSum){
      n1 = 0 ; n2 = 0 ;
  }
}
int check(struct coord c[], int no){

    int set , flag = 0;
    if(c[0].x >= c[0].y)set =1;
    else set = 0 ;
    for(int i = 1 ; i < no && flag == 0; i++){
        if(set == 1){
            if(c[i].x < c[i].y)flag = 1 ;
        }
        else if(set== 0){
            if(c[i].x >= c[i].y)flag =1 ; 
        }
    }
    return flag ;





}
int main()
{
    scanf("%d" , &t) ;
    for(int i = 0 ; i < t ; i++){
        int a, x , y;
        scanf("%d" , &n) ;
        for(int i  = 0 ; i < n ; i++){
            scanf("%d" , &x) ;
            scanf("%d" , &y) ;
            scanf("%d" , &a ) ;
            coor[i].x = x;
            coor[i].y = y ;
            coor[i].a = a ;

        }
        split() ; //printf("AFTER SPLITTING\n %d %d\n" , n1 , n2) ;
        if(n1 == 0 || n2 == 0){
            printf("NO");
            if(i != t-1)printf("\n") ;
            
        }
        else if(((c1[0].x > c1[0].y) && (c2[0].x < c2[0].y)) || ((c2[0].x > c2[0].y) && (c1[0].x < c1[0].y)) ){
           // printf("IN CHECKER CONDITION\n") ;
        int flag =  check(c1 , n1) ; int flag1 = check(c2,n2) ;
      //  printf("AFTER CHECK() %d %d\n" , flag , flag1);
         if(flag==1)
            {   printf("NO");
             if(i != t-1) printf("\n" ) ;
            }
            else if (flag1 == 1){
            
                printf("NO");
                if(i != t-1) printf("\n" ) ;
            
            }

            
        else if(flag == 0 && flag1== 0){
            printf("YES") ;
            if(i!= t-1)printf("\n") ;
        }
         }


    }
    return 0;
}