#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int sgn(long long cur) {
  if (cur == 0) return 0;
  return cur > 0 ? 1 : -1;
}
int R, B;
struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  void input() { scanf("%d%d", &x, &y); }
} pr[maxn], pb[maxn];
point operator+(point p1, point p2) { return point(p1.x + p2.x, p1.y + p2.y); }
point operator-(point p1, point p2) { return point(p1.x - p2.x, p1.y - p2.y); }
long long vect(point p1, point p2) {
  return 1LL * p1.x * p2.y - 1LL * p1.y * p2.x;
}
long long vect(point p, point p1, point p2) { return vect(p1 - p, p2 - p); }
bool cross(point p1, point p2, point p3, point p4) {
  return sgn(vect(p1, p2, p3)) * sgn(vect(p1, p2, p4)) < 0 &&
         sgn(vect(p3, p4, p1)) * sgn(vect(p3, p4, p2)) < 0;
}
bool common(point p1, point p2, point p3, point p4) {
  if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p3.x, p4.x) < min(p1.x, p2.x))
    return 0;
  if (max(p1.y, p2.y) < min(p3.y, p4.y) || max(p3.y, p4.y) < min(p1.y, p2.y))
    return 0;
  return sgn(vect(p1, p2, p3)) * sgn(vect(p1, p2, p4)) <= 0 &&
         sgn(vect(p3, p4, p1)) * sgn(vect(p3, p4, p2)) <= 0;
}
int vis[maxn];
int ind[maxn];
bool func(int cur) {
  if (cur > 0) {
    point p1 = pr[cur - 1], p2 = pb[ind[cur - 1]];
    for (int i = 0; i < cur - 1; i++) {
      point p3 = pr[i], p4 = pb[ind[i]];
      if (common(p1, p2, p3, p4)) return false;
    }
  }
  if (cur == B) return true;
  for (int i = 0; i < B; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    ind[cur] = i;
    if (func(cur + 1)) return true;
    vis[i] = 0;
  }
  return false;
}
int main() {
  scanf("%d%d", &R, &B);
  for (int i = 0; i < R; i++) pr[i].input();
  for (int i = 0; i < B; i++) pb[i].input();
  if (R != B)
    puts("No");
  else if (func(0))
    puts("Yes");
  else
    puts("No");
  return 0;
}
