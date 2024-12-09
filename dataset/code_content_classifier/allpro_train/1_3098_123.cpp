#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=16,M=1<<15,mo=1e9+7;

typedef long long LL;

int n,m,T,f[M],g[N][M],cnt[N][M],p[M];

bool bz[N][M],ok[M];

int main()
{
	scanf("%d%d",&n,&m); T=1<<n;
	p[0]=1;
	for (int i=1;i<=n;i++) p[i]=p[i-1]*2;
	for (int i=0,x,y;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		bz[x][1<<y-1]=1;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<T;j++)
		{
			int k=j&-j;
			cnt[i][j]=cnt[i][j^k]+bz[i][k]; g[i][j]=p[cnt[i][j]]-1;
		}
	}
	for (int i=0;i<T;i++) ok[i]=(((1&i)>0)==((2&i)>0));
	f[0]=1;
	for (int i=1;i<T;i++) if (ok[i])
	{
		f[i]=1;
		for (int j=(i-1)&i;j;j=(j-1)&i) if (ok[j])
		{
			int k=i^j,s=f[k];
			for (int x=0;x<n;x++) if (((1<<x)&k)>0) s=(LL)s*g[x+1][j]%mo;
			else if (((1<<x)&j)>0) s=(LL)s*p[cnt[x+1][k]]%mo;
			f[i]=(f[i]+s)%mo;
		}
	}
	int ans=1;
	for (int i=0;i<m;i++) ans=ans*2%mo;
	ans=(ans-f[T-1]+mo)%mo;
	printf("%d\n",ans);
	return 0;
}