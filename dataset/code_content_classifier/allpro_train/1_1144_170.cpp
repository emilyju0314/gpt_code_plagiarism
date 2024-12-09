#include <bits/stdc++.h>
using namespace std;
const long long INF = 922337203685477110;
const long long N = 1000005;
const long long mod = 1e9 + 7;
const long long M = 22;
vector<long long> g[N], gr[N];
vector<long long> gn[N];
long long comp[N];
long long vis[N];
vector<long long> v;
void dfs(long long s) {
  vis[s] = 1;
  for (auto ch : g[s]) {
    if (!vis[ch]) dfs(ch);
  }
  v.push_back(s);
}
void dfs2(long long s, long long c) {
  vis[s] = 1;
  comp[s] = c;
  for (auto ch : gr[s]) {
    if (!vis[ch]) dfs2(ch, c);
  }
}
long long scc(long long n) {
  for (long long i = 0; i <= n; i++) vis[i] = 0;
  long long c = 1;
  for (long long i = v.size() - 1; i >= 0; i--) {
    if (!vis[v[i]]) {
      dfs2(v[i], c);
      c++;
    }
  }
  if (c < 3) return 0;
  for (long long i = 1; i <= n; i++) {
    for (auto ch : g[i]) {
      if (comp[ch] != comp[i]) {
        gn[comp[i]].push_back(comp[ch]);
      }
    }
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i <= n; i++) {
      gn[i].clear();
      gr[i].clear();
      g[i].clear();
      vis[i] = 0;
      comp[i] = 0;
    }
    v.clear();
    for (long long i = 0; i < m; i++) {
      long long a, b;
      cin >> a >> b;
      if (a != b) {
        g[a].push_back(b);
        gr[b].push_back(a);
      }
    }
    if (n == 1) {
      cout << "No"
           << "\n";
      continue;
    }
    long long ok = 0;
    long long jury = 0;
    for (long long i = 1; i <= n; i++) {
      if (g[i].size() == 0) {
        jury = i;
        ok = 1;
        break;
      }
    }
    if (ok) {
      cout << "Yes"
           << "\n";
      cout << "1"
           << " " << n - 1 << "\n";
      cout << jury << "\n";
      for (long long i = 1; i <= n; i++) {
        if (i != jury) cout << i << " ";
      }
      cout << "\n";
      continue;
    }
    for (long long i = 1; i <= n; i++) {
      if (!vis[i]) dfs(i);
    }
    long long k = scc(n);
    if (k) {
      cout << "Yes"
           << "\n";
      long long ans = 0;
      for (long long i = 1; i < k; i++) {
        if (gn[i].size() == 0) {
          ans = i;
          break;
        }
      }
      vector<long long> vj, vc;
      for (long long i = 1; i <= n; i++) {
        if (comp[i] == ans)
          vj.push_back(i);
        else
          vc.push_back(i);
      }
      cout << vj.size() << " " << vc.size() << "\n";
      for (long long i = 0; i < vj.size(); i++) cout << vj[i] << " ";
      cout << "\n";
      for (long long i = 0; i < vc.size(); i++) cout << vc[i] << " ";
      cout << "\n";
    } else
      cout << "No"
           << "\n";
  }
}
