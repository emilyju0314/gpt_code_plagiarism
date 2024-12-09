#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
const int N = 100005;
vector<int> v[N];
int level[N];
int dp[N];
int mx = 0;
void dfs(int s, int p) {
  amax(mx, level[s]);
  for (int j : v[s]) {
    if (j != p) {
      level[j] = level[s] + 1;
      dfs(j, s);
    }
  }
}
int _runtimeTerror_() {
  int n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;
  mx = 0;
  for (int i = 1; i <= n; ++i) v[i].clear();
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
  }
  level[a] = 0;
  dfs(a, 0);
  if (2 * da >= db || (level[b] <= da)) {
    cout << "Alice\n";
    return 0;
  }
  int l = 0;
  int u = -1;
  for (int i = 1; i <= n; ++i) {
    if (level[i] > l) l = level[i], u = i;
  }
  level[u] = 0;
  dfs(u, 0);
  if (mx >= 2 * da + 1)
    cout << "Bob\n";
  else
    cout << "Alice\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
