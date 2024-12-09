#include<cstdio>
#include<algorithm>
using namespace std;
const int N=405;
const int mod=998244353;
int n,inv[N],f[N][N],g[N],sa,sb,ans;
void Inc(int &x,int y){
	x+=y;x>=mod?x-=mod:x;
}
int main(){
	scanf("%d",&n);
	f[0][0]=mod-1;g[0]=inv[1]=1;
	for(int i=2;i<N;++i)
		inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1,a,b;i<=n;++i){
		scanf("%d%d",&a,&b);
		for(int j=1;j<b;++j)
			g[j]=1ll*g[j-1]*a%mod*inv[j]%mod;
		for(int j=sa;~j;--j)
			for(int k=0;k<=sb;++k)
				for(int l=0;l<b;++l)
					Inc(f[j+a][k+l],mod-1ll*f[j][k]*g[l]%mod);
		sa+=a;sb+=b-1;
	}
	for(int i=1;i<=sa;++i)
		for(int j=0,k=inv[i];j<=sb;++j,k=1ll*k*inv[i]%mod*j%mod)
			Inc(ans,1ll*f[i][j]*k%mod);
	ans=1ll*ans*sa%mod;
	printf("%d\n",ans);
	return 0;
}
