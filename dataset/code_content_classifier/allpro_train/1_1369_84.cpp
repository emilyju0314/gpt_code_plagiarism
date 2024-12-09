#include<bits/stdc++.h>
#define Set(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
template <typename T> inline void init(T&x){
	x=0;char ch=getchar();bool t=0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') t=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch-48);
	if(t) x=-x;return;
}
typedef long long ll;
template<typename T>inline void Inc(T&x,int y){x+=y;if(x>=mod) x-=mod;return;}
template<typename T>inline void Dec(T&x,int y){x-=y;if(x <  0) x+=mod;return;}
template<typename T>inline int fpow(int x,T k){int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
inline int Sum(int x,int y){x+=y;if(x>=mod) return x-mod;return x;}
inline int Dif(int x,int y){x-=y;if(x < 0 ) return x+mod;return x;}
int n,H,D;
int fac[N],ifac[N],f[N];

int main()
{
	init(n),init(H),init(D);fac[0]=ifac[0]=1;
	int sum=0;
	for(int i=1;i<=n;++i) fac[i]=(ll)fac[i-1]*i%mod,Inc(sum,fac[i]);
	ifac[n]=fpow(fac[n],mod-2);
	for(int i=n-1;i;--i) ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
	f[0]=fac[n];int S=fac[n];
	int L=0;
	for(int i=1;i<=H;++i) {
		if(i-L>D) Dec(S,f[L++]);
		if(i==H) cout<<S<<endl;
		f[i]=(ll)S*sum%mod;
		Inc(S,f[i]);
	}
	return 0;
}
