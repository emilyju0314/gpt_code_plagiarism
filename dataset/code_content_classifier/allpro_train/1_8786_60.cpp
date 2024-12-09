#include <bits/stdc++.h>
struct point {
  int x, y;
  inline point operator+(const point &a) const { return {x + a.x, y + a.y}; }
  inline point operator-(const point &a) const { return {x - a.x, y - a.y}; }
  inline int operator^(const point &a) const { return x * a.x + y * a.y; }
  inline int operator*(const point &a) const { return x * a.y - y * a.x; }
  inline bool operator<(const point &a) const {
    return x == a.x ? y > a.y : x < a.x;
  }
};
void input(point *arr, int n) {
  for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].x, &arr[i].y);
}
void convex_hull(point *vec, int n, point *res, int &tp) {
  tp = 0;
  std::sort(vec, vec + n);
  for (int i = 0; i < n; i++) {
    while (tp >= 2 && (res[tp - 1] - vec[i]) * (res[tp - 2] - vec[i]) >= 0)
      tp--;
    res[tp++] = vec[i];
  }
  int orig = tp--;
  for (int i = n - 1; i >= 0; i--) {
    while (tp > orig && (res[tp - 1] - vec[i]) * (res[tp - 2] - vec[i]) >= 0)
      tp--;
    res[tp++] = vec[i];
  }
  tp--;
}
point edge[40005];
int ecnt;
void get_edge(point *arr, int l, int r) {
  edge[ecnt++] = {l, r};
  if (r - l + 1 <= 2) return;
  double mx = -1e18;
  int pos = -1;
  for (int i = l + 1; i < r; i++) {
    double d = (double)((arr[i] - arr[l]) ^ (arr[i] - arr[r]));
    d /= (arr[l] - arr[i]) * (arr[l] - arr[r]);
    if (d > mx) {
      mx = d;
      pos = i;
    }
  }
  get_edge(arr, l, pos);
  get_edge(arr, pos, r);
}
bool solve(point *A, int n, point *b, int m) {
  static point a[40005];
  convex_hull(A, n, a, n);
  ecnt = 0;
  get_edge(a, 0, n - 1);
  for (int j = 0; j < ecnt; j++) {
    int l = edge[j].x, r = edge[j].y;
    double lp = -1e18, rp = 1e18;
    for (int i = 0; i < n && lp < rp; i++) {
      if (i == l || i == r) continue;
      int x = (a[i] - a[l]) ^ (a[i] - a[r]);
      int y = (a[l] - a[i]) * (a[l] - a[r]);
      if (!y) continue;
      double t = (double)x / y;
      if (y < 0)
        rp = std::min(rp, t);
      else
        lp = std::max(lp, t);
    }
    for (int i = 0; i < m && lp < rp; i++) {
      int x = (b[i] - a[l]) ^ (b[i] - a[r]);
      int y = (a[l] - b[i]) * (a[l] - a[r]);
      if (!y) {
        if (x > 0) continue;
        if (x <= 0) {
          lp = 1e18;
          break;
        }
      }
      double t = (double)x / y;
      if (y > 0)
        rp = std::min(rp, t);
      else
        lp = std::max(lp, t);
    }
    if (lp < rp) return true;
  }
  return false;
}
point a[40005], b[40005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  input(a, n);
  input(b, m);
  if (n == 1 || m == 1) {
    puts("YES");
    return 0;
  }
  puts(solve(a, n, b, m) || solve(b, m, a, n) ? "YES" : "NO");
  return 0;
}
