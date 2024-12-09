#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using llu = unsigned long long int;
using pii = tuple<lli, lli>;
using piii = tuple<lli, lli, lli>;
using vi = vector<lli>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;
using vb = vector<bool>;
using vvb = vector<vb>;
lli normalize(lli n) {
  if (n == 0) return n;
  bool neg = n < 0;
  if (neg) n = -n;
  lli res = 1;
  for (lli p = 2; p * p <= n; ++p) {
    lli f = 0;
    while (n % p == 0) {
      n /= p;
      f += 1;
    }
    if (f % 2 == 1) res *= p;
  }
  res *= n;
  if (neg) res = -res;
  return res;
}
int main() {
  lli n;
  scanf("%lld", &n);
  vi v(n);
  for (lli i = 0; i < (lli)(n); ++i) scanf("%lld", &v[i]);
  for (lli i = 0; i < (lli)(n); ++i) v[i] = normalize(v[i]);
  unordered_map<lli, lli> reorder;
  lli ind = 0;
  for (lli i = 0; i < (lli)(n); ++i) {
    if (reorder.count(v[i]) == 0) {
      reorder[v[i]] = ind++;
    }
  }
  vi vr(n);
  for (lli i = 0; i < (lli)(n); ++i) vr[i] = reorder[v[i]];
  vi res(n + 1, 0);
  for (lli i = 0; i < (lli)(n); ++i) {
    vb pres(ind, false);
    lli nb = 0;
    bool hasZero = false;
    bool hadZero = false;
    for (lli j = (lli)(i); j < (lli)(n); ++j) {
      if (!hadZero && v[j] == 0) {
        hasZero = true;
        hadZero = true;
      }
      if (!pres[vr[j]]) {
        pres[vr[j]] = true;
        nb += 1;
      }
      if (hasZero && nb >= 2) {
        nb -= 1;
        hasZero = false;
      }
      res[nb] += 1;
    }
  }
  for (lli i = 0; i < (lli)(n); ++i)
    printf("%lld%c", res[i + 1], " \n"[i + 1 == n]);
  return 0;
}
