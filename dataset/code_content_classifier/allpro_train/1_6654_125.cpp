#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,i,t,r;
	int x[100000]={0};
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i)scanf("%d",&t),x[i]=t+x[i-1];
	for(i=r=0;m--;)
	{
		scanf("%d",&t);
		r=(r+abs(x[i]-x[i+t]))%100000;
		i+=t;
	}
	printf("%d\n",r);
	return 0;
}