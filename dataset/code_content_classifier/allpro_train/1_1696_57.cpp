#include <bits/stdc++.h>
const double eps = 1e-12;
struct point {
  double x, y;
  inline void input() {
    int a, b;
    scanf("%d%d", &a, &b);
    x = a;
    y = b;
  }
  inline point operator+(const point &a) const { return {x + a.x, y + a.y}; }
  inline point operator-(const point &a) const { return {x - a.x, y - a.y}; }
  inline point operator*(const double &a) const { return {x * a, y * a}; }
  inline point operator/(const double &a) const { return {x / a, y / a}; }
  inline double operator*(const point &a) const { return x * a.y - y * a.x; }
  inline bool operator<(const point &a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
  inline bool operator==(const point &a) const { return x == a.x && y == a.y; }
} arr[35], pnt[5];
int pos[5], cnt, n;
inline bool in(double x, double l, double r) {
  if (l > r) std::swap(l, r);
  return x >= l - eps && x <= r + eps;
}
inline double dis(point a, point b) {
  return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline point inter(point sta, point veca, point stb, point vecb) {
  return sta + veca * ((sta - stb) * vecb) / (vecb * veca);
}
inline void inter(point a, point b, point c, point d, int idx) {
  point x = inter(a, b - a, c, d - c);
  if (in(x.x, a.x, b.x) && in(x.y, a.y, b.y) && in(x.x, c.x, d.x) &&
      in(x.y, c.y, d.y)) {
    if (x == c) return;
    pos[cnt] = idx;
    pnt[cnt++] = x;
  }
}
inline double calc(int x, int y) {
  int l = (pos[x] + 1) % n, r = pos[y];
  double res = dis(pnt[x], arr[l]) + dis(pnt[y], arr[r]);
  while (l != r) {
    res += dis(arr[l], arr[(l + 1) % n]);
    l = (l + 1) % n;
  }
  return res;
}
int main() {
  point st, en;
  st.input();
  en.input();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) arr[i].input();
  for (int i = 0; i < n; i++) inter(st, en, arr[i], arr[(i + 1) % n], i);
  if (cnt <= 1) {
    printf("%.10lf\n", dis(st, en));
    return 0;
  }
  if (dis(st, pnt[0]) > dis(st, pnt[1])) {
    std::swap(pnt[0], pnt[1]);
    std::swap(pos[0], pos[1]);
  }
  printf("%.10lf\n", dis(st, pnt[0]) + dis(en, pnt[1]) +
                         std::min(std::min(calc(0, 1), calc(1, 0)),
                                  2 * dis(pnt[0], pnt[1])));
  return 0;
}
