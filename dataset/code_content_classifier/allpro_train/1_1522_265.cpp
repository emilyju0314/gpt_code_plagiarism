#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
int n, m;
char buf[20];
vector<pair<long long, char> > vs, vt;
const long long MOD = 1000000007;
const long long B = 8101919;
long long fac[200200];
inline long long _plus(long long a, long long b) { return (a + b) % MOD; }
inline long long _minus(long long a, long long b) {
  return ((a - b) % MOD + MOD) % MOD;
}
inline long long _mul(long long a, long long b) { return (a * b) % MOD; }
void preculc() {
  fac[0] = 1ll;
  for (int i = 1; i < 200100; i++) fac[i] = _mul(fac[i - 1], B);
}
int main() {
  scanf("%d %d", &n, &m);
  preculc();
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    int len = strlen(buf);
    int num = 0;
    for (int j = 0; j < len - 2; j++) {
      num *= 10;
      num += (int)(buf[j] - '0');
    }
    if (!vt.empty() && vt.back().second == buf[len - 1])
      vt.back().first += num;
    else
      vt.push_back(pair<long long, char>(num, buf[len - 1]));
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", buf);
    int len = strlen(buf);
    int num = 0;
    for (int j = 0; j < len - 2; j++) {
      num *= 10;
      num += (int)(buf[j] - '0');
    }
    if (!vs.empty() && vs.back().second == buf[len - 1])
      vs.back().first += num;
    else
      vs.push_back(pair<long long, char>(num, buf[len - 1]));
  }
  int lt = ((int)(vt).size()), ls = ((int)(vs).size());
  if (lt < ls) {
    printf("0\n");
    return 0;
  }
  long long ans = 0ll;
  if (ls >= 3) {
    long long ha = 0ll, hb = 0ll, ta = 0ll, tb = 0ll;
    for (int i = 1; i < ls - 1; i++) {
      ha = _plus(vs[i].first, _mul(ha, B));
      hb = _plus(vs[i].second, _mul(hb, B));
      ta = _plus(vt[i - 1].first, _mul(ta, B));
      tb = _plus(vt[i - 1].second, _mul(tb, B));
    }
    for (int i = 0; i < lt; i++) {
      if (ha == ta && hb == tb) {
        if (i == 0 || i + ls - 2 >= lt) goto next;
        if (!(vt[i - 1].second == vs[0].second &&
              vt[i - 1].first >= vs[0].first))
          goto next;
        if (!(vt[i + ls - 2].second == vs[ls - 1].second &&
              vt[i + ls - 2].first >= vs[ls - 1].first))
          goto next;
        ans++;
      }
    next:;
      if (i + ls - 2 >= lt) break;
      ta = _minus(ta, _mul(vt[i].first, fac[ls - 3]));
      tb = _minus(tb, _mul(vt[i].second, fac[ls - 3]));
      ta = _mul(ta, B);
      tb = _mul(tb, B);
      ta = _plus(ta, vt[i + ls - 2].first);
      tb = _plus(tb, vt[i + ls - 2].second);
    }
  }
  if (ls == 2) {
    for (int i = 0; i < lt - 1; i++) {
      if (!(vs[0].second == vt[i].second && vs[1].second == vt[i + 1].second))
        continue;
      if (vs[0].first <= vt[i].first && vs[1].first <= vt[i + 1].first) ans++;
    }
  }
  if (ls == 1) {
    for (int i = 0; i < lt; i++) {
      if (vs[0].second == vt[i].second && vs[0].first <= vt[i].first) {
        ans += vt[i].first - vs[0].first + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
