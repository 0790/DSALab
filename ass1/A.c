
#include <stdio.h>

int total=0;
int count=0;
int scount=0;

void substring(int n)
{
    if(total==n)
        return;
    char a;  
    scanf("%c",&a);
    total++;
    if(a=='b')
    {
        if(count==0)
        {
            count++;
            substring(n);
        }
        if(count==3)
        {
            if(scount==0)
            {
                scount++;
                count=1;
                printf("YES %d ",((total)-3));
                substring(n);
            }
            else
            {
                scount++;
                count=1;
                printf("%d ",((total)-3));
                substring(n);
            }
        }
        else
        {
            count=1;
        }
    }
    if(a=='a')
    {
       if(count==1)
       {
           count++;
           substring(n);
       }
       if(count==2)
       {
           count++;
           substring(n);
       }
       else
       {
           count=0;
           substring(n);
       }  
    }
}
int main()
{
    int n;
    char temp;
    scanf("%d",&n);
    scanf("%c",&temp);
    substring(n);
    if(!scount)
        printf("NO");
    return 0;
}