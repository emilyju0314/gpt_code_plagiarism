#include<iostream>
#include<cstdio>
#include<cstring>
const int N=100100;
int a[N];
int n,L;
int main()
{
	scanf("%d%d",&n,&L);
	int flag=0,p=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(i>1 && a[i]+a[i-1]>=L)flag=1,p=i-1;
	}
	if(!flag)printf("Impossible\n");
	else 
	{
		printf("Possible\n");
		for(int i=1;i<p;i++)
			printf("%d\n",i);
		for(int i=n-1;i>p;i--)
			printf("%d\n",i);
		printf("%d\n",p);
	}
	return 0;
}
