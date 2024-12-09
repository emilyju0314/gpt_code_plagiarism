#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

typedef long double D;

const D EPS = 1e-10;

int main() {
  int n;
  cin >> n;
  srand(time(NULL));
  vector<D> x(n), y(n), z(n);
  vector<D> xxx(n), yyy(n), zzz(n);
  rep (i, n) cin >> xxx[i] >> yyy[i] >> zzz[i];
  D res = 0;
  rep (i, n) {
    x[i] = xxx[i] + (D)rand() / RAND_MAX / 1000000;
    y[i] = yyy[i] + (D)rand() / RAND_MAX / 1000000;
    z[i] = zzz[i] + (D)rand() / RAND_MAX / 1000000;
  }
  vector<int> triA, triB, triC;
  rep (i, n) rep (j, i) rep (k, i) if (j != k) {
    D xx = (y[j] - y[i]) * (z[k] - z[i]) - (z[j] - z[i]) * (y[k] - y[i]);
    D yy = (z[j] - z[i]) * (x[k] - x[i]) - (x[j] - x[i]) * (z[k] - z[i]);
    D zz = (x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]);
    bool ok = true;
    rep (l, n) if (i != l && j != l && k != l) {
      if (xx * (x[l] - x[i]) + yy * (y[l] - y[i]) + zz * (z[l] - z[i]) > EPS) {
	ok = false;
	break;
      }
    }
    if (ok) {
      D xxxx = (yyy[j] - yyy[i]) * (zzz[k] - zzz[i]) - (zzz[j] - zzz[i]) * (yyy[k] - yyy[i]);
      D yyyy = (zzz[j] - zzz[i]) * (xxx[k] - xxx[i]) - (xxx[j] - xxx[i]) * (zzz[k] - zzz[i]);
      D zzzz = (xxx[j] - xxx[i]) * (yyy[k] - yyy[i]) - (yyy[j] - yyy[i]) * (xxx[k] - xxx[i]);
      res += sqrt(xxxx * xxxx + yyyy * yyyy + zzzz * zzzz) / 2;
    }
  }
  printf("%.12Lf\n", res);
  return 0;
}