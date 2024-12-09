#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, i, j, ii, jj, zx, xc, mod[3], hsh[3],
    pp = 300007, t, tes, xr[300009][3], f[300009], p[300009], pi, pas,
    lf[300009], lfi, rg[300009], rgi;
void rec(int q, int w) {
  if (q >= w) {
    return;
  }
  int mid = (q + w) / 2;
  int h = 0, hh = 0;
  pi = 0;
  hsh[0] = hsh[1] = 0;
  lfi = 0;
  for (h = mid; h >= q; h--) {
    if (p[pi] != f[h]) {
      pi++;
      p[pi] = f[h];
      for (hh = 0; hh <= 1; hh++) {
        hsh[hh] = hsh[hh] + xr[pi][hh] * p[pi];
        hsh[hh] %= mod[hh];
      }
    } else {
      for (hh = 0; hh <= 1; hh++) {
        hsh[hh] = hsh[hh] - xr[pi][hh] * p[pi] + mod[hh] * mod[hh];
        hsh[hh] %= mod[hh];
      }
      pi--;
    }
    lfi++;
    lf[lfi] = hsh[0] * (mod[1] + 2) + hsh[1];
  }
  pi = 0;
  hsh[0] = hsh[1] = 0;
  rgi = 0;
  for (h = mid + 1; h <= w; h++) {
    if (p[pi] != f[h]) {
      pi++;
      p[pi] = f[h];
      for (hh = 0; hh <= 1; hh++) {
        hsh[hh] = hsh[hh] + xr[pi][hh] * p[pi];
        hsh[hh] %= mod[hh];
      }
    } else {
      for (hh = 0; hh <= 1; hh++) {
        hsh[hh] = hsh[hh] - xr[pi][hh] * p[pi] + mod[hh] * mod[hh];
        hsh[hh] %= mod[hh];
      }
      pi--;
    }
    rgi++;
    rg[rgi] = hsh[0] * (mod[1] + 2) + hsh[1];
  }
  sort(lf + 1, lf + lfi + 1);
  sort(rg + 1, rg + rgi + 1);
  c = 1;
  d = 1;
  for (h = 1; h <= lfi; h++) {
    while (c <= rgi && rg[c] <= lf[h]) c++;
    while (d <= rgi && rg[d] < lf[h]) d++;
    pas += c - d;
  }
  rec(q, mid);
  rec(mid + 1, w);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> tes;
  mod[0] = 1000000007LL;
  mod[1] = 1000000009LL;
  xr[0][0] = xr[0][1] = 1;
  for (i = 1; i <= 300004; i++) {
    for (j = 0; j <= 1; j++) {
      xr[i][j] = xr[i - 1][j] * pp;
      xr[i][j] %= mod[j];
    }
  }
  for (t = 1; t <= tes; t++) {
    cin >> a;
    for (i = 1; i <= a; i++) {
      cin >> f[i];
    }
    pas = 0;
    rec(1, a);
    cout << pas << endl;
  }
  return 0;
}
