#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;
const int maxn = 2000 + 10;
char mp[maxn][maxn];
int h, w, ans = 0, tp[maxn][maxn], lf[maxn][maxn], bt[maxn][maxn], rt[maxn][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '.')
				tp[i][j] = tp[i - 1][j] + 1, lf[i][j] = lf[i][j - 1] + 1;
			else
				tp[i][j] = lf[i][j] = 0;
		}
	for (int i = h; i > 0; i--)
		for (int j = w; j > 0; j--) {
			if (mp[i][j] == '.')
				bt[i][j] = bt[i + 1][j] + 1, rt[i][j] = rt[i][j + 1] + 1, ans = max(ans, tp[i - 1][j] + lf[i][j - 1] + bt[i + 1][j] + rt[i][j + 1] + 1);
			else
				bt[i][j] = rt[i][j] = 0;
		}
	cout << ans << '\n';
	return 0;
}
