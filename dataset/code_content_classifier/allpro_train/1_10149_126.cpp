#include <bits/stdc++.h>
using namespace std;
struct Matrix {
  int a[2][2];
  Matrix operator*(Matrix A) {
    Matrix B;
    B.a[0][0] =
        ((long long)a[0][0] * A.a[0][0] + (long long)a[0][1] * A.a[1][0]) %
        998244353;
    B.a[0][1] =
        ((long long)a[0][0] * A.a[0][1] + (long long)a[0][1] * A.a[1][1]) %
        998244353;
    B.a[1][0] =
        ((long long)a[1][0] * A.a[0][0] + (long long)a[1][1] * A.a[1][0]) %
        998244353;
    B.a[1][1] =
        ((long long)a[1][0] * A.a[0][1] + (long long)a[1][1] * A.a[1][1]) %
        998244353;
    return B;
  }
};
struct Node {
  int l, r;
  Matrix v;
} t[100005 << 2];
struct Data {
  int va, vb, s, x;
  Data() {}
  Data(int a, int b, int c, int d) {
    va = a, vb = b;
    s = c, x = d;
  }
} a[100005 << 1];
bool cmp(Data a, Data b) {
  return (long long)a.va * b.vb < (long long)a.vb * b.va;
}
int n, x[100005], v[100005], p[100005], cnt, ans;
int Pow(int a, int k) {
  if (!k) return 1;
  int p = Pow(a, k / 2);
  if (k & 1) return (long long)p * p % 998244353 * a % 998244353;
  return (long long)p * p % 998244353;
}
void Build(int q, int l, int r) {
  t[q].l = l, t[q].r = r;
  if (l == r) {
    t[q].v.a[0][0] = t[q].v.a[1][0] =
        (p[l + 1] <= 1 ? 1 - p[l + 1] : 1 - p[l + 1]);
    t[q].v.a[0][1] = t[q].v.a[1][1] = p[l + 1];
    return;
  }
  int mid = (l + r) >> 1;
  Build(q << 1, l, mid);
  Build(q << 1 | 1, mid + 1, r);
  t[q].v = t[q << 1].v * t[q << 1 | 1].v;
}
void Change(int q, int x, int s) {
  if (t[q].l == t[q].r) {
    t[q].v.a[s >> 1][s & 1] = 0;
    return;
  }
  int mid = (t[q].l + t[q].r) >> 1;
  Change(q << 1 | (x > mid), x, s);
  t[q].v = t[q << 1].v * t[q << 1 | 1].v;
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &x[i], &v[i], &p[i]);
    p[i] = (long long)p[i] * Pow(100, 998244353 - 2) % 998244353;
  }
  for (int i = 1; i < n; i++) {
    a[++cnt] = Data(x[i + 1] - x[i], v[i] + v[i + 1], 2, i);
    if (v[i] != v[i + 1]) {
      if (v[i] < v[i + 1])
        a[++cnt] = Data(x[i + 1] - x[i], v[i + 1] - v[i], 0, i);
      else
        a[++cnt] = Data(x[i + 1] - x[i], v[i] - v[i + 1], 3, i);
    }
  }
  sort(a + 1, a + cnt + 1, cmp);
  ans = (long long)a[1].va * Pow(a[1].vb, 998244353 - 2) % 998244353;
  Build(1, 1, n - 1);
  for (int i = 1; i <= cnt; i++) {
    Change(1, a[i].x, a[i].s);
    int m = ((long long)p[1] * (t[1].v.a[1][0] + t[1].v.a[1][1]) +
             (long long)(1 - p[1]) * (t[1].v.a[0][0] + t[1].v.a[0][1])) %
            998244353;
    ans = (ans -
           (long long)a[i].va * Pow(a[i].vb, 998244353 - 2) % 998244353 * m) %
          998244353;
    if (i < cnt)
      ans = (ans + (long long)a[i + 1].va * Pow(a[i + 1].vb, 998244353 - 2) %
                       998244353 * m) %
            998244353;
  }
  if (ans < 0) ans += 998244353;
  printf("%d\n", ans);
}
