#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-13;
struct point {
  long long x, y;
  long long d;
  double z;
  point(){};
  point(int _x, int _y) : x(_x), y(_y) {}
  bool operator<(const point& v) const {
    return z < v.z || (fabs(z - v.z) < eps && d < v.d);
  }
  point operator-(const point u) const { return point(x - u.x, y - u.y); }
  long long operator^(const point u) const { return x * u.y - y * u.x; }
  long long operator*(const point u) const { return x * u.x + y * u.y; }
  void print() const { printf("%d %d\n", x, y); }
};
struct ConvexHull {
  point center;
  set<point> st;
  set<point>::iterator L(set<point>::iterator x) {
    if (x == st.begin()) x = st.end();
    x--;
    return x;
  }
  set<point>::iterator R(set<point>::iterator x) {
    x++;
    if (x == st.end()) x = st.begin();
    return x;
  }
  bool insert(point a) {
    if (st.find(a) != st.end()) return false;
    a.d = (a - center) * (a - center);
    a.z = atan2(a.y - center.y, a.x - center.x);
    if (st.size() > 2) {
      set<point>::iterator i = st.lower_bound(a), j;
      if (i == st.end()) i = st.begin();
      j = L(i);
      if (((a - *j) ^ (*i - *j)) <= 0) return false;
    }
    if (st.size() == 2) {
      set<point>::iterator i = st.begin();
      set<point>::iterator j = R(i);
      if (((a - *j) ^ (*i - *j)) == 0) {
        if (((a - *j) * (*i - *j)) < 0) return false;
        st.insert(a);
        st.erase(R(st.begin()));
        return true;
      }
    }
    st.insert(a);
    if (st.size() <= 3) return true;
    set<point>::iterator cur = st.find(a), i, j;
    i = L(cur);
    j = L(i);
    while (((*i - *j) ^ (*cur - *j)) <= 0) {
      st.erase(i);
      i = j;
      j = L(j);
    }
    i = R(cur);
    j = R(i);
    while (((*i - *j) ^ (*cur - *j)) >= 0) {
      st.erase(i);
      i = j;
      j = R(j);
    }
    return true;
  }
  bool Inhull(point a) {
    a.d = (a - center) * (a - center);
    a.z = atan2(a.y - center.y, a.x - center.x);
    set<point>::iterator i = st.lower_bound(a), j;
    if (i == st.end()) i = st.begin();
    j = L(i);
    return ((a - *j) ^ (*i - *j)) <= 0;
  }
} CH;
point o, p, a[5];
int q, op;
int main() {
  scanf("%d", &q);
  for (int i = 0; i < 3; i++) {
    scanf("%d%I64d%I64d", &op, &a[i].x, &a[i].y);
    o.x += a[i].x;
    o.y += a[i].y;
    a[i].x *= 3;
    a[i].y *= 3;
  }
  CH.center = o;
  for (int i = 0; i < 3; i++) CH.insert(a[i]);
  q -= 3;
  while (q--) {
    scanf("%d%I64d%I64d", &op, &p.x, &p.y);
    p.x *= 3;
    p.y *= 3;
    if (op == 2) {
      if (CH.Inhull(p))
        puts("YES");
      else
        puts("NO");
    } else
      CH.insert(p);
  }
  return 0;
}
