#include <bits/stdc++.h>
using namespace std;
long long pl, pr, vl, vr, k;
int l[100000], lsz;
int main() {
  cin >> pl >> pr >> vl >> vr >> k;
  long long pl1 = pl, vl1 = vl;
  for (int len = 1; len <= 9; len++) {
    for (int p = 0; p < (1 << len); ++p) {
      int x = 0;
      for (int i = 0; i < len; ++i)
        if (p & (1 << i))
          x = x * 10 + 7;
        else
          x = x * 10 + 4;
      l[lsz++] = x;
    }
  }
  sort(l, lsz + l);
  long long ans = 0;
  for (int i = 0; i + k - 1 < lsz && l[i] <= max(vr, pr); ++i) {
    long long left = l[i], right = l[i + k - 1], lf, rh;
    if (i == 0)
      lf = 0;
    else
      lf = l[i - 1] + 1;
    if (i + k < lsz)
      rh = l[i + k] - 1;
    else
      rh = (1 << 30);
    if (!(min(left, pr) - max(pl, lf) + 1 <= 0 ||
          min(vr, rh) - max(right, vl1) + 1 <= 0)) {
      ans += (min(left, pr) - max(pl, lf) + 1) *
             (min(vr, rh) - max(right, vl1) + 1);
    }
    if (!(min(left, vr) - max(vl, lf) + 1 <= 0 ||
          min(rh, pr) - max(right, pl1) + 1 <= 0)) {
      ans += (min(left, vr) - max(vl, lf) + 1) *
             (min(rh, pr) - max(right, pl1) + 1);
    }
    pl = max(left + 1, pl);
    vl = max(left + 1, vl);
    if (pl > pr || vl > vr) break;
  }
  if (k == 1)
    for (int i = 0; i < lsz; ++i)
      if (pl1 <= l[i] && l[i] <= pr && vl1 <= l[i] && l[i] <= vr) ans--;
  printf("%.20lf",
         (double)ans / ((vr * 1.0 - vl1 + 1.0) * (pr * 1.0 - pl1 + 1.0)));
  return 0;
}
