#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int qpow(int x, int p, int mod) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = 1ll * res * x % mod;
    }
    p >>= 1;
    x = 1ll * x * x % mod;
  }
  return res;
}
void solve();
mt19937 rng(time(0));
long long qpow(long long x, long long p, long long MOD) {
  long long res = 1, v = x;
  while (p) {
    if (p & 1) {
      res *= v;
      res %= MOD;
    }
    v *= v;
    v %= MOD;
    p >>= 1;
  }
  return res;
}
long long inv(long long x, long long MOD) { return qpow(x, MOD - 2, MOD); }
void init() {}
long long read() {
  int ch = getchar();
  if (ch == EOF) {
    return INT_MIN;
  }
  while (!isdigit(ch) && ch != '-') {
    ch = getchar();
    if (ch == EOF) {
      return INT_MIN;
    }
  }
  long long res = 0, sign = 1;
  if (ch == '-') {
    ch = getchar();
    sign = -1;
  }
  while (isdigit(ch)) {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * sign;
}
int nextchar() {
  int ch = getchar();
  while (ch == ' ' || ch == '\n' || ch == '\r') {
    ch = getchar();
  }
  return ch;
}
int main() {
  init();
  solve();
  return 0;
}
const int MAXN = 1505;
char grid[MAXN][MAXN];
int wx[MAXN][MAXN], wy[MAXN][MAXN];
bool check() {
  int n = read(), m = read(), sx = -1, sy = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'S') {
        sx = i, sy = j;
        break;
      }
    }
  }
  memset(wx, 0x3f, sizeof(wx));
  queue<pair<int, int>> q;
  q.push({sx, sy});
  wx[sx][sy] = 0;
  wy[sx][sy] = 0;
  int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
  while (q.size()) {
    auto [i, j] = q.front();
    q.pop();
    int cwx = wx[i][j], cwy = wy[i][j];
    for (int d = 0; d < 4; ++d) {
      int ni = i + dx[d], nj = j + dy[d], nwx = cwx, nwy = cwy;
      if (ni == n) ni = 0, nwx += 1;
      if (ni == -1) ni = n - 1, nwx -= 1;
      if (nj == m) nj = 0, nwy += 1;
      if (nj == -1) nj = m - 1, nwy -= 1;
      if (grid[ni][nj] != '#') {
        if (wx[ni][nj] > 1e4) {
          q.push({ni, nj});
          wx[ni][nj] = nwx;
          wy[ni][nj] = nwy;
        } else if (wx[ni][nj] != nwx || wy[ni][nj] != nwy) {
          return true;
        }
      }
    }
  }
  return false;
}
void solve() { check() ? puts("Yes") : puts("No"); }
