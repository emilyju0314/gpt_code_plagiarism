#include <cstdio>
#include <algorithm>
#define N 1000010
using namespace std;
typedef long long ll;
int mod=998244353;
int n,m,ans,sum,fac[N],inv[N];
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for (int i=2;i<=n+m;i++)
		fac[i]=(ll)fac[i-1]*i%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for (int i=2;i<=n+m;i++)
		inv[i]=(ll)inv[i]*inv[i-1]%mod;
}
int C(int m,int n)
{
	return ((((ll)fac[n]*inv[m])%mod)*(ll)inv[n-m])%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	if (n<m) swap(n,m);
	ans=n;
	init();
	for (int i=1;i<=m;i++)
        sum=((ll)C(i,i<<1)*C(n-i,n+m-(i<<1))+sum)%mod;
    printf("%d\n", (((((ll)sum*inv[2]%mod)*inv[n+m]%mod)*fac[n]%mod)*fac[m]+ans)%mod);
}