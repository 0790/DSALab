#include<stdio.h>
struct coord{
    int x ;
    int y ;
} q1[1000] , q2[1000] , q3[1000] , q4[1000];
int n, n1,n2,n3,n4 ;
int sum;
int ab(int a ){
    if(a>=0 )return a;
    else return -1*a ;
}
void sortasc(){
    int tx,ty ;int d , flag = 0 ;
    for (int c = 1 ; c <= n1 - 1; c++) {
    tx = q1[c].x;
    ty = q1[c].y ;
    for ( d = c - 1 ; d >= 0; d--) {
      if (q1[d].y > ty) {
        q1[d+1].y = q1[d].y;
        q1[d+1].x = q1[d].x ;
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      q1[d+1].y = ty;
      q1[d+1].x = tx ;
  }



  // for 4th quad
  for (int c = 1 ; c <= n4 - 1; c++) {
    tx = q4[c].x;
    ty = q4[c].y ;
    for ( d = c - 1 ; d >= 0; d--) {
      if (q4[d].y > ty) {
        q4[d+1].y = q4[d].y;
        q4[d+1].x = q4[d].x ;
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      q4[d+1].y = ty;
      q4[d+1].x = tx ;
  }
}
void sortdsc(){
    int tx,ty,d, flag;
    for (int c = 1 ; c <= n2 - 1; c++) {
    tx = q2[c].x;
    ty = q2[c].y ;
    for ( d = c - 1 ; d >= 0; d--) {
      if (q2[d].y < ty) {
        q2[d+1].y = q2[d].y;
        q2[d+1].x = q2[d].x ;
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      q2[d+1].y = ty;
      q2[d+1].x = tx ;
  }

  //for 3rd quad
   for (int c = 1 ; c <= n2 - 1; c++) {
    tx = q3[c].x;
    ty = q3[c].y ;
    for ( d = c - 1 ; d >= 0; d--) {
      if (q3[d].y < ty) {
        q3[d+1].y = q3[d].y;
        q3[d+1].x = q3[d].x ;
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      q3[d+1].y = ty;
      q3[d+1].x = tx ;
  }
   
}
int main(){  

    scanf("%d" , &n) ;
    int x , y ; n1=n2=n3=n4 = 0 ; 
    for(int i = 0; i < n ; i++ ){ 
        scanf("%d" , &x) ;
        scanf("%d" , &y) ;
        if(x>= 0){
            if(y>=0){
                q1[n1].x = x;
                q1[n1].y = y;
                n1++ ;
            }
            else {
                q4[n4].x=x;
                q4[n4].y = y ;
                n4++;
            }
        }
        else{
            if(y>=0){
                q2[n2].x = x;
                q2[n2].y = y;
                n2++ ;
            }
            else {
                q3[n3].x=x;
                q3[n3].y = y ;
                n3++;
            }
        }
    }
    sortasc();
    sortdsc() ;
     for(int i = 0 ; i < n1-1 ; i++){
         sum += ab(q1[i].x - q1[i+1].x) + ab(q1[i].y - q1[i+1].y) ;

     }
      for(int i = 0 ; i < n2-1 ; i++){
         sum += ab(q2[i].x - q2[i+1].x) + ab(q2[i].y - q2[i+1].y) ;

     }
      for(int i = 0 ; i < n3-1 ; i++){
         sum += ab(q3[i].x - q3[i+1].x) + ab(q3[i].y - q3[i+1].y) ;

     }
      for(int i = 0 ; i < n4-1 ; i++){
         sum += ab(q4[i].x - q4[i+1].x) + ab(q4[i].y - q4[i+1].y) ;

     }

  if(n1>0){
      if(n2>0){
          sum+= ab(q1[n1-1].x - q2[0].x) + ab(q1[n1-1].y - q2[0].y  ) ;
      }
      else if(n3>0){
          sum+= ab(q1[n1-1].x - q3[0].x) + ab(q1[n1-1].y - q3[0].y  ) ;
      }
      else if(n4>0){
          sum+= ab(q1[n1-1].x - q4[0].x) + ab(q1[n1-1].y - q4[0].y  ) ;
      }
      else sum+= ab(q1[n1-1].x - q1[0].x) + ab(q1[n1-1].y - q1[0].y  ) ;
  }
  if(n2>0){
      if(n3>0){
          sum+= ab(q2[n2-1].x - q3[0].x) + ab(q2[n2-1].y - q3[0].y  ) ;
      }
      else if(n4>0){
          sum+= ab(q2[n2-1].x - q4[0].x) + ab(q2[n2-1].y - q4[0].y  ) ;
      }
      else if(n1>0){
          sum+= ab(q2[n2-1].x - q1[0].x) + ab(q2[n2-1].y - q1[0].y  ) ;
      }
      else sum+= ab(q2[n2-1].x - q2[0].x) + ab(q2[n2-1].y - q2[0].y  ) ;
  }
  //for connecting third
  if(n3>0){
      if(n4>0){
          sum+= ab(q3[n3-1].x - q4[0].x) + ab(q3[n3-1].y - q4[0].y  ) ;
      }
      else if(n1>0){
          sum+= ab(q3[n3-1].x - q1[0].x) + ab(q3[n3-1].y - q1[0].y  ) ;
      }
      else if(n2>0){
          sum+= ab(q3[n3-1].x - q2[0].x) + ab(q3[n3-1].y - q2[0].y  ) ;
      }
      else sum+= ab(q3[n3-1].x - q3[0].x) + ab(q3[n3-1].y - q3[0].y  ) ;
  }
  //for connecting fourth 
  if(n4>0){
      if(n1>0){ 
          sum+= ab(q4[n4-1].x - q1[0].x) + ab(q4[n4-1].y - q1[0].y  ) ;
      }
      else if(n2>0){
          sum+= ab(q4[n4-1].x - q2[0].x) + ab(q4[n4-1].y - q2[0].y  ) ;
      }
      else if(n3>0){
          sum+= ab(q4[n4-1].x -  q3[0].x) + ab(q4[n4-1].y - q3[0].y  ) ;
      }
      else sum+= ab(q4[n4-1].x - q4[0].x) + ab(q4[n4-1].y - q4[0].y  ) ;
  }
    printf("%d", sum) ;


    return 0 ;
}