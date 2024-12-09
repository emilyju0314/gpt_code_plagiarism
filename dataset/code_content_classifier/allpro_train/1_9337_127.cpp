#include<bits/stdc++.h>
using namespace std;

const int mo=1e9+7;

int n,m,k;
int g[21][21],dp[2][1<<19],S0[21][1<<19];

int main()
{
#ifdef h10
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	int i,j,S,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	memset(g,-1,sizeof(g));
	for (i=1;i<=k;i++)
		scanf("%d%d%d",&a,&b,&c),g[a][b]=c;
	for (i=1;i<n;i++)
	for (S=0;S<1<<(n-1);S++)
	{
		S0[i][S]=S|(1<<(i-1));
		for (j=i;j<n-1;j++)
			if ((S0[i][S]>>j)&1) {S0[i][S]-=1<<j; break;}
	}

	int fk=1;
	dp[fk][0]=1;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<n;j++)
		{
			memset(dp[fk^1],0,sizeof(dp[fk^1]));
			for (S=0;S<1<<(n-1);S++) if (dp[fk][S])
			{
				int tmp=dp[fk][S];
				if ((S>>(j-1))&1)
					(dp[fk^1][S]+=g[i][j]==0?0:tmp)%=mo;
				else
				{
					if (g[i][j]!=1)
						(dp[fk^1][S]+=tmp)%=mo;
					if (g[i][j]!=0)
						(dp[fk^1][S0[j][S]]+=tmp)%=mo;
				}
			}
			fk^=1;
		}
	}
	int Ans=0;
	for (S=0;S<1<<(n-1);S++)
		(Ans+=dp[fk][S])%=mo;
	printf("%d\n",Ans);
}
