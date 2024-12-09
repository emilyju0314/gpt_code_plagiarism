#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[] = {0, -1, 0, 1, 1, -1, 1, -1};
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long ceil1(long long a, long long b) { return (a + b - 1) / b; }
void read(vector<long long>& arr) {
  for (long long i = 0; i < int(arr.size()); i++) cin >> arr[i];
}
void read_graph(vector<vector<long long>>& g, long long m) {
  while (m--) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
}
vector<long long> dp;
vector<vector<long long>> g;
long long ans;
void dfs(long long r, long long p = -1) {
  vector<long long> temp;
  vector<long long> temp2;
  for (auto y : g[r]) {
    if (y == p)
      temp.push_back(1);
    else {
      dfs(y, r);
      temp.push_back(dp[y]);
      temp2.push_back(dp[y]);
    }
  }
  long long res = int(temp.size());
  sort(temp.begin(), temp.end());
  sort(temp2.begin(), temp2.end());
  for (long long i = 0, j = int(temp.size()) - 1; i < 2 and j >= 0; i++, j--) {
    res += temp[j] - 1;
  }
  ans = max(ans, res + 1);
  res = int(temp2.size());
  for (long long i = 0, j = int(temp2.size()) - 1; i < 1 and j >= 0; i++, j--) {
    res += temp2[j] - 1;
  }
  dp[r] = res + 1;
}
void solve() {
  long long n;
  cin >> n;
  g = vector<vector<long long>>(n);
  read_graph(g, n - 1);
  long long r = 0;
  ans = 0;
  dp = vector<long long>(n);
  dfs(r);
  vector<long long>& temp = dp;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
