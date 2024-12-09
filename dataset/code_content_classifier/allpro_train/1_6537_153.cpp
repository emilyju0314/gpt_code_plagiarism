#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;
const long long md = 1e9 + 7;
const long long prime = 1e7 + 19;
long long sum(long long a, long long b) { return (a + b) % md; }
long long mul(long long a, long long b) { return (a * b) % md; }
long long mn(long long a, long long b) { return (a - b + md) % md; }
long long pw(long long a, long long b) {
  long long o = 1;
  for (int i = 0; i < 60; ++i) {
    if (b & (1LL << i)) {
      o = mul(o, a);
    }
    a = mul(a, a);
  }
  return o;
}
long long n, k, dp[maxn][1005], t[1005], v[maxn], w[maxn], num, st[maxn],
    ft[maxn], q, cnt, re;
vector<int> bt[4 * maxn];
bool isq[maxn];
void up(int u, int l, int r, int f, int s, int x) {
  if (f >= r || l >= s) return;
  if (f <= l && r <= s) {
    bt[u].push_back(x);
    return;
  }
  int md = (l + r) >> 1;
  up(2 * u, l, md, f, s, x);
  up(2 * u + 1, md, r, f, s, x);
}
void ad(int u) {
  for (auto x : bt[u]) {
    dp[cnt][0] = 0;
    for (int i = 1; i < k + 1; ++i) {
      dp[cnt][i] = 0;
      if (i >= w[x]) {
        dp[cnt][i] = dp[cnt - 1][i - w[x]] + v[x];
      }
      dp[cnt][i] = max(dp[cnt][i], dp[cnt - 1][i]);
    }
    cnt++;
  }
}
void del(int u) { cnt -= bt[u].size(); }
void solve(int u, int l, int r) {
  ad(u);
  if (r - l == 1) {
    if (isq[l]) {
      re = 0;
      for (int i = 1; i < k + 1; ++i) {
        re = sum(re, mul(dp[cnt - 1][i], t[i]));
      }
      cout << re << endl;
    }
    del(u);
    return;
  }
  int md = (l + r) >> 1;
  solve(2 * u, l, md);
  solve(2 * u + 1, md, r);
  del(u);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i < k + 1; ++i) {
    t[i] = pw(prime, i - 1);
  }
  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> w[i];
    st[i] = 0;
    ft[i] = maxn;
  }
  num = n;
  cin >> q;
  for (int i = 1; i < q + 1; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> v[num] >> w[num];
      st[num] = i;
      ft[num] = maxn;
      num++;
    } else if (type == 2) {
      int ind;
      cin >> ind;
      ind--;
      ft[ind] = i;
    } else {
      isq[i] = true;
    }
  }
  for (int i = 0; i < num; ++i) {
    up(1, 0, maxn, st[i], ft[i], i);
  }
  cnt = 1;
  dp[0][0] = 0;
  solve(1, 0, maxn);
  return 0;
}
