#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int N = 190;

template <typename T> inline void read(T &AKNOI) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    AKNOI = flag * x;
}

template <typename T> inline void cmax(T &x, T y) {
	if (x < y) x = y;
}

char s[N];
int n, m, g[N][N];
int dp[2][N][N][N];

void init() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; ++j) {
			g[i][j] = ((s[j] == '#')? 1 : 0);
			g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
		}
	}
}

void solve() {
	for (int l = 1; l <= m; ++l) {
		for (int r = l; r <= m; ++r) {
			for (int i = 1; i <= n; ++i) {
				int x = max(i - 1, dp[0][i - 1][l][r]);
				while (x < n) {
					int cnt = g[x + 1][r] - g[i - 1][r] - g[x + 1][l - 1] + g[i - 1][l - 1];
					if (cnt == 0 || cnt == (x - i + 2) * (r - l + 1)) ++x;
					else break;
				}
				dp[0][i][l][r] = x;
			}
		}
	}
	int k = 1, pre = 0, cur = 1;
	for (; dp[pre][1][1][m] < n; ++k) {
		mset(dp[cur], 0);
		for (int i = 1; i <= n; ++i) {
			for (int len = 1; len <= m; ++len) {
				for (int l = 1, r = len; r <= m; ++l, ++r) {
					if (dp[pre][i][l][r] == n) {
						dp[cur][i][l][r] = n;
						continue;
					}
					dp[cur][i][l][r] = dp[pre][ dp[pre][i][l][r] + 1 ][l][r];
					int L = l, R = r - 1, P = 0;
					while (L <= R) {
						int mid = (L + R) >> 1;
						int lv = dp[pre][i][l][mid], rv = dp[pre][i][mid + 1][r];
						cmax(P, min(lv, rv));
						if (lv < rv) {
							R = mid - 1;
						} else {
							L = mid + 1;
						}
					}
					cmax(dp[cur][i][l][r], P);
				}
			}
		}
		swap(pre, cur);
	}
	printf("%d\n", k - 1);
}

int main() {
	init();
	solve();
	return 0;
}