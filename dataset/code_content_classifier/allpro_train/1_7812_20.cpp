#include <bits/stdc++.h>
using namespace std;
int tot;
vector<int> adj[100005];
long long ans = 0;
int siz[100005], out[100005], pos[100005], cop[100005], p[100005], ret[100005];
bool found[100005];
void dfs(int n, int par) {
  siz[n] = 1;
  p[n] = par;
  for (int v : adj[n]) {
    if (v != par) {
      dfs(v, n);
      siz[n] += siz[v];
    }
  }
  ans += min(siz[n], tot - siz[n]) * 2;
}
int centroid(int n, int par) {
  for (int v : adj[n]) {
    if (v != par) {
      if (2 * siz[v] >= tot) return centroid(v, n);
    }
  }
  return n;
}
int cnt = 0;
void getans(int n, int par) {
  found[n] = 1;
  for (int v : adj[n]) {
    if (v != par) {
      getans(v, n);
    }
  }
  cop[cnt] = n;
  pos[cnt++] = n;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  tot = n;
  for (int i = 1; i <= n; i++) pos[i] = i;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  cout << ans << "\n";
  int c = centroid(1, 0);
  if (siz[c] * 2 == n) {
    getans(c, p[c]);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (!found[i]) v.push_back(i);
    }
    int i1 = 0, i2 = 0;
    for (int i = 1; i <= n; i++) {
      if (found[i])
        ret[v[i2++]] = i;
      else
        ret[cop[i1++]] = i;
    }
  } else {
    getans(c, 0);
    for (int i = (n - 1) / 2; i < (n - 1) / 2 + n - 1; i++) {
      out[cop[i - (n - 1) / 2]] = pos[i % (n - 1)];
    }
    int val = out[cop[0]];
    out[cop[0]] = c;
    for (int i = 1; i <= n; i++) {
      if (out[i] == 0) out[i] = val;
      ret[out[i]] = i;
    }
  }
  for (int i = 1; i <= n; i++) cout << ret[i] << " ";
  cout << endl;
}
