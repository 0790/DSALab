#include<stdio.h>
#include<stdlib.h>

int main(){
    int no;
    scanf("%d", &no);
    long long int* mult_add = (long long int*)malloc(no * sizeof(long long int));
    char* op = (char*)malloc(no * sizeof(char));
    scanf("%*c");
    int loop_count = 0;
    for(int i=0; i<no; i++)
    {
        scanf("%c", &op[i]);
        scanf("%*c");
        scanf("%*c");
        if(op[i] == 'L')
        {
            for(int j=0; j<2; j++)
                scanf("%*c");
            scanf("%lld", &mult_add[i]);
            loop_count++;
        }
        else if(op[i] == 'F')
        {
            scanf("%lld", &mult_add[i]);
        }
        scanf("%*c");

    }
    long long int* multip = (long long int*)malloc(loop_count * sizeof(long long int));
    int multip_count = 0;
    long long int mult = 1;
    long long int sum = 0;
    for(int i=0; i<no; i++)
    {
        if(op[i] == 'F')
        {
            sum+=(mult*mult_add[i]);
        }
        else if(op[i] == 'L')
        {
            mult*=mult_add[i];
            multip[multip_count] = mult_add[i];
            multip_count++;
        }
        else if(op[i] == 'E')
        {
            mult/=multip[multip_count-1];
            multip[multip_count-1]=0;
            multip_count--;
        }
    }
    printf("%lld", sum);
}