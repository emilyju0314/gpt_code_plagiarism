#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18+7107;
int n,a[200005];
ll dpf[200005],dpb[200005],f[200005],sum[200005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ans=INF;
	for(int i=1;i<=n;i++)
	{
		dpf[i]=min(sum[i-1],dpf[i-1])+(a[i]&1);
		if(!a[i]) dpf[i]+=2;
		//printf("dpf(%d)=(%lld,%lld)\n",i,dpf[i][0],dpf[i][1]);
	}
	for(int i=n;i>=1;i--)
	{
		dpb[i]=min(sum[n]-sum[i],dpb[i+1])+(a[i]&1);
		if(!a[i]) dpb[i]+=2;
		//printf("dfb(%d)=(%lld,%lld)\n",i,dpb[i][0],dpb[i][1]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=min(min(sum[i-1],dpf[i-1]),f[i-1])+((a[i]&1)^1);
		ans=min(ans,min(f[i]+min(sum[n]-sum[i],dpb[i+1]),
			min(sum[i-1],dpf[i-1])+min(sum[n]-sum[i],dpb[i])));
		//printf("f(%d)=%lld\n",i,f[i]);
	}
	printf("%lld\n",ans);
	return 0;
}