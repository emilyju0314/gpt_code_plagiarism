#include<bits/stdc++.h>
using namespace std;
const int MAXN = 305;
const int P = 998244353;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
char s[MAXN]; int n;
int dp[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
bool res[MAXN][MAXN][MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
bool check(int x, int y, int z) {
	return res[x][y][z];
}
int main() {
	scanf("%s", s + 1), n = strlen(s + 1), dp[n][0][0] = 1;
	for (int i = n; i >= 1; i--)
	for (int j = 0; j + (n - i) <= n - 1; j++)
	for (int k = 0; j + k + (n - i) <= n - 1; k++)
		if (s[i] == '0') {
			update(dp[i - 1][j][k], dp[i][j][k]);
			update(dp[i][j][k + 1], dp[i][j][k]);
		} else {
			update(dp[i - 1][j][k], dp[i][j][k]);
			update(dp[i][j + 1][k], dp[i][j][k]);
		}
	memset(vis, -1, sizeof(vis));
	vis[0][0][0] = 0;
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= i / 2; j++)
	for (int k = 0; j + k <= i / 2; k++) {
		if (vis[i][j][k] == -1) continue;
		int tmp = vis[i][j][k];
		if (i + 1 <= n && tmp != 0) {
			if (s[i + 1] == '0') chkmax(vis[i + 1][j + 1][k], tmp - 1);
			if (s[i + 1] == '1') chkmax(vis[i + 1][j][k + 1], tmp - 1);
		}
		if (i + 2 <= n) {
			if (s[i + 1] == '0' || s[i + 2] == '0') chkmax(vis[i + 2][j + 1][k], tmp);
			if (s[i + 1] == '1' || s[i + 2] == '1') chkmax(vis[i + 2][j][k + 1], tmp);
			chkmax(vis[i + 2][j][k], tmp + 1);
		}
	}
	for (int i = 0; i <= n; i++)
	for (int j = n; j >= 0; j--)
	for (int k = n; k >= 0; k--) {
		res[i][j][k] = vis[i][j][k] != -1;
		if (i != 0) res[i][j][k] |= res[i - 1][j][k];
		res[i][j][k] |= res[i][j + 1][k];
		res[i][j][k] |= res[i][j][k + 1];
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	for (int j = 0; j + (n - i) <= n; j++)
	for (int k = 0; j + k + (n - i) <= n; k++)
		if (dp[i][j][k] && (n - i) + j + k != 0) {
			if (check(i, j, k)) {
				update(ans, dp[i][j][k]);
			}
		}
	cout << ans << endl;
	return 0;
}
