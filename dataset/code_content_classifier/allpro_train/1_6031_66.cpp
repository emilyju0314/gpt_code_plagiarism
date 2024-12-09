#include <bits/stdc++.h>
using namespace std;
inline long long getint() {
  long long _x = 0, _tmp = 1;
  char _tc = getchar();
  while ((_tc < '0' || _tc > '9') && _tc != '-') _tc = getchar();
  if (_tc == '-') _tc = getchar(), _tmp = -1;
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x * _tmp;
}
inline long long add(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x + _y;
  if (_ >= _mod) _ -= _mod;
  return _;
}
inline long long sub(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x - _y;
  if (_ < 0) _ += _mod;
  return _;
}
inline long long mul(long long _x, long long _y,
                     long long _mod = 1000000007ll) {
  long long _ = _x * _y;
  if (_ >= _mod) _ %= _mod;
  return _;
}
long long mypow(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 1ll;
  long long _tmp = mypow(_a, _x / 2, _mod);
  _tmp = mul(_tmp, _tmp, _mod);
  if (_x & 1) _tmp = mul(_tmp, _a, _mod);
  return _tmp;
}
long long mymul(long long _a, long long _x, long long _mod) {
  if (_x == 0) return 0ll;
  long long _tmp = mymul(_a, _x / 2, _mod);
  _tmp = add(_tmp, _tmp, _mod);
  if (_x & 1) _tmp = add(_tmp, _a, _mod);
  return _tmp;
}
inline bool equal(double _x, double _y) {
  return _x > _y - 1e-9 && _x < _y + 1e-9;
}
int __ = 1, _cs;
void build() {}
int ml[] = {1, 2, 4, 8};
int n;
string trans(int x) {
  string ss = "0";
  ss[0] = (char)(x);
  return ss;
}
inline string lea(int aa, int bb, int cc, int kk) {
  return "lea e" + trans(aa + 'a') + "x, [e" + trans(bb + 'a') + "x + " +
         trans(ml[kk] + '0') + "*e" + trans(cc + 'a') + "x]";
}
void init() { n = getint(); }
vector<string> ans, cur;
int bst = 6, r[10];
bool got, tag[10000];
void go(int now, int mx) {
  if (now >= bst || mx > n || got) return;
  if (mx == n) {
    got = true;
    ans = cur;
    bst = now;
    ans.resize(bst);
    return;
  }
  for (int i = 0; i <= now; i++) {
    for (int k = 3; k >= 0; k--) {
      r[now + 1] = ml[k] * r[i];
      if (tag[r[now + 1]]) continue;
      tag[r[now + 1]] = true;
      cur[now] = lea(now + 1, 10, i, k);
      if (r[now + 1] > mx) go(now + 1, r[now + 1]);
      tag[r[now + 1]] = false;
      if (bst == now + 1 || got) return;
    }
    for (int j = 0; j <= now; j++)
      for (int k = 3; k >= 0; k--) {
        r[now + 1] = r[i] + ml[k] * r[j];
        if (tag[r[now + 1]]) continue;
        tag[r[now + 1]] = true;
        cur[now] = lea(now + 1, i, j, k);
        if (r[now + 1] > mx) go(now + 1, r[now + 1]);
        tag[r[now + 1]] = false;
        if (bst == now + 1 || got) return;
      }
  }
}
void solve() {
  cur.resize(6);
  for (bst = 2;; bst++) {
    r[0] = 1;
    for (int i = 1; i < 10; i++) r[i] = 0;
    tag[0] = true;
    tag[1] = true;
    go(0, 1);
    if (got) {
      printf("%d\n", (int)ans.size());
      for (size_t i = 0; i < ans.size(); i++) cout << ans[i] << endl;
      exit(0);
    }
  }
}
int main() {
  build();
  while (__--) {
    init();
    solve();
  }
}
