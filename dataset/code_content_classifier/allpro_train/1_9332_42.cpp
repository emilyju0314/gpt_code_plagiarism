#include<stdio.h>
int main()
{
	int n, a, b, i, count =0, t, c;
	scanf("%d", &n);
	scanf("%d", &a);
	for(i=1; i<n; i++)
	{
		c = 0;
		scanf("%d", &b);
		while(b<=a && i<n)
		{
			c++;
			a=b;
			scanf("%d", &b);
			i++;
		}
		if(c>count) count = c;
		a=b;
	}
	printf("%d\n", count);
}