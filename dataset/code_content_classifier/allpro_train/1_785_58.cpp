#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[102][100005];
vector<pair<int, int> > graph[100005];
int grp[100005], sz[100005];
int find_grp(int idx) {
  if (grp[idx] == idx) return idx;
  return grp[idx] = find_grp(grp[idx]);
}
int vt[100005];
long long mod = 1e9 + 7;
long long pow(int a, int b) {
  long long ret = 1;
  for (int i = 0; i < b; i++) {
    ret = (ret * a) % mod;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    graph[t1].push_back(pair<int, int>(t2, t3));
    graph[t2].push_back(pair<int, int>(t1, t3));
  }
  for (int i = 1; i <= n; i++) grp[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> nxt : graph[i]) {
      if (nxt.second == 0) {
        int b = nxt.first;
        int a = i;
        a = find_grp(a);
        b = find_grp(b);
        if (a != b) {
          grp[a] = b;
          sz[b] += sz[a];
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int a = find_grp(i);
    if (vt[a] == 1) continue;
    vt[a] = 1;
    int s = sz[a];
    ans = (ans - pow(s, k) + mod) % mod;
  }
  ans = (ans + pow(n, k)) % mod;
  cout << ans;
  return 0;
}
