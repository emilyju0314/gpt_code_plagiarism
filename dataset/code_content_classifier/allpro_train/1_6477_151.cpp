/*只要保证这个颜色开始的第一个填在第一个空位上
之后的都随便填即可
所以方案数就是C(空格位置-1,数量-1),组合意义就是这个颜色的小球中有一个填的位置是被钦定的，然后有一个空位也是被钦定填的，所以都要-1*/
#include<bits/stdc++.h>
#define Mod 1000000007
#define N 2005
#define M N*N
using namespace std;
int n,K,dp[N][N],fac[M],inv[M];
inline int ksm(int x,int y){
	int ans1=1;while (y){
		if (y&1) ans1=1ll*ans1*x%Mod;
		y>>=1;x=1ll*x*x%Mod;
	}return ans1;
}
inline int C(int n,int m){return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
int main(){
	scanf("%d%d",&n,&K);
	if (K==1) return puts("1"),0;dp[0][0]=1;
	fac[0]=1;for (int i=1;i<M;i++) fac[i]=1ll*fac[i-1]*i%Mod;
	inv[M-1]=ksm(fac[M-1],Mod-2);
	for (int i=M-2;~i;i--) inv[i]=1ll*inv[i+1]*(i+1)%Mod;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i;j++){
			if (i) dp[i][j]=1ll*(dp[i][j]+dp[i-1][j])%Mod;
			if (j) dp[i][j]=1ll*(1ll*dp[i][j-1]*C(n*K-i-(j-1)*(K-1)-1,K-2)%Mod+dp[i][j])%Mod;
		}
	}
	printf("%lld\n",1ll*dp[n][n]*fac[n]%Mod);//颜色序列有n!种排列 
	return 0;
}