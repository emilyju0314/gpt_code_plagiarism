#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(nullptr));
const long long INF = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<set<long long>> g(n);
  vector<long long> pr(n);
  pr[0] = -1;
  for (long long i = 0; i < n - 1; i++) {
    long long b, e;
    cin >> b >> e;
    b--;
    e--;
    g[b].insert(e);
    g[e].insert(b);
  }
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  if (a[0] != 0) {
    cout << "NO";
    return 0;
  }
  queue<long long> q;
  vector<bool> used(n);
  used[0] = true;
  q.push(0);
  for (long long i = 1; i < n; i++) {
    long long u = a[i];
    long long v = q.front();
    while (q.size() > 0 && g[v].find(u) == g[v].end()) {
      if (g[v].size() > 1 || (g[v].size() > 0 && *g[v].begin() != pr[v]) ||
          (q.size() == 1)) {
        cout << "NO";
        return 0;
      }
      q.pop();
      v = q.front();
    }
    if (q.size() == 0) {
      cout << "NO";
      return 0;
    }
    g[v].erase(u);
    pr[u] = v;
    q.push(u);
    if (g[v].size() == 0) q.pop();
  }
  cout << "YES";
  return 0;
}
