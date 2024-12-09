#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const int mod = 998244353;
const int maxn = 2005;
string s;
long long ans = 0;
int n;
vector<pair<int, int> > edges[maxn];
int col[maxn], vis[maxn];
int isbi = 1;
void flood(int x, int curcol) {
  if (vis[x]) {
    if (col[x] != curcol) {
      isbi = 0;
    }
    return;
  }
  vis[x] = 1;
  col[x] = curcol;
  for (int i = 0; i < edges[x].size(); i++) {
    int u = edges[x][i].first, v = edges[x][i].second;
    flood(u, curcol ^ v);
  }
}
int pw(int x, int y) {
  if (!y) return 1;
  if (y == 1) return x;
  int mid = pw(x, y >> 1);
  if (y & 1) return 1ll * mid * mid % mod * x % mod;
  return 1ll * mid * mid % mod;
}
int sear() {
  isbi = 1;
  int con = 0;
  for (int i = 0; i <= 2 * n + 1; i++) {
    if (!vis[i]) {
      flood(i, 0);
      ++con;
    }
  }
  if (!isbi) return 0;
  return pw(2, con - 1);
}
int solve(int m) {
  memset(vis, 0, sizeof vis);
  memset(col, -1, sizeof col);
  for (int i = 0; i <= maxn - 1; i++) edges[i].clear();
  for (int i = 0; i < n; i++) {
    edges[i].push_back(make_pair(n - 1 - i, 0));
  }
  for (int i = 0; i < m; i++) {
    edges[i + n].push_back(make_pair(n + (m - 1 - i), 0));
  }
  for (int i = m; i < n; i++) {
    edges[i + n].push_back(make_pair(2 * n, 0));
    edges[2 * n].push_back(make_pair(i + n, 0));
  }
  for (int i = 0; i < n; i++) {
    if (s[n - 1 - i] == '0') {
      edges[i].push_back(make_pair(i + n, 0));
      edges[i + n].push_back(make_pair(i, 0));
    } else if (s[n - 1 - i] == '1') {
      edges[i].push_back(make_pair(i + n, 1));
      edges[i + n].push_back(make_pair(i, 1));
    }
  }
  edges[2 * n].push_back(make_pair(2 * n + 1, 1));
  edges[2 * n + 1].push_back(make_pair(2 * n, 1));
  edges[n].push_back(make_pair(2 * n, 1));
  edges[2 * n].push_back(make_pair(n, 1));
  edges[0].push_back(make_pair(2 * n, 1));
  edges[2 * n].push_back(make_pair(0, 1));
  return sear();
}
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.size();
  for (int i = 1; i < n; i++) {
    ans = (ans + solve(i)) % mod;
  }
  cout << ans << endl;
  return 0;
}
