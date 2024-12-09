#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("O3")
using namespace std;
const long double eps = 1e-6;
const int N = (1 << 22);
const int inf = 1e9 + 7;
long long n, k;
vector<int> a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, d;
    cin >> n >> d;
    long long mn = 0;
    long long n1 = n;
    long long st = 0;
    while (n1) {
      mn += st * (min(n1, (1ll << st)));
      n1 = max(0ll, n1 - (1 << st));
      st++;
    }
    if (n * (n - 1) / 2 < d || d < mn) {
      cout << "NO\n";
      continue;
    }
    vector<int> a(n, 1);
    long long c = (n - 1) * n / 2;
    set<int> g[n];
    vector<int> go(n);
    vector<int> deep(n, 0);
    for (int i = 0; i + 1 < n; i++) {
      g[i].insert(i + 1);
      go[i + 1] = i;
      deep[i + 1] = i + 1;
    }
    go[0] = -1;
    queue<int> q;
    q.push(n - 1);
    bool f = 1;
    while (c > d && !q.empty()) {
      long long v = q.front();
      q.pop();
      if (g[v].size() > 0) continue;
      for (int i = 0; i < n; i++)
        if (deep[i] == deep[v] - 2 && g[i].size() < 2) {
          c--;
          deep[v]--;
          g[go[v]].erase(v);
          if (g[go[v]].size() == 0) q.push(go[v]);
          g[i].insert(v);
          go[v] = i;
          q.push(v);
          f = 1;
          break;
        }
      if (q.empty()) {
        if (f == 0) break;
        f = 0;
        for (int i = 0; i < n; i++) {
          if (g[i].size() == 0) q.push(i);
        }
      }
    }
    if (c != d) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i < n; i++) cout << go[i] + 1 << " ";
    cout << "\n";
  }
  return 0;
}
