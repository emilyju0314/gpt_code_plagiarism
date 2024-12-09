#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int g[100010],a[100010],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g[i]=gcd(g[i-1],a[i]);
	}
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		ans=max(ans,gcd(g[i-1],g[i+1]));
		g[i]=gcd(g[i+1],a[i]);
	}
	printf("%d\n",ans);
	return 0;
}