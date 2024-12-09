#include <bits/stdc++.h>
using std::make_pair;
using std::pair;
using std::sort;
using std::swap;
const int N = 1e3 + 10;
int n, top, ans[N][2], cnt;
bool incv[N];
struct point {
  int x, y, org;
  bool color;
  inline point(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
  inline const bool operator==(const point &p) const {
    return color == p.color;
  }
  inline const friend double distance(const point &p1, const point &p2) {
    return sqrt(pow(1.0 * (p1.x - p2.x), 2.0) + pow(1.0 * (p1.y - p2.y), 2.0));
  }
} p[N], s[N], ss[N];
struct vector {
  int x, y;
  inline vector(const point &a, const point &b) {
    x = b.x - a.x;
    y = b.y - a.y;
  }
  inline const double length() { return distance(point(0, 0), point(x, y)); }
  inline const friend int cross_product(const vector &v1, const vector &v2) {
    return v1.x * v2.y - v1.y * v2.x;
  }
};
struct triangle {
  point v[3];
  inline triangle(const point &a, const point &b, const point &c) {
    v[0] = a;
    v[1] = b;
    v[2] = c;
  }
  inline const bool difference() {
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < 3; i++) cnt[v[i].color]++;
    return cnt[0] > cnt[1];
  }
  inline const pair<point, point> same() {
    bool c = difference();
    int s[2], cnt = -1;
    for (int i = 0; i < 3; i++)
      if (v[i].color ^ c) s[++cnt] = i;
    return make_pair(v[s[0]], v[s[1]]);
  }
  inline const bool in(const point &p) {
    int cp1 = cross_product(vector(v[0], v[1]), vector(v[0], p)),
        cp2 = cross_product(vector(v[1], v[2]), vector(v[1], p)),
        cp3 = cross_product(vector(v[2], v[0]), vector(v[2], p));
    return cp1 && cp2 && cp3 && (cp1 > 0) == (cp2 > 0) &&
           (cp1 > 0) == (cp3 > 0);
  }
};
int fa[N];
inline const void init() {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
inline const int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline const void Union(int x, int y) { fa[find(x)] = find(y); }
inline const bool operator<(const point &p1, const point &p2) {
  vector v1(p[1], p1), v2(p[1], p2);
  int cp = cross_product(v1, v2);
  if (cp > 0) return true;
  if (!cp && v1.length() < v2.length()) return true;
  return false;
}
inline const void convex_hull() {
  for (int i = 1; i <= n; i++)
    if (p[i].y < p[1].y) swap(p[1], p[i]);
  sort(p + 2, p + n + 1);
  s[++top] = p[1];
  incv[p[1].org] = 1;
  for (int i = 2; i <= n; i++) {
    while (top > 1 &&
           cross_product(vector(s[top - 1], s[top]), vector(s[top], p[i])) <= 0)
      incv[s[top].org] = 0, top--;
    s[++top] = p[i];
    incv[p[i].org] = 1;
  }
}
inline const void divide(triangle t) {
  bool c = t.difference();
  static std::vector<point> same, diff;
  same.clear();
  diff.clear();
  for (int i = 1; i <= n; i++)
    if (t.in(p[i]))
      if (p[i].color ^ c)
        same.push_back(p[i]);
      else
        diff.push_back(p[i]);
  pair<point, point> P = t.same();
  if (diff.empty()) {
    same.push_back(P.first);
    same.push_back(P.second);
    for (int i = 0; i < same.size() - 1; i++)
      for (int u, v, j = i + 1; j < same.size(); j++)
        if (find(u = same[i].org) ^ find(v = same[j].org))
          ans[++cnt][0] = u - 1, ans[cnt][1] = v - 1, Union(u, v);
    return;
  }
  point nxt = diff[0];
  for (int i = 0; i < 2; i++) divide(triangle(t.v[i], t.v[i + 1], nxt));
  divide(triangle(t.v[2], t.v[0], nxt));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].color), p[i].org = i;
  convex_hull();
  init();
  for (int i = 1; i <= top; i++) ss[i] = s[i];
  int tot = std::unique(ss + 1, ss + top + 1) - ss - 1;
  if (tot > 3 || tot == 3 && ss[1].color ^ ss[tot].color)
    return puts("Impossible"), 0;
  int fst = 0, lst = 0;
  bool c = ss[1].color;
  if (tot > 2) {
    for (int i = 1; i <= top; i++) {
      if (s[i].color ^ c && !fst) fst = i;
      if (s[i].color ^ c) lst = i;
    }
    for (int i = fst; i < lst; i++)
      divide(triangle(s[i], s[i + 1], s[lst + 1]));
    for (int i = lst + 1; i < top; i++)
      divide(triangle(s[i], s[i + 1], s[fst]));
    for (int i = 1; i < fst - 1; i++) divide(triangle(s[i], s[i + 1], s[fst]));
    divide(triangle(s[top], s[1], s[fst]));
  }
  if (tot == 2) {
    int pos;
    for (int i = 1; i <= top; i++)
      if (s[i].color ^ c) {
        pos = i;
        break;
      }
    for (int i = pos; i < top; i++)
      divide(triangle(s[pos - 1], s[i], s[i + 1]));
    for (int i = 1; i < pos - 1; i++) divide(triangle(s[i], s[i + 1], s[top]));
  }
  if (tot == 1) {
    point one;
    bool found = 0;
    for (int i = 1; i <= n; i++)
      if (!incv[p[i].org] && p[i].color ^ c) {
        one = p[i];
        found = 1;
        break;
      }
    if (found) {
      for (int i = 1; i < top; i++) divide(triangle(s[i], s[i + 1], one));
      divide(triangle(s[top], s[1], one));
    } else {
      for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
          if (find(i) ^ find(j))
            ans[++cnt][0] = i - 1, ans[cnt][1] = j - 1, Union(i, j);
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
