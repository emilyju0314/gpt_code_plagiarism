#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
const int MOD = 998244353;
const int oo = 1e9;
int n, m, bl[N], dp[N], sum[N], phi[N], mark[N];
vector<int> g[N], ct[N], fn;
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int calc(int u) {
  int &ret = dp[u];
  if (ret != -1) return ret;
  ret = sum[u];
  for (auto v : g[u]) ret = max(sum[u] + calc(v), ret);
  return ret;
}
void build(int u) {
  while (ct[u].size()) fn.push_back(ct[u].back()), ct[u].pop_back();
  for (auto v : g[u])
    if (sum[u] + calc(v) == calc(u)) {
      build(v);
      break;
    }
}
long long fast(long long a, long long b) {
  if (!b) return 1ll;
  long long res = fast(a, b / 2);
  res = (res * res) % m;
  if (b & 1) return (res * a) % m;
  return res;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  for (int a, i = 0; i < n; ++i) {
    scanf("%d", &a);
    bl[a] = 1;
  }
  for (int i = 1; i <= 200000; ++i) phi[i] = i;
  for (int i = 2; i <= 200000; ++i) {
    if (mark[i]) continue;
    for (int j = i; j <= 200000; j += i) {
      mark[j] = 1;
      phi[j] -= phi[j] / i;
    }
  }
  for (int i = 0; i < m; ++i)
    if (!bl[i]) sum[gcd(i, m) % m]++, ct[gcd(i, m) % m].push_back(i);
  for (int i = 1; i < m; ++i) {
    g[i].push_back(0);
    for (int j = i + i; j < m; j += i) {
      g[i].push_back(j);
    }
  }
  pair<int, int> ans = make_pair(0, 0);
  for (int i = 0; i < m; ++i) ans = max(ans, make_pair(calc(i), i));
  printf("%d\n", ans.first);
  if (ans.first) build(ans.second);
  long long cur = 1;
  for (int i = 0; i < fn.size(); ++i) {
    if (i) printf(" ");
    int gc = gcd(m, fn[i - 1]);
    long long ans =
        !i ? 1ll * fn[i]
           : (1ll * (fn[i] / gc) * fast(fn[i - 1] / gc, phi[m / gc] - 1)) %
                 (m / gc);
    printf("%lld", ans);
  }
  puts("");
  return 0;
}
