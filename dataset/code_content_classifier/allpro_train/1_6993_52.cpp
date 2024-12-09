#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,l,r,L,R;
signed main()
{
	scanf("%lld%lld",&a,&b);
	if (a==b)
	{
		printf("1\n");
		return 0;
	}
	int wh,num=0;
	for (int i=63;i>=0;i--)
	{
		if (((a>>i)&1ll)!=((b>>i)&1ll))
		{
			wh=i;
			break;
		}
		else if ((a>>i)&1ll) num|=(1<<i);
	}
	r=b;
	for (int i=0;i<=wh;i++) r|=(1ll<<i);
	l=a|(1ll<<wh);
	L=a;R=b;
	for (int i=wh-1;i>=0;i--)
	{
		if ((b>>i)&1ll)
		{
			for (int j=0;j<=i;j++) R|=(1ll<<j);
			break;
		}
	}
	// printf("%lld %lld %lld %lld\n",l,r,L,R);
	if (R>=l) printf("%lld\n",r-L+1);
	else printf("%lld\n",R-L+1+r-l+1);
}