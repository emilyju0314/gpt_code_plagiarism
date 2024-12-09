#include <bits/stdc++.h>
using namespace std;
struct point {
  long long int x, y;
  bool operator==(const point &p) const { return (x == p.x && y == p.y); }
};
istream &operator>>(istream &in, point &p) {
  in >> p.x >> p.y;
  return in;
}
struct vect {
  long long int x, y;
  vect(long long int x, long long int y) : x(x), y(y) {}
};
vect p2v(const point &a, const point &b) { return vect(b.x - a.x, b.y - a.y); }
long long int scal_prod(const vect &v1, const vect &v2) {
  return v1.x * v2.x + v1.y * v2.y;
}
long long int vect_prod(const vect &v1, const vect &v2) {
  return v1.x * v2.y - v2.x * v1.y;
}
long long int sqr_len(const vect &v) { return scal_prod(v, v); }
bool lies(point a, point b, point c) {
  vect v1 = p2v(c, a), v2 = p2v(c, b);
  if (vect_prod(v1, v2) != 0 || scal_prod(v1, v2) > 0) {
    return false;
  } else {
    return true;
  }
}
bool check_dist(point a, point b, point c) {
  vect v1 = p2v(c, a), v2 = p2v(c, b);
  long long d1 = sqr_len(v1), d2 = sqr_len(v2);
  long long mmin = min(d1, d2), mmax = max(d1, d2);
  return (16LL * mmin >= mmax);
}
int main() {
  int n_tests;
  cin >> n_tests;
  for (int i = 0; i < n_tests; ++i) {
    vector<point> v;
    for (int j = 0; j < 6; ++j) {
      point tmp;
      cin >> tmp;
      v.push_back(tmp);
    }
    int flag = 0;
    point a1, a2, b1, b2, c1, c2;
    for (int j = 0; j < 6; ++j) {
      for (int k = j + 1; k < 6; ++k) {
        if (v[j] == v[k]) {
          a1 = v[j];
          a2 = v[j ^ 1];
          b1 = v[k];
          b2 = v[k ^ 1];
          for (int l = 0; l < 6; ++l) {
            if (l != j && l != (j ^ 1) && l != k && l != (k ^ 1)) {
              c1 = v[l];
              c2 = v[l ^ 1];
              break;
            }
          }
          flag = 1;
        }
      }
    }
    if (!flag) {
      cout << "NO" << endl;
      continue;
    }
    if (vect_prod(p2v(a1, a2), p2v(b1, b2)) == 0LL ||
        scal_prod(p2v(a1, a2), p2v(b1, b2)) < 0LL) {
      cout << "NO" << endl;
      continue;
    }
    if (!((lies(a1, a2, c1) && lies(b1, b2, c2)) ||
          (lies(a1, a2, c2) && lies(b1, b2, c1)))) {
      cout << "NO" << endl;
      continue;
    }
    if (lies(a1, a2, c1) && lies(b1, b2, c2)) {
      if (!(check_dist(a1, a2, c1) && check_dist(b1, b2, c2))) {
        cout << "NO" << endl;
        continue;
      }
    } else {
      if (!(check_dist(a1, a2, c2) && check_dist(b1, b2, c1))) {
        cout << "NO" << endl;
        continue;
      }
    }
    cout << "YES" << endl;
  }
  return 0;
}
