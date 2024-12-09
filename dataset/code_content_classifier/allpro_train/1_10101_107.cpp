#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '{';
  for (int i = (0), __i = (((int)(vec).size())); i < __i; i++) {
    os << vec[i];
    if (i + 1 != ((int)(vec).size())) os << ',';
  }
  os << '}';
  return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &par) {
  os << '(' << par.first << ',' << par.second << ')';
  return os;
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
template <class T>
T sqr(T x) {
  return x * x;
}
int a[100000];
int pre[100000][18];
int b[100000][18];
int last[100000];
int n, k;
void sort_b(int l1, int d, int lev) {
  if (l1 + d >= n) {
    for (int i = (l1), __i = (n); i < __i; i++) b[i][lev] = b[i][lev - 1];
    return;
  }
  int r1 = l1 + d;
  int l2 = r1;
  int r2 = min(l2 + d, n);
  int l = l1;
  while (l1 < r1 || l2 < r2) {
    if (l1 == r1)
      b[l++][lev] = b[l2++][lev - 1];
    else if (l2 == r2)
      b[l++][lev] = b[l1++][lev - 1];
    else if (b[l1][lev - 1] < b[l2][lev - 1])
      b[l++][lev] = b[l1++][lev - 1];
    else
      b[l++][lev] = b[l2++][lev - 1];
  }
}
int get_res(int l, int r, int L, int R, int lev, int ll) {
  if (L >= n) return 0;
  if (l == L && r == R) {
    int left = l - 1;
    int right = r + 1;
    while (left + 1 != right) {
      int m = (left + right) / 2;
      if (b[m][lev] >= ll)
        right = m;
      else
        left = m;
    }
    return right - l;
  } else {
    int M = (L + R) / 2;
    if (l > M)
      return get_res(l, r, M + 1, R, lev - 1, ll);
    else if (r <= M)
      return get_res(l, r, L, M, lev - 1, ll);
    else
      return get_res(l, M, L, M, lev - 1, ll) +
             get_res(M + 1, r, M + 1, R, lev - 1, ll);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = (0), __i = (n); i < __i; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = (0), __i = (100000); i < __i; i++) last[i] = -1;
  for (int i = (0), __i = (n); i < __i; i++) {
    pre[i][0] = last[a[i]];
    last[a[i]] = i;
  }
  int deg = 1;
  for (int i = (1), __i = (18); i < __i; i++) {
    deg <<= 1;
    for (int j = (0), __j = (n); j < __j; j++) {
      if (pre[j][i - 1] != -1)
        pre[j][i] = pre[pre[j][i - 1]][i - 1];
      else
        pre[j][i] = -1;
    }
    if (deg >= n) break;
  }
  for (int i = (0), __i = (n); i < __i; i++) {
    int kk = k;
    int cur = i;
    int j = 0;
    while (kk > 0 && cur != -1) {
      if (kk & 1) cur = pre[cur][j];
      j++;
      kk >>= 1;
    }
    b[i][0] = cur;
  }
  int d = 1;
  int lev = 1;
  while (d < n) {
    for (int i = 0; i < n; i += 2 * d) sort_b(i, d, lev);
    d <<= 1;
    lev++;
  }
  lev--;
  int q;
  cin >> q;
  int lst = 0;
  for (int i = (0), __i = (q); i < __i; i++) {
    int l, r;
    cin >> l >> r;
    l = (l + lst) % n;
    r = (r + lst) % n;
    if (r < l) swap(l, r);
    lst = get_res(l, r, 0, d - 1, lev, l);
    cout << lst << endl;
  }
  return 0;
}
