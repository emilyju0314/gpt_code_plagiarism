#include <bits/stdc++.h>
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return sgn ? -res : res;
}
const int N = 2005;
const int INF = 0x3f3f3f3f;
const double eps = 1e-12;
int n, sze;
bool vis[N];
std::pair<double, double> p[N];
std::vector<double> vc;
long long ans;
inline int sgn(const double &x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
inline double Compare(const std::pair<double, double> &u,
                      const std::pair<double, double> &v) {
  return sgn(u.second * v.first - u.first * v.second);
}
inline bool cmp(const std::pair<double, double> &u,
                const std::pair<double, double> &v) {
  return sgn(u.second * v.first - u.first * v.second) <= 0;
}
int main() {
  n = read();
  for (int i = (0); i < (n); ++i) {
    int a = read(), b = read(), c = read();
    double d = a * a + b * b;
    p[i].first = (double)a * c / d;
    p[i].second = (double)b * c / d;
    if (sgn(p[i].first) == 0 && sgn(p[i].second) == 0) {
      ++sze;
      vis[i] = true;
    }
  }
  if (sze == 2) ans = n - 2;
  for (int i = (0); i < (n); ++i)
    if (!vis[i]) {
      vc.clear();
      for (int j = (i + 1); j < (n); ++j)
        if (!vis[j]) {
          std::pair<double, double> k = std::make_pair(
              p[j].first - p[i].first, p[j].second - p[i].second);
          if (sgn(k.first) == 0)
            vc.push_back(1e99);
          else
            vc.push_back(k.second / k.first);
        }
      std::sort(vc.begin(), vc.end());
      for (int j = 0, k = 1; j < (int)((vc).size()); j = k, ++k) {
        while (k < (int)((vc).size()) && sgn(vc[k] - vc[j]) == 0) ++k;
        int l = k - j;
        ans += l * (l - 1) / 2;
      }
    }
  printf("%I64d\n", ans);
  return 0;
}
