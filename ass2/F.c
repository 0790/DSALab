#include<stdio.h>

int logaritm(int n)
{
    int ret = 0;
    while (n>>=1) 
    {
        ++ret;      
    }
    return ret;
}

int power(int x,int y)
{
    int ret=1,i=0;
    while(i<y)
    {
        ret*=x;
        i++;
    }
    return ret;
}

int getcount(int m,int k)
{
    if(m==0)return 1;
    if(k<0)return 0;
    if(k==0)return 1;
    if(m>=power(2,k))return getcount(m-power(2,k),k)+getcount(m,k-1);
    else return getcount(m,k-1);

}

int main()
{
    int m=0;
    int c = 0 ;
    scanf("%d" , &m) ; 
    
        int k=logaritm(m);
        c= getcount(m,k);
        printf("%d" , c) ;
    
    return 0;
}