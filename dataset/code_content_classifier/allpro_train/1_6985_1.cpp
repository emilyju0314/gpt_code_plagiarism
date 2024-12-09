#include <bits/stdc++.h>
using namespace std;

const int nax = 5e5+5;
vector<long long> st(2*nax);
int n;

void modify(int p, int v) {
	for(st[p+=n] += v;p>0;p>>=1) st[p>>1] = st[p] + st[p^1];
}

long long sum(int l, int r) {
	l+=n, r+=n;
	long long ans = 0;
	while(l<r) {
		if(l&1) ans += st[l++];
		if(r&1) ans += st[--r];
		l>>=1, r>>=1;
	}
	return ans;
}

int main() {
	int q, a, b, t;
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		st[i] = 0;
		cin >> st[i+n];
	}
	for(int i = n-1;i>0;i--) st[i] = st[2*i]+st[2*i+1];
	while(q--) {
		cin >> t >> a >> b;
		if(!t) {
			modify(a, b);
		}
		else cout << sum(a, b) << endl;
	}
	return 0;
}
