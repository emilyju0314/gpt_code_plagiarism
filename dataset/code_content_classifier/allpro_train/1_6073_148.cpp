#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
struct BIT {
  int _n;
  long long _d[SIZE];
  void init(int __n) {
    _n = __n;
    memset(_d, 0, sizeof(long long) * (_n + 1));
  }
  void ins(int x, long long v) {
    for (; x <= _n; x += x & -x) _d[x] += v;
  }
  long long qq(int x) {
    long long res = 0;
    for (; x; x -= x & -x) res += _d[x];
    return res;
  }
  long long qq_range(int x, int y) {
    long long ret = qq(y);
    if (x) ret -= qq(x - 1);
    return ret;
  }
} bit;
int p[SIZE], pos[SIZE];
int main() {
  int n;
  R(n);
  for (int i = (1); i <= (n); ++i) {
    R(p[i]);
    pos[p[i]] = i;
  }
  vector<long long> an;
  bit.init(n);
  long long now = 0;
  set<int> ll, rr;
  long long ss = 0;
  for (int i = (1); i <= (n); ++i) {
    now += bit.qq(n + 1 - pos[i]);
    bit.ins(n + 1 - pos[i], 1);
    if (((int)(ll).size()) <= ((int)(rr).size())) {
      ll.insert(pos[i]);
      ss -= pos[i];
    } else {
      rr.insert(pos[i]);
      ss += pos[i];
    }
    while (((int)(rr).size()) && *ll.rbegin() > *rr.begin()) {
      int x = *ll.rbegin();
      int y = *rr.begin();
      ll.erase(prev(ll.end()));
      rr.erase(rr.begin());
      ss += (x - y) * 2;
      ll.insert(y);
      rr.insert(x);
    }
    long long v = ss;
    if (((int)(ll).size()) > ((int)(rr).size())) {
      v += *ll.rbegin();
      v -= (i + 1LL) * (i / 2) / 2;
    } else {
      v -= (long long)i * (i / 2) / 2;
    }
    an.push_back(now + v);
  }
  W(an);
  return 0;
}
