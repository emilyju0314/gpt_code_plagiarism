#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

int n, V;
int x[maxn], v[maxn];
int dp_pre[1<<19], dp_suf[1<<19], ok[maxn];
int rig[maxn][20];

void cal_dp(int *dp) {
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 20; j++) {
			if (j && !v[j-1]) {
				rig[i][j] = i-1;
				continue;
			}
			rig[i][j] = i;
			if (i + 1 <= n && x[i + 1] - x[i] <= v[j]) {
				rig[i][j] = rig[i+1][j];
			}
		}
	}
	for (int j = 0; j < 20; j++) rig[n + 1][j] = n;
	for (int i = 1; i < (1 << 18); i++) {
		for (int j = 0; j < 18; j++) {
			if (i & (1 << j)) {
				dp[i] = max(dp[i], rig[dp[i ^ (1 << j)] + 1][j]);
			}
		}	
	}
}

int main() {
	scanf("%d%d", &n, &V);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	v[0] = V / 2;
	for (int i = 1; i <= 20; i++) v[i] = v[i-1] / 2;
	cal_dp(dp_pre);
	reverse(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) x[i] = - x[i];
	cal_dp(dp_suf);
	reverse(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) x[i] = - x[i];
	for (int i = 1; i <= n; i++) {
		int l = i, r = i;
		while (r + 1 <= n && x[r + 1] - x[r] <= V) ++ r;
		int _ok = 0;
		for (int j = 0; j < (1 << 18); j++) {
			if (dp_pre[j] >= l-1 && dp_suf[(~j)&((1<<18)-1)] >= n-r) {
				_ok = 1;
			}
		}
		if (_ok) for (int j = l; j <= r; j++) ok[j] = 1;
		i = r;
	}
	for (int i = 1; i <= n; i++) {
		if (ok[i]) puts("Possible");
		else puts("Impossible");
	}
	return 0;
}