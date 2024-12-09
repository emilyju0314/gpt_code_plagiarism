#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int M=1e6+5,mod=998244353;
int num[M],sum[M],n,inv[M],ma,ans;

signed main(){
	read(n);
	for(int i=1,x;i<=n;i++) ma=max(ma,read(x)),num[x]=(num[x]+x)%mod;
	inv[1]=1;for(int i=2;i<=ma;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod; 
	for(int i=ma;i;i--){
		int cur=0;
		for(int j=i;j<=ma;j+=i) cur=(cur+num[j])%mod;
		sum[i]=1ll*cur*cur%mod;
		for(int j=i+i;j<=ma;j+=i) sum[i]=(sum[i]-sum[j]+mod)%mod;
		ans=((1ll*ans+1ll*sum[i]*inv[i]%mod-num[i]+mod)%mod);
	}
	write(1ll*ans*inv[2]%mod);
}