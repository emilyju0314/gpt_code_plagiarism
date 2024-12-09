#include <bits/stdc++.h>
using namespace std;
template <class T, class V>
ostream &operator<<(ostream &s, pair<T, V> a) {
  s << a.first << ' ' << a.second;
  return s;
}
long long int bigmod(long long int a, long long int p, long long int m) {
  long long int res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
void XOR(vector<long long int> &a, bool inv = false, int add = 0) {
  int M = a.size();
  int MD = (1000000007) + add;
  for (int len = 2, l2 = 1; len <= M; len <<= 1, l2 <<= 1) {
    for (int i = 0, inc = M / len; i < M; i += len) {
      for (int j = 0, l = 0; j < l2; j++, l += inc) {
        long long int u = a[i + j], v = a[i + j + l2];
        a[i + j] = (u + v > MD ? u + v - MD : u + v);
        a[i + j + l2] = (u - v < 0 ? u - v + MD : u - v);
        ;
      }
    }
  }
  if (inv) {
    int invM = bigmod(M, MD - 2, MD);
    for (auto &x : a) x = x * invM % MD;
  }
}
void multiply(vector<long long int> &a, vector<long long int> &b,
              vector<long long int> &v1, int add = 0) {
  int n = max(a.size(), b.size());
  int M = v1.size();
  vector<long long int> v2(M);
  for (int i = 0; i < b.size(); i++) v2[i] = b[i];
  XOR(v2, false, add);
  for (int i = 0; i < M; i++) v1[i] = v1[i] * v2[i] % ((1000000007) + add);
}
vector<pair<long long int, long long int> > adj[300005];
int vis[300005];
vector<vector<long long int> > cycle;
void dfs(int ind, vector<pair<long long int, long long int> > &st, int par = -1,
         int w = 0) {
  st.push_back(pair<long long int, long long int>(ind, w));
  vis[ind] = 1;
  for (auto x : adj[ind]) {
    if (x.first == par) continue;
    if (vis[x.first] == 1) {
      cycle.emplace_back();
      cycle.back().push_back(x.second);
      for (int i = st.size() - 1; st[i].first != x.first; i--)
        cycle.back().push_back(st[i].second);
    } else if (vis[x.first] == 0)
      dfs(x.first, st, ind, x.second);
  }
  vis[ind] = 2;
  st.pop_back();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  for (int qq = 1; qq <= T; qq++) {
    int n, m;
    cin >> n >> m;
    int all = 0;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      all ^= w;
      adj[u].push_back(pair<long long int, long long int>(v, w));
      adj[v].push_back(pair<long long int, long long int>(u, w));
    }
    vector<pair<long long int, long long int> > st;
    dfs(1, st);
    vector<long long int> ans(131072), ans2(131072);
    ans[0] = 1;
    ans2[0] = 1;
    XOR(ans, false, 0);
    XOR(ans2, false, 2);
    for (auto x : cycle) {
      vector<long long int> temp(131072);
      for (auto y : x) temp[y]++;
      multiply(ans, temp, ans);
      multiply(ans2, temp, ans2, 2);
    }
    XOR(ans, 1, 0);
    XOR(ans2, 1, 2);
    pair<long long int, long long int> a = {2000000000, 0};
    for (int i = 0; i < 131072; i++) {
      if ((ans[i] || ans2[i]) && (a.first > (i ^ all))) {
        a = {(i ^ all), ans[i]};
      }
    }
    cout << a << endl;
  }
}
