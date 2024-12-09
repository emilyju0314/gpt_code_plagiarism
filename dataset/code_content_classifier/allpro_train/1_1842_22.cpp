#include <bits/stdc++.h>
using namespace std;

#define co(n) cout<<n<<endl;
const double eps=1e-10,pi=3.1415926535898;
const int mod=1e9+7,maxn=1e5+10;
int T,n,m,k,x,y,a[maxn],b[maxn],c[maxn],d[maxn],e[maxn];

int main(int argc, char const *argv[]) {
	int ans=0;
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d", a+i);
	}
	a[0] = a[n+1] = maxn;
	for (int i=1;i<=n;++i) {
		if (a[i] > a[i-1]) b[i] = b[i-1]+1;
		else b[i] = 1;
	}
	for (int i=n;i>=1;--i) {
		if (a[i] > a[i+1]) c[i] = c[i+1]+1;
		else c[i] = 1;
	}
	for (int i=1;i<=n;++i) {
		d[i] = d[i-1];
		d[i] = max(d[i-1], max(b[i], c[i]));
	}
	for (int i=n;i>=1;--i) {
		e[i] = e[i+1];
		e[i] = max(e[i+1], max(b[i], c[i]));
	}
	for (int i=1;i<=n;++i) {
		if (b[i] == 1 or c[i] == 1) continue;
		if (max(b[i], c[i]) <= max(d[i-1], e[i+1])) continue;
		if (b[i]-(b[i]&1)>=c[i] or c[i]-(c[i]&1)>=b[i]) continue;
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
clock_t clk;
clk = clock();
if(clock() - clk > CLOCKS_PER_SEC * 0.9) 
      T
W     L
A C M E R
  E L   E
    E
*/