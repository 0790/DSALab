#include <stdio.h>
#include<string.h>
int len(char s[])
{
    int ct=0;
    while(s[ct]!='\0')
        ct++;
    return ct;
}

void num_merge(char n1[],char n2[],int n,int m,char n3[])
{
    int i=0;
    int j=0;
    int k=0;
    while(i<n&&j<m)
    {
        if(n1[i]>n2[j])
        {
            n3[k]=n1[i];
            n1[i]=-1;
            i++;
        }
        else if(n1[i]<n2[j])
        {
            n3[k]=n2[j];
            n2[j]=-1;
            j++;
        }
        else if(n1[i]==n2[j])
        {
            int o=i;
            int p=j;
            while(n1[o]==n2[p]&&o<n&&p<m)
            {
                o++;
                p++;
            }
            if(n1[o]>n2[p])
            {
                n3[k]=n1[i];
                n1[i]=-1;
                i++;
            }
            else if(n1[o]<n2[p])
            {
                n3[k]=n2[j];
                n2[j]=-1;
                j++;
            }
            else if(n1[o]==n2[p])
            {
                n3[k]=n2[j];
                n2[j]=-1;
                j++;
            }
        }
        k++;
    }
    while(i<n)
        n3[k++]=n1[i++];
    while(j<m)
        n3[k++]=n2[j++];
}

int main()
{
    char n1[250],n2[250];
    char n3[500]="" , n4[500];
    char temp;
    scanf("%s",n1);
    scanf("%c",&temp);
    scanf("%s",n2);
    scanf("%c",&temp);
    num_merge(n1,n2,len(n1),len(n2),n3);
    printf("%s\n",n3);
    return 0; 
}