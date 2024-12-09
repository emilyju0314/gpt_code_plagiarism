#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,c,l[7],f[305][1<<5][305],p[6];
double ans;
bool flag[6];
void DP()
{
	memset(f,0,sizeof(f));
	f[0][0][l[0]*(n+1)]=1;
	for(int i=1;i<=c*(n+1);i++)
	{
		for(int s=0;s<(1<<n);s++)
		{
			for(int r=i;r<=c*(n+1);r++)
			{
				if(f[i-1][s][r]==0)continue;
				f[i][s][r]+=f[i-1][s][r];
				int t=i%(n+1);
				if(t==0||((1<<(t-1))&s))continue;
				f[i][s|(1<<(t-1))][min(max(r,i+l[p[t]]*(n+1)),c*(n+1))]+=f[i-1][s][r];
			}
		}
	}
	ans+=f[c*(n+1)][(1<<n)-1][c*(n+1)];
}
void dfs(int step)
{
	if(step>n)return DP();
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		p[step]=i;
		flag[i]=1;
		dfs(step+1);
		flag[i]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)scanf("%d",&l[i]);
	sort(l+1,l+n+1);
	l[0]=l[n];
	n--;
	dfs(1);
	for(int i=1;i<=n;i++)ans/=c*i;
	printf("%.16lf\n",ans);
	return 0;
}