#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const int MAXS = (1 << 18) + 5;
template <typename T>
inline void read(T &AKNOI) {
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
char ss[N];
int n, g[N][N], bit[MAXS], S;
long long dp[MAXS][N], chain[N][MAXS], prod[N][MAXS], ans[MAXS];
map<long long, long long> mp;
void DFS(int x, int len, int d, long long t) {
  if (len == n) {
    long long sum = 0;
    for (int s = 0; s < S; ++s) {
      sum += prod[d][s] * (((n - bit[s]) & 1) ? -1 : 1);
    }
    mp[t] = sum;
    return;
  }
  if (len + x > n) return;
  DFS(x + 1, len, d, t);
  for (int s = 0; s < S; ++s) {
    prod[d + 1][s] = prod[d][s] * chain[x][s];
  }
  DFS(x, len + x, d + 1, t * 10 + x);
}
void init() {
  read(n);
  S = (1 << n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", ss);
    for (int j = 0; j < n; ++j) {
      g[i][j] = ss[j] - '0';
    }
  }
}
void solve() {
  for (int i = 0; i < n; ++i) {
    dp[1 << i][i] = 1;
  }
  for (int s = 1; s < S; ++s) {
    bit[s] = bit[s >> 1] + (s & 1);
    for (int i = 0; i < n; ++i) {
      long long x = dp[s][i];
      if (!x) continue;
      chain[bit[s]][s] += x;
      for (int j = 0; j < n; ++j) {
        if ((s >> j) & 1) continue;
        if (!g[i][j]) continue;
        dp[s | (1 << j)][j] += x;
      }
    }
  }
  for (int t = 1; t <= n; ++t) {
    for (int i = 1; i < S; i <<= 1) {
      for (int j = 0; j < S; j += (i << 1)) {
        for (int k = 0; k < i; ++k) {
          chain[t][j + k + i] += chain[t][j + k];
        }
      }
    }
  }
  for (int s = 0; s < S; ++s) {
    prod[0][s] = 1;
  }
  DFS(1, 0, 0, 0);
  S >>= 1;
  for (int s = 0; s < S; ++s) {
    static int stk[N], top, len;
    top = len = 0;
    for (int i = 0; i < n; ++i) {
      if ((s >> i) & 1) {
        ++len;
      } else {
        stk[top++] = len + 1;
        len = 0;
      }
    }
    sort(stk, stk + top);
    long long t = 0;
    for (int i = 0; i < top; ++i) {
      t = t * 10 + stk[i];
    }
    ans[s] = mp[t];
  }
  for (int i = 1; i < S; i <<= 1) {
    for (int j = 0; j < S; j += (i << 1)) {
      for (int k = 0; k < i; ++k) {
        ans[j + k] -= ans[j + k + i];
      }
    }
  }
  for (int s = 0; s < S; ++s) {
    printf("%lld ", ans[s]);
  }
}
int main() {
  init();
  solve();
  return 0;
}
