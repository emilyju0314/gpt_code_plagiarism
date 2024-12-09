#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 1e5 + 5;
int n, m, cum[2][2][N];
char str[N];
pair<int, int> mem[N];
bool vis[N];
pair<int, int> cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return max(a, b);
  return min(a, b);
}
pair<int, int> solve(int i) {
  if (i + m - 1 >= n) return {0, 0};
  auto& ret = mem[i];
  if (vis[i]) return ret;
  vis[i] = 1;
  ret = solve(i + 1);
  if (cum[i & 1][1][i] - cum[i & 1][1][i + m] == 0 &&
      cum[i & 1 ^ 1][0][i] - cum[i & 1 ^ 1][0][i + m] == 0) {
    auto cur = solve(i + m);
    ++cur.first;
    cur.second += m - (cum[i & 1][0][i] - cum[i & 1][0][i + m]) -
                  (cum[i & 1 ^ 1][1][i] - cum[i & 1 ^ 1][1][i + m]);
    ret = cmp(ret, cur);
  }
  return ret;
}
int main() {
  cin >> n >> str >> m;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 2; ++j) {
      cum[i & 1 ^ 1][j][i] = cum[i & 1 ^ 1][j][i + 1];
      cum[i & 1][j][i] = cum[i & 1][j][i + 1];
    }
    if (str[i] != '?') ++cum[i & 1][str[i] - 'a'][i];
  }
  cout << solve(0).second;
  return 0;
}
