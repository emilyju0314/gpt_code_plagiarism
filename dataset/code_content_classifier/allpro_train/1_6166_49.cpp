#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000000],b[1000000];
int solve(int x,int y)
{
	int sum=0,ans=0;
	for(int i=0;i<n;i++) b[i]=a[i];
	for(int i=0;i<=x;i++) sum+=b[i];
	if(sum>=y) return 0;
	for(int i=x+1;i<n;i++)
	{
		int q=1ll<<(i-x),p=min(b[i],(y-sum)/q);
		sum+=p*q;
		b[i]-=p;
		b[x]+=p*q;
		ans+=p*(q-1);
	}
	int t=0;
	for(int i=0;i<=x;i++) t+=b[i]*((1ll<<i)-1);
	if(t+sum>=y) return ans+y-sum;
	for(int i=x+1;i<n;i++)
		if(b[i])
		{
			for(int j=i;j>x;j--)
			{
				int p=1ll<<(j-x);
				ans+=(y-sum)/p;
				if((y-sum)%p)
				{
					if(y-sum<p||!x) ++ans;
					else
					{
						int q=(y-sum)%p;
						ans+=q;
						sum+=q;			
					}
				}
			}
			return ans;
		}
	return -1;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int bo,x,y;
		scanf("%lld%lld%lld",&bo,&x,&y);
		if(bo&1) a[x]=y; else printf("%lld\n",solve(x,y));
	}
	return 0;
}