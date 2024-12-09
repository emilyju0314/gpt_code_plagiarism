#include <bits/stdc++.h>
#define MAX_N 200000
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-48);
}
int n, l, a[MAX_N+5], b[MAX_N+5];
lnt mx, sl[MAX_N+5], sr[MAX_N+5];
int main() {
	read(l), read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) b[i] = l-a[n-i+1];
	for (int i = 1; i <= n; i++) sl[i] = sl[i-1]+a[i];
	for (int i = 1; i <= n; i++) sr[i] = sr[i-1]+b[i];
	for (int i = 0, c = n>>1; i < n; c = (n-++i)>>1)
		if ((c<<1) == n-i)
			mx = max(mx, ((sl[i+c]-sl[i])<<1)+(sr[c]<<1)+(a[i]<<1)-a[i+c]), 
			mx = max(mx, ((sr[i+c]-sr[i])<<1)+(sl[c]<<1)+(b[i]<<1)-b[i+c]);
		else
			mx = max(mx, ((sl[i+c]-sl[i])<<1)+(sr[c]<<1)+(a[i]<<1)+b[c+1]), 
			mx = max(mx, ((sr[i+c]-sr[i])<<1)+(sl[c]<<1)+(b[i]<<1)+a[c+1]);
	return printf("%lld\n", mx), 0;
}
