#include <bits/stdc++.h>
using namespace std;
struct R2vec {
  int x, y;
  R2vec() {}
  R2vec(int x, int y) : x(x), y(y) {}
  inline R2vec operator+(const R2vec &w) { return R2vec(x + w.x, y + w.y); }
  inline R2vec operator-(const R2vec &w) { return R2vec(x - w.x, y - w.y); }
  inline R2vec operator-() { return R2vec(-x, -y); }
  inline long long int operator*(const R2vec &w) {
    return (long long int)x * w.x + (long long int)y * w.y;
  }
  inline long long int operator%(const R2vec &w) {
    return (long long int)x * w.y - (long long int)y * w.x;
  }
  inline long long int operator~() {
    return (long long int)x * x + (long long int)y * y;
  }
  inline bool operator<(const R2vec &w) const {
    return x != w.x ? x < w.x : y < w.y;
  }
  inline bool operator==(const R2vec &w) { return x == w.x && y == w.y; }
  inline bool operator!=(const R2vec &w) { return x != w.x || y != w.y; }
};
inline ostream &operator<<(ostream &out, const R2vec &w) {
  return out << '[' << w.x << ',' << w.y << ']';
}
struct ConvexHull {
  vector<R2vec> hull;
  ConvexHull() {}
  ConvexHull(vector<R2vec> cloud) {
    sort((cloud).begin(), (cloud).end());
    vector<R2vec> up, down;
    for (auto &w : cloud) {
      while (((int)(up).size()) > 1 &&
             (up.back() - up[((int)(up).size()) - 2]) % (w - up.back()) >= 0)
        up.pop_back();
      up.push_back(w);
      while (((int)(down).size()) > 1 &&
             (down.back() - down[((int)(down).size()) - 2]) %
                     (w - down.back()) <=
                 0)
        down.pop_back();
      down.push_back(w);
    }
    hull = up;
    for (int i = ((int)(down).size()) - 2; i; --i) hull.push_back(down[i]);
  }
  vector<pair<long long int, long long int>> hash() {
    vector<pair<long long int, long long int>> res(((int)(hull).size()));
    for (int i = 0; i < ((int)(hull).size()); ++i)
      res[i] = {
          ~(hull[i] - hull[(i ? i - 1 : ((int)(hull).size()) - 1)]),
          (hull[(i ? i - 1 : ((int)(hull).size()) - 1)] - hull[i]) *
              (hull[(i + 1 < ((int)(hull).size()) ? i + 1 : 0)] - hull[i])};
    return res;
  }
};
template <class C>
struct KMP {
  C p;
  vector<int> fail;
  KMP(C p) : p(p), fail(((int)(p).size())) {
    for (int i = 0, j = -2; i < ((int)(p).size()); fail[i] = ++j, ++i)
      while (j > -2 && p[j + 1] != p[i])
        if (j == -1)
          j = -2;
        else
          j = fail[j];
  }
  vector<int> all_match(C &text, bool overlap = true) {
    vector<int> res;
    for (int i = 0, j = -1; i < ((int)(text).size()); ++i) {
      while (j > -2 && p[j + 1] != text[i])
        if (j == -1)
          j = -2;
        else
          j = fail[j];
      if (++j == ((int)(p).size()) - 1)
        res.push_back(i - j), j = overlap ? fail[j] : -1;
    }
    return res;
  }
  bool match(C &text) {
    for (int i = 0, j = -1; i < ((int)(text).size()); ++i) {
      while (j > -2 && p[j + 1] != text[i])
        if (j == -1)
          j = -2;
        else
          j = fail[j];
      if (++j == ((int)(p).size()) - 1) return true;
    }
    return false;
  }
};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<R2vec> e1(n), e2(m);
  for (auto &e : e1) scanf("%d%d", &e.x, &e.y);
  for (auto &e : e2) scanf("%d%d", &e.x, &e.y);
  ConvexHull CH1(e1), CH2(e2);
  vector<pair<long long int, long long int>> a1;
  KMP<vector<pair<long long int, long long int>>> kmp(a1 = CH1.hash());
  vector<pair<long long int, long long int>> hash = CH2.hash();
  for (int i = 0, j = ((int)(hash).size()); i < j; ++i) hash.push_back(hash[i]);
  if (kmp.match(hash))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
