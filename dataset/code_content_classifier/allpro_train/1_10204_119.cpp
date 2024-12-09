#include <bits/stdc++.h>
using namespace std;
const int N=210000;
#define ll long long
#define PA pair<int,int>
int n,cnt;
int a[N],b[N],vis[N],neg[N<<1];
vector<int>v1,v2;
ll ans;
PA c[N<<1];
int main()
{
	//freopen("tt.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		v1.push_back(min(a[i],b[i]));
		v2.push_back(max(a[i],b[i]));
		c[++cnt]=PA(a[i],i);
		c[++cnt]=PA(b[i],i);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	ans=(ll)(v1[n-1]-v1[0])*(v2[n-1]-v2[0]);

	sort(c+1,c+1+cnt);
	for(int i=1,t;i<=cnt;i++)
	{
		if(!vis[t=c[i].second])vis[t]=i;
		else neg[i]=vis[t],neg[vis[t]]=i;
	}
	for(int i=1,r=0,num=0,t;i<=cnt;i++)
	{
		while(num!=n&&r<cnt)
		{
			r++;t=c[r].second;
			if(neg[r]<i||neg[r]>r)
				num++;
		}
		if(num==n)
			ans=min(ans,(ll)(c[cnt].first-c[1].first)*(c[r].first-c[i].first));
		if(neg[i]<i||neg[i]>r)
			num--;
	}
	printf("%lld\n",ans);
	return 0;
}
