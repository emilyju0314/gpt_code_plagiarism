#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 5e5 + 5;
const long long INF = 1e14;
vector<long long> adj[N];
vector<long long> col[N];
long long c[N];
long long idx[N];
long long n, m;
long long sz[N];
long long th[N];
void dfs(long long u, long long p) {
  long long r = 1;
  long long j = 0;
  for (long long i = 0; i < sz[u]; i++) {
    long long v = col[u][i];
    if (c[v] != -1) {
      th[j++] = c[v];
      continue;
    }
  }
  sort(th, th + j);
  long long k = 0;
  for (long long i = 0; i < sz[u]; i++) {
    long long v = col[u][i];
    if (c[v] == -1) {
      while (k < j && r == th[k]) {
        r++;
        k++;
      }
      c[v] = r;
      r++;
    }
  }
  for (long long i = 0; i < adj[u].size(); i++) {
    long long v = adj[u][i];
    if (v == p) continue;
    dfs(v, u);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  long long s;
  long long r;
  long long mm = 0;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    if (mm < s) {
      r = i;
      mm = s;
    }
    sz[i] = s;
    long long a;
    while (s--) {
      cin >> a;
      a--;
      col[i].push_back(a);
    }
    idx[i] = i;
  }
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (mm == 0) {
    cout << 1 << "\n";
    for (long long i = 0; i < m; i++) cout << "1 ";
    cout << "\n";
    return 0;
  }
  cout << sz[r] << "\n";
  for (long long i = 0; i < m; i++) c[i] = -1;
  for (long long i = 0; i < sz[r]; i++) {
    c[col[r][i]] = i + 1;
  }
  for (long long i = 0; i < adj[r].size(); i++) {
    dfs(adj[r][i], r);
  }
  for (long long i = 0; i < m; i++) {
    if (c[i] == -1) c[i] = 1;
    cout << c[i] << " ";
  }
  cout << "\n";
  return 0;
}
