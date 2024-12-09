#include <bits/stdc++.h>
using namespace std;
long long int pp[100005],p[100005],ar[100005],n,k,x,y,z,ans,tut,top,maks;
int main()
{
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		p[i]=p[i-1]+x;
		if(x>0)
			pp[i]=pp[i-1]+x;
		else
			pp[i]=pp[i-1];
	}
	for(int i=1;i<=n-k+1;i++)
	{
		if(p[i+k-1]-p[i-1]>0)
			ans+=p[i+k-1]-p[i-1];
		ans+=pp[i-1];
		ans+=pp[n]-pp[i+k-1];
		if(ans>maks)
			maks=ans;
		ans=0;
	}
	printf("%lld",maks);
}
