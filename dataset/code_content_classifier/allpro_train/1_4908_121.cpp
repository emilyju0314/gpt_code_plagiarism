#include <bits/stdc++.h>
#define maxn 2000010
#define ll long long

const int g = 2;
const ll mod = 75161927681ll;
const ll p = 200003;
ll ans,w1[maxn],w2[maxn],w3[maxn];
int a[maxn],n,vis[maxn],rev[maxn];

ll qpow(ll a,ll b){
	if (b==0)return 1;
	ll d=qpow(a,b>>1);d=d*d%p;
	if (b&1)d=d*a%p;
	return d;
}

ll qpow1(ll a,ll b){
	if (b==0)return 1;
	__int128 d=qpow1(a,b>>1);d=d*d%mod;
	if (b&1)d=d*a%mod;
	return d;
}

void NTT( ll *a, int lim, int flag ) {
	for (int i = 1; i < lim; ++ i) rev[i] = (rev[i>>1]>>1) | (i&1) * (lim>>1);
	for (int i = 0; i < lim; ++ i) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		ll wn = qpow1(3,(mod-1)/(i<<1));
		if (flag == -1) wn = qpow1(wn, mod - 2);
		for (int j = 0; j < lim; j += (i<<1)) {
			ll w =1;
			for (int k = 0; k < i; w=(__int128)w*wn%mod,++k) {
				ll a1 = a[j+k];
				ll a2 = (__int128) w * a[j+k+i] % mod;
				a[j+k] = (a1 + a2) % mod; a[j+k+i] = (a1 - a2 + mod) % mod;
			}
		}
	} if (flag == -1) {
		ll inv=qpow1(lim,mod-2);
		for (int i = 0; i < lim; ++i) a[i] = (__int128) a[i] * inv % mod;
	}
}


int main() {
	scanf("%d",&n);
//	printf(">%lld\n",mod);
	for(int i=1,f=g;i<p;++i){vis[f] = i;f=(ll)f*g%p;}
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (!a[i]) continue;
		int d = vis[a[i]];
	//	printf("%d %d\n",d,qpow(g,d));
		w1[d]++; w2[d]++;
	} 
	
	int lim = 1;
	while (lim<=p+p+1) lim<<=1;
//	printf(">%d\n",lim);
	NTT(w1,lim,1); 
	for (int i = 0; i < lim; ++ i) w3[i] = (__int128) w1[i] * w1[i] % mod;
	NTT(w3,lim,-1); 
	for (int i=1;i<p;++i) w3[i+i] -= w2[i];
	for(int i=1;i<2*p;++i)  {
		ans += qpow(g,i) * w3[i] / 2;
	//	if (w3[i]) printf("%d %lld\n",i,w3[i]);
	}
	printf("%lld",ans);
	return 0;
}
	

