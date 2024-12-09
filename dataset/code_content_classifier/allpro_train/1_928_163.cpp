#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=2e5;
const int mod=998244353;
int n,k;
struct Seq{
	int l,r;
}a[15];
ll f[maxn+5],sf[maxn+5];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d %d",&a[i].l,&a[i].r);
	f[1]=sf[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(a[j].l>=i) continue;
			if(a[j].r>=i) f[i]=((f[i]+sf[i-a[j].l])%mod-sf[0]+mod)%mod;
			else f[i]=((f[i]+sf[i-a[j].l])%mod-sf[i-a[j].r-1]+mod)%mod;
		}
		sf[i]=(sf[i-1]+f[i])%mod;
	}
	printf("%lld\n",f[n]);
	return 0;
}
