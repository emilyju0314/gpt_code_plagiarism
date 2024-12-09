#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846;
const long long MOD = 1e+9 + 7;
const long long INF = LLONG_MAX;
const int INFi = INT_MAX;
const long long N = 1e+3 + 8;
vector<long long> adj[N];
long long vis[N];
long long dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
long long test_cases = 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
;
long long n, u, v, primary_distance, root, ans[N];
vector<long long> lvl[N];
pair<long long, long long> query(vector<long long> nodes, long long level) {
  if (nodes.size() == 0) return {INF, INF};
  long long x, dis;
  cout << "? " << nodes.size() << " ";
  for (auto it : nodes) cout << it << " ";
  cout << endl;
  cin >> ans[level] >> dis;
  if (dis == -1) exit(0);
  return {ans[level], dis};
}
void tell(long long x, long long y) {
  string res;
  cout << "! " << x << " " << y << endl;
  cin >> res;
  if (res == "Incorrect") exit(0);
}
long long P(long long key) {
  pair<long long, long long> p = query(lvl[key], key);
  return p.second > primary_distance;
}
long long bs(long long L, long long R) {
  while (L < R) {
    long long mid = (L + R) / 2;
    if (P(mid))
      R = mid;
    else
      L = mid + 1;
  }
  return L - 1;
}
void dfs(long long v, long long p, long long d) {
  lvl[d].push_back(v);
  for (auto to : adj[v]) {
    if (to != p) dfs(to, v, d + 1);
  }
}
void clear(long long ok) {
  for (long long i = (0); i <= n + 3; i++) {
    if (ok) adj[i].clear();
    lvl[i].clear();
    ans[i] = -1;
  }
}
void solve() {
  vector<long long> v;
  for (long long i = (1); i <= n; i++) v.push_back(i);
  pair<long long, long long> res = query(v, 0);
  root = res.first;
  primary_distance = res.second;
  dfs(root, -1, 0);
  long long x = ans[bs(primary_distance / 2, primary_distance + 1)];
  clear(0);
  dfs(x, -1, 0);
  long long y = query(lvl[primary_distance], primary_distance).first;
  tell(x, y);
}
void MAIN(long long tc) {
  cin >> n;
  for (long long i = (1); i <= n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  solve();
  clear(1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  cin >> test_cases;
  for (long long i = (1); i <= test_cases; i++) {
    MAIN(i);
  }
}
