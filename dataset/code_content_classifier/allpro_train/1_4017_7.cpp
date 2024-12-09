#include <bits/stdc++.h>
using namespace std;
template <class T>
void setmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void setmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const char dc[4] = {'U', 'R', 'D', 'L'};
const int MAXN = 100010;
const int MAXQ = 100010;
const int MAXLog = 20;
int ax0[MAXN], ay0[MAXN], ax1[MAXN], ay1[MAXN], avx[MAXN], avy[MAXN];
int nxt[MAXN];
long long dis[MAXN];
int qx[MAXN], qy[MAXN], qd[MAXN];
long long qt[MAXN];
int qnxt[MAXN];
int n, sz, qs;
int sgn(int x) {
  if (x == 0)
    return 0;
  else
    return x > 0 ? 1 : -1;
}
pair<int, int> lst[MAXN + MAXQ];
int color[MAXN * 4];
void paint(int x, int s, int t, int le, int ri, int c) {
  if (le <= s && t <= ri) {
    color[x] = c;
    return;
  }
  int mid = (s + t) / 2;
  if (color[x] >= 0) {
    color[x * 2] = color[x * 2 + 1] = color[x];
    color[x] = -1;
  }
  if (le <= mid) paint(x * 2, s, mid, le, ri, c);
  if (mid < ri) paint(x * 2 + 1, mid + 1, t, le, ri, c);
}
int getcolor(int x, int s, int t, int p) {
  if (color[x] >= 0) return color[x];
  int mid = (s + t) / 2;
  if (p <= mid)
    return getcolor(x * 2, s, mid, p);
  else
    return getcolor(x * 2 + 1, mid + 1, t, p);
}
void init() {
  scanf("%d%d", &n, &sz);
  for (int i = (int)(1); i <= (int)(n); ++i) {
    scanf("%d%d%d%d", ax0 + i, ay0 + i, ax1 + i, ay1 + i);
    avx[i] = sgn(ax1[i] - ax0[i]);
    avy[i] = sgn(ay1[i] - ay0[i]);
  }
  scanf("%d", &qs);
  for (int i = (int)(1); i <= (int)(qs); ++i) {
    char c[9];
    scanf("%d%d%s", qx + i, qy + i, c);
    cin >> qt[i];
    qd[i] = 0;
    while (dc[qd[i]] != c[0]) ++qd[i];
  }
  for (int dir = 0; dir < (int)(4); ++dir) {
    for (int i = (int)(1); i <= (int)(n); ++i) {
      int v0 = ax0[i] * dx[dir] + ay0[i] * dy[dir];
      int v1 = ax1[i] * dx[dir] + ay1[i] * dy[dir];
      lst[i].first = min(-v0, -v1);
      lst[i].second = -i;
    }
    for (int i = (int)(1); i <= (int)(qs); ++i) {
      lst[n + i].first = -(qx[i] * dx[dir] + qy[i] * dy[dir]);
      lst[n + i].second = i;
    }
    sort(lst + 1, lst + n + qs + 1);
    memset(color, 0, sizeof(color));
    for (int k = (int)(1); k <= (int)(n + qs); ++k) {
      int i = -lst[k].second;
      if (i > 0) {
        if (avx[i] == dx[dir] && avy[i] == dy[dir]) {
          int s = ax1[i];
          if (dx[dir] != 0) s = ay1[i];
          int c = getcolor(1, 1, sz + 1, s + 1);
          nxt[i] = c;
        }
        int l = ax0[i], r = ax1[i];
        if (dx[dir] != 0) l = ay0[i], r = ay1[i];
        if (l > r) swap(l, r);
        paint(1, 1, sz + 1, l + 1, r + 1, i);
      } else {
        i = -i;
        if (dir == qd[i]) {
          int s = qx[i];
          if (dx[dir] != 0) s = qy[i];
          qnxt[i] = getcolor(1, 1, sz + 1, s + 1);
        }
      }
    }
  }
  for (int i = (int)(1); i <= (int)(n); ++i) {
    if (nxt[i] == 0) {
      int sid = 0;
      if (avx[i] + avy[i] > 0) sid = sz;
      dis[i] = abs(sid - (avx[i] != 0 ? ax1[i] : ay1[i]));
    } else {
      int j = nxt[i];
      dis[i] = abs(ax1[i] - ax1[j]) + abs(ay1[i] - ay1[j]);
    }
  }
}
long long clen[MAXN];
bool vis[MAXN];
long long tmp[MAXN];
int plnk[MAXN][MAXLog];
long long plen[MAXN][MAXLog];
void getwalk(int t, int x1, int y1, int dx, int dy, int x2, int y2, int &x,
             int &y) {
  bool fl = false;
  if (dx == 0) fl = true, swap(x1, y1), swap(x2, y2), swap(dx, dy);
  int px = abs(x1 - x2);
  if (t <= px) {
    x = x1 + dx * t, y = y1;
  } else {
    x = x2, y = y1;
    t -= px;
    dy = sgn(y2 - y1);
    y += dy * t;
  }
  if (fl) swap(x, y);
}
bool onside(int x, int y, int x1, int y1, int x2, int y2) {
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}
void solve() {
  memset(clen, 0xff, sizeof(clen));
  memset(tmp, 0xff, sizeof(tmp));
  memset(vis, false, sizeof(vis));
  for (int i = (int)(1); i <= (int)(n); ++i)
    if (!vis[i]) {
      tmp[i] = 0;
      for (int y = i, x = nxt[i];; y = x, x = nxt[x]) {
        if (x == 0) break;
        if (vis[x]) break;
        if (tmp[x] >= 0) {
          long long len = tmp[y] + dis[y] - tmp[x];
          clen[x] = len;
          for (int k = nxt[x]; k != x; k = nxt[k]) clen[k] = len;
          break;
        }
        tmp[x] = tmp[y] + dis[y];
      }
      for (int x = i; x > 0 && !vis[x]; x = nxt[x]) vis[x] = true;
    }
  for (int i = (int)(1); i <= (int)(n); ++i)
    if (nxt[i] > 0) {
      plnk[i][0] = nxt[i];
      plen[i][0] = dis[i];
    } else {
      plnk[i][0] = i;
      plen[i][0] = 0;
    }
  for (int j = (int)(1); j <= (int)(MAXLog - 1); ++j)
    for (int i = (int)(1); i <= (int)(n); ++i) {
      plnk[i][j] = plnk[plnk[i][j - 1]][j - 1];
      plen[i][j] = plen[i][j - 1] + plen[plnk[i][j - 1]][j - 1];
    }
  for (int cur = (int)(1); cur <= (int)(qs); ++cur) {
    int d = qd[cur];
    if (qnxt[cur] == 0) {
      long long x = qx[cur] + dx[d] * qt[cur];
      long long y = qy[cur] + dy[d] * qt[cur];
      if (x < 0) x = 0;
      if (x > sz) x = sz;
      if (y < 0) y = 0;
      if (y > sz) y = sz;
      printf("%d %d\n", (int)x, (int)y);
      continue;
    }
    int i = qnxt[cur];
    long long l = abs(qx[cur] - ax1[i]) + abs(qy[cur] - ay1[i]);
    long long t = qt[cur];
    if (t <= l) {
      int x, y, u = dx[d], v = dy[d];
      if (onside(qx[cur], qy[cur], ax0[i], ay0[i], ax1[i], ay1[i]))
        u = avx[i], v = avy[i];
      getwalk((int)t, qx[cur], qy[cur], u, v, ax1[i], ay1[i], x, y);
      printf("%d %d\n", x, y);
    } else {
      t -= l;
      for (int j = MAXLog - 1; j >= 0; --j)
        if (plen[i][j] <= t) {
          t -= plen[i][j];
          i = plnk[i][j];
        }
      if (clen[i] > 0) t %= clen[i];
      for (int j = MAXLog - 1; j >= 0; --j)
        if (plen[i][j] <= t) {
          t -= plen[i][j];
          i = plnk[i][j];
        }
      int j = nxt[i];
      if (j == 0) {
        long long x = ax1[i] + avx[i] * t;
        long long y = ay1[i] + avy[i] * t;
        if (x < 0) x = 0;
        if (x > sz) x = sz;
        if (y < 0) y = 0;
        if (y > sz) y = sz;
        printf("%d %d\n", (int)x, (int)y);
      } else {
        int x, y;
        getwalk((int)t, ax1[i], ay1[i], avx[i], avy[i], ax1[j], ay1[j], x, y);
        printf("%d %d\n", x, y);
      }
    }
  }
}
int main() {
  init();
  solve();
  return 0;
}
