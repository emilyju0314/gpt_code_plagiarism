#include <bits/stdc++.h>
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
char a[1005], b[1005][1005];
int dp[1005][1005], l[1005];
int d[10];
const int K = 1001;
int main() {
  scanf("%s", a);
  int len = strlen(a), first = K - len;
  reverse(a, a + len);
  for (int i = 0; i < K; ++i)
    if (!a[i]) a[i] = '0';
  reverse(a, a + K);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
    l[i] = len = strlen(b[i]);
    reverse(b[i], b[i] + len);
    for (int j = 0; j < K; ++j)
      if (!b[i][j]) b[i][j] = '0';
  }
  for (int i = 0; i < n; ++i) reverse(b[i], b[i] + K);
  for (int i = 0; i <= 9; ++i) scanf("%d", d + i);
  vector<int> id(n);
  for (int i = 0; i < n; ++i) id[i] = i;
  memset(dp, -0x3f, sizeof(dp));
  dp[K][0] = 0;
  for (int i = K - 1; i >= 0; --i) {
    if (a[i] == '?') {
      for (char p = '0'; p <= '9'; ++p) {
        if (p == '0' && i == first) continue;
        a[i] = p;
        int cur = 0, carry = 0;
        vector<int> v(n);
        for (int j = 0; j < n; ++j) {
          v[j] = b[id[j]][i] - '0' + a[i] - '0';
          if (v[j] >= 10) carry++;
          if (v[j] == 0 && i < min(first, K - l[id[j]])) continue;
          cur += d[v[j] % 10];
        }
        for (int j = 0; j <= n; ++j) {
          dp[i][carry] = max(dp[i][carry], dp[i + 1][j] + cur);
          if (j == n) break;
          if (v[j] == 0 && i < min(first, K - l[id[j]]))
            ;
          else
            cur -= d[v[j] % 10];
          v[j]++;
          cur += d[v[j] % 10];
          if (v[j] == 10) carry++;
        }
      }
    } else {
      int cur = 0, carry = 0;
      vector<int> v(n);
      for (int j = 0; j < n; ++j) {
        v[j] = b[id[j]][i] - '0' + a[i] - '0';
        if (v[j] >= 10) carry++;
        if (v[j] == 0 && i < min(first, K - l[id[j]])) continue;
        cur += d[v[j] % 10];
      }
      for (int j = 0; j <= n; ++j) {
        dp[i][carry] = max(dp[i][carry], dp[i + 1][j] + cur);
        if (j == n) break;
        if (v[j] == 0 && i < min(first, K - l[id[j]]))
          ;
        else
          cur -= d[v[j] % 10];
        v[j]++;
        cur += d[v[j] % 10];
        if (v[j] == 10) carry++;
      }
    }
    vector<int> cnt(10);
    for (int j = 0; j < n; ++j) cnt[b[id[j]][i] - '0']++;
    for (int i = 8; i >= 0; --i) cnt[i] += cnt[i + 1];
    vector<int> nxt(n);
    for (int j = n - 1; j >= 0; --j) nxt[--cnt[b[id[j]][i] - '0']] = id[j];
    id = nxt;
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) ans = max(ans, dp[0][i]);
  cout << ans << '\n';
}
