#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int fac[500005],ifac[500005];
inline int power(int a,int b){
	int c=1;
	while(b){
		if(b&1)c=1ll*c*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return c;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=k;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[k]=power(fac[k],mod-2);
	for(int i=k;i>0;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	int ans=0;
	for(int i=n;i<=k;i++)ans=(ans+1ll*fac[k-1]*ifac[i-1]%mod*ifac[k-i])%mod;
	printf("%d\n",ans);
	return 0;
}