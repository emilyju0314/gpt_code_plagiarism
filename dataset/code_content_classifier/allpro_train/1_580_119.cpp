#include<bits/stdc++.h>
using namespace std;
int f[101][100001],a[100001];
int main()
{
	int i,n,j,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0][0]=1;
	for(i=0;i<=k;i++)
		f[0][i]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			f[i][j]=f[i-1][j];
			if(j-a[i]-1>=0)
				f[i][j]=(f[i][j]+1000000007-f[i-1][j-a[i]-1])%1000000007;
		}
		for(j=1;j<=k;j++)
			f[i][j]=(f[i][j]+f[i][j-1])%1000000007;
	}
	printf("%d",(f[n][k]-f[n][k-1]+1000000007)%1000000007);
	return 0;
}