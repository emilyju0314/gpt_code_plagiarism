#include <bits/stdc++.h>

#define debug(x)	cerr << #x << ' ' << x << endl

using namespace std;

const int N = 1000005;
const int mod = 1e9 + 7;
const int oo = 1e9;

vector <int> sub[N];
int dp[N], n, q, a[N], S[N];
int t[N * 4];
long long bal[N];

void update(int b, int e, int node, int pos, int val){
	if(b == e){	
		t[node] = max(t[node], val);
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	if(pos <= mid) update(b, mid, l, pos, val);
	else update(mid + 1, e, h, pos, val);
	t[node] = max(t[l], t[h]);
}

int query(int b, int e, int node, int x, int y){
	if(y < b || e < x) return -oo;
	if(b >= x && e <= y) return t[node];
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	return max(query(b, mid, l, x, y), query(mid + 1, e, h, x, y));
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		S[i] = S[i-1] + a[i];
	}
	fill(t, t + N * 4, -oo);
	scanf("%d", &q);
	int x, y;
	for(int i = 1; i <= q; ++i){
		scanf("%d %d", &x, &y);
		sub[x].push_back(y);
	}
	for(int i = 1; i <= n; ++i){
		update(1, n, 1, i, dp[i - 1] - S[i - 1]);
		for(auto kt : sub[i]){
			dp[kt] = max(dp[kt], S[kt] + max(query(1, n, 1, i, kt), dp[i - 1] - S[i - 1]));
			update(1, n, 1, kt, dp[kt] - S[kt]);
		}
		dp[i] = max(dp[i], dp[i - 1] + (a[i] ^ 1));
	}
	cout << n - dp[n] << endl;
	return 0;
}
