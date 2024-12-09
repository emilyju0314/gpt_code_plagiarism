#include <bits/stdc++.h>
using namespace std;
template <class s, class n>
ostream &operator<<(ostream &os, pair<n, s> x) {
  return os << "<" << x.first << ", " << x.second << ">";
}
template <class second, class n>
void mini(second &x, n y) {
  if (x > y) x = y;
}
template <class second, class n>
void maxi(second &x, n y) {
  if (x < y) x = y;
}
template <class second>
auto operator<<(ostream &os, second x) ->
    typename enable_if<!is_same<second, string>::value,
                       decltype(x.end(), os)>::type {
  int o = 0;
  os << "{";
  for (auto c : x) {
    if (o++) os << ", ";
    os << c;
  }
  return os << "}";
}
void dor() { cerr << endl; }
template <class second, class... n>
void dor(second x, n... y) {
  cerr << boolalpha << x;
  dor(y...);
}
const int MXN = 1e5 + 5;
vector<int> V[MXN];
int par[MXN];
vector<int> order;
int n;
void dfs(int x, int pp) {
  par[x] = pp;
  for (auto i : V[x])
    if (i != pp) dfs(i, x);
  order.push_back(x);
}
int dp[MXN];
int ans[MXN];
int calc(int sr) {
  if (ans[sr] != -1) return ans[sr];
  for (int i = (1); i <= (int)(n); ++i) dp[i] = 0;
  int res = 0;
  for (auto i : order) {
    int mx1 = 0, mx2 = 0;
    for (auto j : V[i]) {
      if (j == par[i]) continue;
      if (dp[j] > mx1) {
        mx2 = mx1;
        mx1 = dp[j];
      } else if (dp[j] > mx2) {
        mx2 = dp[j];
      }
    }
    if (mx1 + mx2 + 1 >= sr)
      res++;
    else
      dp[i] = mx1 + 1;
  }
  return ans[sr] = res;
}
void go(int a, int b) {
  calc(a);
  calc(b);
  if (ans[a] == ans[b]) {
    for (int i = (a + 1); i <= (int)(b - 1); ++i) ans[i] = ans[a];
    return;
  }
  int sr = (a + b) / 2;
  go(a, sr);
  go(sr + 1, b);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (int)(n); ++i) ans[i] = -1;
  for (int i = 0; i < (int)(n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].push_back(b);
    V[b].push_back(a);
  }
  dfs(1, 0);
  go(1, n);
  for (int i = (1); i <= (int)(n); ++i) printf("%d\n", ans[i]);
}
