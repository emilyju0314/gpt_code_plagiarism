#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p);
template <class T>
ostream &operator<<(ostream &os, vector<T> &v);
template <class T>
ostream &operator<<(ostream &os, set<T> &v);
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &v);
const int N = 2e5 + 5;
const long long mod = 1e9 + 7;
bool Q;
struct Line {
  mutable long long k, m, p;
  bool operator<(const Line &o) const { return Q ? p < o.p : k < o.k; }
};
struct LineContainer : multiset<Line> {
  const long long inf = LLONG_MAX;
  long long div(long long a, long long b) {
    if (b < 0) a *= -1, b *= -1;
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) {
      x->p = inf;
      return 0;
    }
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(long long k, long long m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  long long query(long long x) {
    if (empty()) {
      return -1e18;
    }
    Q = 1;
    auto l = *lower_bound({0, 0, x});
    Q = 0;
    return l.k * x + l.m;
  }
};
long long a[N];
long long s1[N];
long long s2[N];
long long n;
void TEST_CASES(int cas) {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    s1[i] = s1[i - 1] + a[i];
    s2[i] = s2[i - 1] + a[i] * i;
  }
  long long ans = s2[n];
  LineContainer l;
  for (long long i = 1; i <= n; i++) {
    long long now = s2[i] - s1[i] + l.query(i);
    long long m = s1[i] - s1[i - 1];
    long long c = s2[i - 1] - s2[i] + s1[i];
    l.add(m, c);
    ans = max(ans, now + s2[n] - s2[i]);
  }
  LineContainer l2;
  for (long long i = n; i >= 1; i--) {
    long long now = -s2[i - 1] - s1[i - 1] + s2[n] + l2.query(i);
    long long m = (s1[i] - s1[i - 1]);
    long long c = -s2[i] + s2[i - 1] + s1[i - 1];
    l2.add(m, c);
    ans = max(ans, now + s2[i - 1]);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, cas = 0;
  while (t--) {
    TEST_CASES(++cas);
  }
  return 0;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
  os << "{" << p.first << ", " << p.second << "} ";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> &v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) {
    os << v[i] << " ";
  }
  os << " ]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> &v) {
  os << "[ ";
  for (T i : v) {
    os << i << " ";
  }
  os << " ]";
  return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &v) {
  for (auto i : v) {
    os << "Key : " << i.first << " , Value : " << i.second << endl;
  }
  return os;
}
