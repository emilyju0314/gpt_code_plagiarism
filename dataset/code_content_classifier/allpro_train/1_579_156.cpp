#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[11][11],b[11];
int main()
{
	int n,m,i,j,k,ans=0;cin>>n>>m;int lim=(1<<n);
	for (i=1;i<=m;i++)
	{
		cin>>k;
		for (j=1;j<=k;j++) cin>>f[i][j];
	}
	for (i=1;i<=m;i++) cin>>b[i];
	for (i=0;i<lim;i++)
	{
		int flg=1;
		for (j=1;j<=m;j++)
		{
			int t=b[j];
			for (k=1;k<=n;k++)
			{
				t^=((i>>(f[j][k]-1))&1);
			}
			if (t) {flg=0;break;}
		}
		if (flg) ans++;
	}
	cout<<ans;
}
