#include <stdio.h>
int power(int b);
int main()
{
	int n, sum, i ;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int j = 1 ;
	for(i = 0; i < n; i++)
	{
		sum = sum + (a[i]*j) ;
		if(power(j) == i+2)
			j++ ;
	}
	printf("%d", sum);
}
int power(int b)
{
	int r = 1, i ;
	for(i = 1; i <= b; i++)
		r = r * 2 ;
	return r ;
}