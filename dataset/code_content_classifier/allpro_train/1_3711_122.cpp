#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,a[200005],b[200005];
int dp[4005][4005],ans;
int fac[8005],inv[8005];

int C(int x,int y){
	return 1ll*(1ll*fac[x]*inv[y]%mod)*inv[x-y]%mod;
}

int main(){
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=8000;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=8000;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=8000;i++) inv[i]=1ll*inv[i]*inv[i-1]%mod;
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
	for(int i=1;i<=n;i++) dp[2000-a[i]][2000-b[i]]++;
	for(int i=0;i<=4000;i++){
		for(int j=0;j<=4000;j++){
			if(i>0) dp[i][j]+=dp[i-1][j],dp[i][j]%=mod; 
			if(j>0) dp[i][j]+=dp[i][j-1],dp[i][j]%=mod;
		}
	}
	for(int i=1;i<=n;i++) ans+=dp[a[i]+2000][b[i]+2000],ans%=mod;
	for(int i=1;i<=n;i++) ans=(ans-C(2*a[i]+2*b[i],2*a[i])+mod)%mod;
	ans=1ll*ans*inv[2]%mod;
	printf("%d\n",ans);
	
	return 0;
}