#include<bits/stdc++.h>
using namespace std;

int n,L,x[300010],t[300010],dir[300010],col[300010],cn;
long long ans;

//0:don't change  1:change   2:--  3:(    4:)

int main()
{
	scanf("%d%d",&n,&L);
	for (int i=1; i<=n; i++) scanf("%d",&x[i]);
	for (int i=1; i<=n; i++) scanf("%d",&t[i]);
	for (int i=1; i<=n; i++)
	{
		long long t1=((t[i]%(2*L))<=(2*x[i])&&(t[i]%(2*L)!=0))?t[i]+(2ll*x[i]-(t[i]%(2*L))):t[i]+(2ll*L-(t[i]%(2*L)));
		long long t2=((t[i]%(2*L))<=(2*(L-x[i]))&&(t[i]%(2*L)!=0))?t[i]+(2ll*(L-x[i])-(t[i]%(2*L))):t[i]+(2ll*L-(t[i]%(2*L)));
		if (t[i]%(2*L)==0) t1-=(2*L),t2-=(2*L);
		long long ans1=(t1/(2*L))*2+((t[i]%(2*L))<=(2*x[i])&&(t[i]%(2*L)!=0)),ans2=(t2/(2*L))*2+((t[i]%(2*L))<=(2*(L-x[i]))&&(t[i]%(2*L)!=0));
		ans+=min(ans1,ans2);
		if (ans1<ans2)
		{
			if ((t[i]%(2*L))<=(2*x[i])&&(t[i]%(2*L)!=0)) dir[i]=3; else dir[i]=2;
		} else
		if (ans1>ans2)
		{
			if ((t[i]%(2*L))<=2*(L-x[i])&&(t[i]%(2*L)!=0)) dir[i]=4; else dir[i]=2;
		} else
		if ((t[i]%(2*L))<=(2*x[i])&&(t[i]%(2*L)!=0)) dir[i]=1; else dir[i]=0;
	}
	for (int i=1; i<=n; i++) 
		if (dir[i]==1) col[++cn]=0; else
		if (dir[i]==3) col[++cn]=1; else
		if (dir[i]==4) col[++cn]=2;
	if (dir[n]==0||dir[n]==2) col[++cn]=2,ans++;
	int l=0,r=0;
	for (int i=1; i<cn; i++)
	{
		if (col[i]==0) l--,r++; else
		if (col[i]==1) l++,r++; else l--,r--;
		if (r<0) ans-=r,l=r=0; else
		if (l<0) l=(r&1);
	}
	if (col[cn]==0) l--,r++; else
	if (col[cn]==1) l++,r++; else l--,r--;
	ans+=(l+1);
	printf("%lld\n",(ans+1)*L);
	return 0;
}