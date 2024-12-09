#include <bits/stdc++.h>
using namespace std;
const long double pi = 4 * atan((long double)1);
const int mod = 1e9 + 7;
const int nax = 5e5 + 5;
int n, q, t, fac;
int a[nax], sg[nax * 4];
int fpb(int x, int y) {
  if (y == 0) {
    return x;
  }
  return fpb(y, x % y);
}
void upd(int x, int idx, int l, int r, int pos) {
  if (l == idx && r == idx) {
    sg[pos] = x;
  } else {
    int mid = (l + r) / 2;
    if (l <= idx && mid >= idx) {
      upd(x, idx, l, mid, pos * 2);
    } else {
      upd(x, idx, mid + 1, r, pos * 2 + 1);
    }
    sg[pos] = fpb(sg[pos * 2], sg[pos * 2 + 1]);
  }
}
void get(int nL, int nR, int dif, int l, int r, int pos) {
  if (fac >= 2) {
    return;
  }
  if (nL <= l && r <= nR) {
    if (sg[pos] % dif == 0) {
      return;
    } else if (l == r && sg[pos] % dif != 0) {
      fac++;
      return;
    } else {
      if (l - r + 1 != 1) {
        int mid = (l + r) / 2;
        get(nL, nR, dif, l, mid, pos * 2);
        get(nL, nR, dif, mid + 1, r, pos * 2 + 1);
      }
    }
  } else if (r < nL || l > nR) {
    return;
  } else {
    int mid = (l + r) / 2;
    get(nL, nR, dif, l, mid, pos * 2);
    get(nL, nR, dif, mid + 1, r, pos * 2 + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    upd(a[i], i, 1, n, 1);
  }
  cin >> q;
  while (q--) {
    cin >> t;
    if (t == 1) {
      int x, y, z;
      cin >> x >> y >> z;
      fac = 0;
      get(x, y, z, 1, n, 1);
      if (fac < 2) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      int x, y;
      cin >> x >> y;
      upd(y, x, 1, n, 1);
    }
  }
}
