#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return SQR(POW(B, P / 2));
}
template <typename T>
inline T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
inline T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline T BMOD(T p, T e, T m) {
  T ret = 1;
  while (e) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
    e >>= 1;
  }
  return (T)ret;
}
int n;
long long int ss[210], dur[210];
map<long long int, int> MP;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &ss[i], &dur[i]);
  }
  set<pair<long long int, pair<long long int, int> > > res;
  res.insert(
      make_pair(100000000000000000LL,
                make_pair(100000000000000000LL + 100000000000000000LL, 0)));
  for (int i = 1; i <= n; i++) {
    long long int st = ss[i];
    long long int en = st + dur[i] - 1;
    int ok = 1;
    for (__typeof(res.begin()) j = res.begin(); j != res.end(); j++) {
      pair<long long int, pair<long long int, int> > id1 = *j;
      long long int fs = id1.first;
      long long int sc = id1.second.first;
      if (st >= fs && st <= sc) {
        ok = 0;
        break;
      }
      if (en >= fs && en <= sc) {
        ok = 0;
        break;
      }
      if (st < fs && en > sc) {
        ok = 0;
        break;
      }
    }
    if (ok == 1) {
      res.insert(make_pair(st, make_pair(en, i)));
    } else {
      long long int nw = 1;
      for (__typeof(res.begin()) j = res.begin(); j != res.end(); j++) {
        pair<long long int, pair<long long int, int> > id1 = *j;
        if (id1.first == nw) {
          nw = id1.second.first + 1;
        } else
          break;
      }
      int fl = 0;
      for (__typeof(res.begin()) j = res.begin(); j != res.end(); j++) {
        pair<long long int, pair<long long int, int> > id1 = *j;
        long long int fs = id1.first;
        if (nw > fs) continue;
        if (nw == fs) {
          nw = id1.second.first + 1;
          continue;
        }
        if (nw + dur[i] - 1 < fs) {
          res.insert(make_pair(nw, make_pair(nw + dur[i] - 1, i)));
          fl = 1;
          break;
        } else
          nw = id1.second.first + 1;
      }
      if (!fl) {
        res.insert(make_pair(nw, make_pair(nw + dur[i] - 1, i)));
      }
    }
  }
  set<pair<int, pair<long long int, long long int> > > ans;
  for (__typeof(res.begin()) j = res.begin(); j != res.end(); j++) {
    pair<long long int, pair<long long int, int> > tmp = *j;
    ans.insert(
        make_pair(tmp.second.second, make_pair(tmp.first, tmp.second.first)));
  }
  for (__typeof(ans.begin()) j = ans.begin(); j != ans.end(); j++) {
    pair<int, pair<long long int, long long int> > tt = *j;
    if (tt.first == 0) continue;
    printf("%lld %lld\n", tt.second.first, tt.second.second);
  }
  return 0;
}
