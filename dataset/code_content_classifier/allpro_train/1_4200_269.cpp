#include <bits/stdc++.h>
using namespace std;
const int M = 2e3 + 10;
int n;
struct Point {
  int x, y;
  Point() {}
  Point(const int &x, const int &y) : x(x), y(y) {}
  int dim() const { return x < 0 || x == 0 && y < 0; }
  void in() { cin >> x >> y; }
} a[M];
Point b[M];
long long tot, cut;
int operator*(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
bool operator<(const Point &a, const Point &b) {
  if (a.dim() == b.dim()) {
    return a * b > 0;
  } else {
    return a.dim() > b.dim();
  }
}
bool operator==(const Point &a, const Point &b) { return !(a < b) && !(b < a); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) a[i].in();
  tot = 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    for (int j = 0, N = 0; j < n; j++) {
      if (i == j) continue;
      b[N] = Point(a[j].x - a[i].x, a[j].y - a[i].y);
      N++;
    }
    sort(b, b + n - 1);
    int tmp = 0;
    for (int j = 1; j < n - 1; j++) {
      if (b[j] == b[j - 1])
        tmp++;
      else {
        cut += 1ll * (tmp + 1) * tmp / 2;
        tmp = 0;
      }
    }
    cut += 1ll * (tmp + 1) * tmp / 2;
  }
  cout << tot - cut / 2 << endl;
  return 0;
}
