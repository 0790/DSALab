#include <stdio.h>

int dist;

/* merge sort not wokring?
void mmerge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++)
        L[i]=a[p+i];
    for(int i=0;i<n2;i++)
        R[i]=a[q+1+i];
    L[n1]=1000000000;
    R[n1]=1000000000;
    int k=0,l=0;
    for(int i=p;i<=r;i++)
    {
        if(L[k]<=R[l])
        {
            a[i]=L[k];
            k++;
        }
        else
        {
            a[i]=R[l];
            l++;
        }
    }
}


void msort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        msort(a,p,q);
        msort(a,q+1,r);
        mmerge(a,p,q,r);
    }    
} */

void isort(int a[],int n)
{
    for(int j=1;j<n;j++)
    {
        int key=a[j];
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}

//basically a binary search for the distances
void find_dist(int a[], int n, int k)
{
    dist=-1;
    //min and max possible distances
    int l=1,h=a[n-1];
    while(l<h)
    {
        int mid=(l+h)/2;
        int flag=1;
        //checking if possible to place elements with a dist of mid
        int pos=a[0];
        int number=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]-pos>=mid)
            {
                pos=a[i];
                number++;
                if(number==k)
                    flag=0;
            }
        }
        //if possible, make the distance maximum of what it was initiially, and what it could be (mid), because we want min dist
        if(!flag)
        {
            if(dist<mid)
                dist=mid;
            l=mid+1;
        }
        //if not possible, search for a lower distance
        else
        {
            h=mid;
        }
    }
}

int main()
{
    int n,m;
    char temp;
    scanf("%d %d",&n,&m);
    scanf("%c",&temp);
    int a[n];
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    scanf("%c",&temp);
    isort(a,m);
    find_dist(a,m,n);
    printf("%d",dist);
    return 0;
}