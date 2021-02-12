#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;
    char temp;
    scanf("%d %d",&n,&k);
    scanf("%c",&temp);
    char c[n];
    scanf("%s",c);
    scanf("%c",&temp);
    
    //calculate n^k
    int power = 1, temp1=k;
    while(temp1>0)
    {
        temp1--;
        power*=n;
    }
    
    
    int bits=0; //number of bits. 
    for(int m=power-1;m!=0;m=m/n)
        bits++;
    for(int i=0;i<power;i++)
    {
        int p=0, bits1=0; 
        int array[bits];
        
        for(int z=i; z!=0; z=z/n)
            bits1++; //number of bits in the number
            
        for(int z=0; z<bits-bits1 ;z++)
            printf("%c",c[0]);
            
        //binary
        for(int z=i; z!=0; z=z/n)
            array[p++]=z%n; 
            
        //print from back
        for(int z=p-1;z>=0;z--)
            printf("%c",c[array[z]]); 
        printf("\n");
    }
    return 0;
}