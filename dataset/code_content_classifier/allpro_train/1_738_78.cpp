#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 100005;
struct Matrix {
  long long n, m;
  long long a[2][2];
  Matrix() {
    n = 2, m = 2;
    a[0][0] = 1;
    a[0][1] = 0;
    a[1][0] = 0;
    a[1][1] = 1;
  }
  void clear() {
    n = m = 0;
    memset(a, 0, sizeof(a));
  }
  Matrix iden() {
    memset((*this).a, 0, sizeof((*this).a));
    (*this).m = n;
    (*this).n = n;
    for (long long i = 0; i < n; ++i) (*this).a[i][i] = 1;
    return *this;
  }
  Matrix operator+(const Matrix &b) const {
    Matrix tmp;
    tmp.n = n;
    tmp.m = m;
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < m; ++j)
        tmp.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
    return tmp;
  }
  Matrix operator*(const Matrix &b) const {
    Matrix tmp;
    tmp.clear();
    tmp.n = n;
    tmp.m = b.m;
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < b.m; ++j)
        for (long long k = 0; k < m; ++k)
          tmp.a[i][j] =
              (tmp.a[i][j] + ((a[i][k]) * (b.a[k][j])) % mod + mod) % mod;
    return tmp;
  }
  Matrix qpow(long long t) {
    Matrix ans, temp = (*this);
    while (t) {
      if (t & 1) ans = ans * temp;
      t >>= 1;
      temp = temp * temp;
    }
    return ans;
  }
  void print() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) printf("%lld ", a[i][j]);
      printf("\n");
    }
  }
};
Matrix fib;
Matrix tree[maxn << 2];
Matrix lazy[maxn << 2];
void pushup(int i) { tree[i] = tree[i << 1] + tree[i << 1 | 1]; }
void pushdown(int i) {
  tree[i << 1] = tree[i << 1] * lazy[i];
  tree[i << 1 | 1] = tree[i << 1 | 1] * lazy[i];
  lazy[i << 1] = lazy[i << 1] * lazy[i];
  lazy[i << 1 | 1] = lazy[i << 1 | 1] * lazy[i];
  lazy[i].iden();
}
void build(int i, int L, int R) {
  if (L == R) {
    int a;
    scanf("%d", &a);
    tree[i] = fib.qpow(a - 1);
    return;
  }
  int mid = (L + R) >> 1;
  build(i << 1, L, mid);
  build(i << 1 | 1, mid + 1, R);
  pushup(i);
}
void update(Matrix x, int l, int r, int i, int L, int R) {
  if (l <= L && R <= r) {
    tree[i] = tree[i] * x;
    lazy[i] = lazy[i] * x;
    return;
  }
  pushdown(i);
  int mid = (L + R) >> 1;
  if (l <= mid) update(x, l, r, i << 1, L, mid);
  if (r > mid) update(x, l, r, i << 1 | 1, mid + 1, R);
  pushup(i);
}
long long query(int l, int r, int i, int L, int R) {
  long long ans = 0;
  if (l <= L && R <= r) {
    return ans = tree[i].a[0][0];
  }
  pushdown(i);
  int mid = (L + R) >> 1;
  if (l <= mid) ans = (ans + query(l, r, i << 1, L, mid)) % mod;
  if (r > mid) ans = (ans + query(l, r, i << 1 | 1, mid + 1, R)) % mod;
  pushup(i);
  return ans;
}
int n, m, c, l, r, x;
int main() {
  fib.n = fib.m = 2;
  fib.a[0][0] = 1;
  fib.a[0][1] = 1;
  fib.a[1][0] = 1;
  fib.a[1][1] = 0;
  scanf("%d%d", &n, &m);
  build(1, 1, n);
  for (int i = 0; i < m; i++) {
    scanf("%d", &c);
    if (c == 1) {
      scanf("%d%d%d", &l, &r, &x);
      update(fib.qpow(x), l, r, 1, 1, n);
    } else {
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(l, r, 1, 1, n));
    }
  }
  return 0;
}
