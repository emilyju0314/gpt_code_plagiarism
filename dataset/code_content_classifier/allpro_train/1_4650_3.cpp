#include <bits/stdc++.h>
using namespace std;


#define int long long 


const int N = 2e5 + 7, mod = 998244353;


int t[N << 2], lzy[N << 2], pwr[N], hsh[10][N];


void pushDown(int v, int l, int r) {
	if(lzy[v]) {
		t[v] = hsh[lzy[v]][r - l + 1];
		if(l ^ r) {
			lzy[v * 2] = lzy[v];
			lzy[v * 2 + 1] = lzy[v];
		}
		lzy[v] = 0;
	}
}

void modify(int v, int l, int r, int L, int R, int x) {
	pushDown(v, l, r);
	if(l > R || r < L) return;
	if(l >= L && r <= R) {
		lzy[v] = x;
		pushDown(v, l, r);
		return;
	}
	int mid = (l + r) / 2;
	modify(v * 2, l, mid, L, R, x);
	modify(v * 2 + 1, mid + 1, r, L, R, x);
	t[v] = (t[v * 2] * pwr[r - mid] + t[v * 2 + 1]) % mod;
}

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	pwr[0] = 1;
	for(int i = 1; i <= n; i++) {
		pwr[i] = (pwr[i - 1] * 10) % mod;
	}

	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= n; j++) {
			hsh[i][j] = (hsh[i][j - 1] * 10 + i) % mod;
		}
	}

	modify(1, 1, n, 1, n, 1);

	for(int i = 1; i <= q; i++) {
		int l, r, x; cin >> l >> r >> x;
		modify(1, 1, n, l, r, x);
		cout << t[1] << endl;
	}
}