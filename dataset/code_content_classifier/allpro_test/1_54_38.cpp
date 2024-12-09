#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T>
void readArray(vector<T> &A) {
  for (T &i : A) cin >> i;
}
template <typename T>
void printArray(vector<T> A) {
  for (T i : A) cout << i << " ";
  cout << endl;
}
long long fastPow(long long a, long long b, long long m = mod) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
bool isPrime(long long n, int iter = 5) {
  if (n < 4) return n == 2 || n == 3;
  for (int i = 0; i < iter; i++) {
    int a = 2 + rand() % (n - 3);
    if (fastPow(a, n - 1, n) != 1) return false;
  }
  return true;
}
long long inv(long long n, long long m = mod) { return fastPow(n, m - 2); }
long long mul(long long a, long long b, long long m = mod) {
  return (a * b) % m;
}
long long add(long long a, long long b, long long m = mod) {
  return (a + b + m) % m;
}
vector<vector<pair<int, bool>>> adj;
vector<int> role;
bool flg;
pair<int, int> dfs(int u, bool r) {
  if (!flg) return {0, 0};
  role[u] = r;
  pair<int, int> tot = {1, r ? 1 : 0};
  for (auto v : adj[u]) {
    if (role[v.first] == -1) {
      pair<int, int> res = dfs(v.first, r ? v.second : (v.second ^ 1));
      tot.first += res.first;
      tot.second += res.second;
    } else {
      if ((r && v.second != role[v.first]) ||
          (!r && v.second == role[v.first])) {
        flg = false;
        return {0, 0};
      }
    }
  }
  return tot;
}
void solve() {
  int n, m;
  cin >> n >> m;
  adj = vector<vector<pair<int, bool>>>(n);
  role = vector<int>(n, -1);
  flg = true;
  for (int i = 0; i < m; i++) {
    int u, v;
    string second;
    cin >> u >> v >> second;
    u--, v--;
    bool ok = (second[0] == 'c');
    adj[u].push_back({v, ok});
    adj[v].push_back({u, ok});
  }
  int ans = 0;
  for (int u = 0; u < n; u++) {
    if (role[u] == -1) {
      pair<int, int> res = dfs(u, 1);
      ans += max(res.first - res.second, res.second);
    }
    if (!flg) {
      cout << -1;
      return;
    }
  }
  cout << ans;
}
void trials() {
  int t;
  for (cin >> t; t--; cout << endl) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  trials();
}
