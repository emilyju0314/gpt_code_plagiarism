#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
template <typename T, typename U>
inline void mnze(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void mxze(T &x, U y) {
  if (x < y) x = y;
}
void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
template <typename T>
void _dbg(const char *sdbg, T h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename T, typename... U>
void _dbg(const char *sdbg, T h, U... t) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
struct BIT {
  int N;
  vector<long long> a;
  void init(int n) {
    a.resize(n + 10);
    N = n + 5;
  }
  void upd(int p, int val) {
    for (++p; p <= N; p += p & -p) a[p] += val;
  }
  long long sum(int p) {
    long long ret = 0;
    for (++p; p; p -= p & -p) ret += a[p];
    return ret;
  }
};
const int MaxN = 2e5 + 5;
bool cnt[MaxN];
int n;
vector<int> x, y;
vector<int> xs[MaxN];
int main() {
  scan(n);
  x.resize(n);
  y.resize(n);
  vector<int> cmpsx, cmpsy;
  for (int i = 0; i < (int)n; i++) {
    scan(x[i], y[i]);
    cmpsx.push_back(x[i]);
    cmpsy.push_back(y[i]);
  }
  sort(cmpsx.begin(), cmpsx.end());
  cmpsx.resize(distance(cmpsx.begin(), unique(cmpsx.begin(), cmpsx.end())));
  for (int i = 0; i < (int)n; i++)
    x[i] =
        distance(cmpsx.begin(), lower_bound(cmpsx.begin(), cmpsx.end(), x[i]));
  sort(cmpsy.begin(), cmpsy.end());
  cmpsy.resize(distance(cmpsy.begin(), unique(cmpsy.begin(), cmpsy.end())));
  for (int i = 0; i < (int)n; i++)
    y[i] =
        distance(cmpsy.begin(), lower_bound(cmpsy.begin(), cmpsy.end(), y[i]));
  for (int i = 0; i < (int)n; i++) xs[y[i]].push_back(x[i]);
  BIT bit;
  bit.init(n);
  long long ans = 0, m = 0;
  for (int j = n - 1; j > -1; j--) {
    sort(xs[j].begin(), xs[j].end());
    if (xs[j].size() == 0) continue;
    for (int i = 0; i < (int)xs[j].size(); i++) {
      int xx = xs[j][i];
      if (!cnt[xx]) {
        cnt[xx] = true;
        m++;
        bit.upd(xx, 1);
      }
    }
    ans += m * (m - 1) / 2 + m;
    for (int i = 1; i < (int)xs[j].size(); i++) {
      int x1 = xs[j][i - 1];
      int x2 = xs[j][i];
      long long mid = bit.sum(x2 - 1) - bit.sum(x1);
      mid = max(0ll, mid);
      ans -= mid * (mid - 1) / 2 + mid;
    }
    int x2 = xs[j][0];
    long long mid;
    if (x2 > 0)
      mid = bit.sum(x2 - 1);
    else
      mid = 0;
    ans -= mid * (mid - 1) / 2 + mid;
    int x1 = xs[j].back();
    mid = bit.sum(n) - bit.sum(x1);
    ans -= mid * (mid - 1) / 2 + mid;
  }
  printf("%lld\n", ans);
}
