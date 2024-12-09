#include <bits/stdc++.h>
using namespace std;
const int N = 11, inf = 1e9, M = 999;
int n, t, xZ, yZ, sd = 4, uksc, ukkap;
int sci[N][N], dfZ[N][N], dn[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> g[M], kap[N][N];
bool chp(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < n && sci[x][y] != -1;
}
bool us[M];
int p[M], ans;
bool kun(int v) {
  if (us[v]) return false;
  us[v] = true;
  for (int i : g[v]) {
    if (p[i] == -1 || kun(p[i])) {
      p[i] = v;
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  for (int i = 0; i < n; ++i) {
    fill(dfZ[i], dfZ[i] + n, inf);
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == 'Z') xZ = i, yZ = j;
      if (s[j] >= '0' && s[j] <= '9')
        sci[i][j] = s[j] - '0';
      else
        sci[i][j] = -1;
    }
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] > '0' && s[j] <= '9') {
        for (int P = 0; P < s[j] - '0'; ++P) kap[i][j].push_back(ukkap++);
      }
    }
  }
  dfZ[xZ][yZ] = 0;
  queue<pair<int, int> > q;
  q.push({xZ, yZ});
  while (!q.empty()) {
    int xv = q.front().first, yv = q.front().second;
    q.pop();
    for (int i = 0; i < sd; ++i) {
      int xt = xv + dx[i], yt = yv + dy[i];
      if (!chp(xt, yt) || dfZ[xt][yt] <= dfZ[xv][yv] + 1) continue;
      dfZ[xt][yt] = dfZ[xv][yv] + 1;
      q.push({xt, yt});
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (sci[i][j] <= 0) continue;
      for (int P = 0; P < n; ++P) fill(dn[P], dn[P] + n, inf);
      dn[i][j] = 0;
      q.push({i, j});
      vector<int> kek;
      while (!q.empty()) {
        int xv = q.front().first, yv = q.front().second;
        for (int K : kap[xv][yv]) kek.push_back(K);
        q.pop();
        for (int T = 0; T < sd; ++T) {
          int xt = xv + dx[T], yt = yv + dy[T];
          if (!chp(xt, yt) || dn[xt][yt] <= dn[xv][yv] + 1 ||
              dfZ[xt][yt] < dn[xv][yv] + 1 || dn[xv][yv] == t ||
              dfZ[xv][yv] == dn[xv][yv])
            continue;
          dn[xt][yt] = dn[xv][yv] + 1;
          q.push({xt, yt});
        }
      }
      for (int U = uksc; U < uksc + sci[i][j]; ++U)
        for (int K : kek) g[U].push_back(K);
      uksc += sci[i][j];
    }
  }
  fill(p, p + M, -1);
  for (int i = 0; i < uksc; ++i) {
    if (kun(i)) {
      ans++;
      fill(us, us + uksc, false);
    }
  }
  cout << ans;
}
