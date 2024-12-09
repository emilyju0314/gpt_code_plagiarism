#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const int oo = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
const int maxn = 1000;
const long double eps = 1e-15;
int n;
long double first[maxn + 5], second[maxn + 5];
inline bool eq(const long double &first, const long double &second) {
  return abs(first - second) < eps || abs(first - second) < eps * abs(first);
}
struct data {
  long double a, b, k;
  data() {}
  data(const long double &_a, const long double &_b, const long double &_k)
      : a(_a), b(_b), k(_k) {}
  friend bool operator<(const data &first, const data &second) {
    return eq(first.a, second.a)
               ? eq(first.b, second.b) ? first.k < second.k : first.b < second.b
               : first.a < second.a;
  }
};
vector<data> all;
int main() {
  scanf("%d", &n);
  for (int i = (0), _end_ = (n); i < _end_; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    double tmp = 1.0 / (a * a * d * d + c * c * b * b);
    first[i] = tmp * a * b * d * d;
    second[i] = tmp * c * b * b * d;
  }
  for (int i = (0), _end_ = (n); i < _end_; ++i)
    for (int j = (0), _end_ = (i); j < _end_; ++j)
      all.push_back(
          data(first[i] + first[j], second[i] + second[j],
               eq(first[i] - first[j], 0)
                   ? 1e100
                   : (second[i] - second[j]) / (first[i] - first[j])));
  sort((all).begin(), (all).end());
  int m = (int((all).size()));
  int ans = 0;
  for (int i = 0; i < m;) {
    int j = i;
    while (j < m && eq(all[i].a, all[j].a) && eq(all[i].b, all[j].b)) ++j;
    int tmp = 1;
    for (int k = i; k < j;) {
      int l = k;
      while (l < j && eq(all[k].k, all[l].k)) ++l;
      tmp = (long long)tmp * (l - k + 1) % Mod;
      k = l;
    }
    (ans += tmp) %= Mod;
    (ans -= j - i + 1) %= Mod;
    i = j;
  }
  printf("%d\n", ans);
  return 0;
}
