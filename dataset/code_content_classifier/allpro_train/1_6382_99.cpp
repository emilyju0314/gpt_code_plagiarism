#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int quickpow(int x,int y)
{
	long long res=1,base=x;
	while(y)
	{
		if(y&1)res*=base,res%=mod;
		y>>=1;base*=base,base%=mod;
	}
	return res;
}
int inv(int x){return quickpow(x,mod-2);}
int prod[600002];
int c(int x,int y){return 1ll*prod[x]*inv(prod[x-y])%mod*inv(prod[y])%mod;}
signed main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	prod[0]=1;
	for(int i=1;i<=n*2;i++)
		prod[i]=1ll*prod[i-1]*i%mod;
/*	if(k>=n)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=1ll*c(n,i)*c(n-1,i-1)%mod,ans%=mod;
		printf("%d",ans);
		return 0;
	}*/
	int ans=0;
	for(int i=max(n-k,1);i<=n;i++)
		{
			ans+=1ll*c(n,i)*c(n-1,i-1)%mod,ans%=mod;
			
		}
	printf("%d",ans);
	return 0;
}
