#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x < y ? x - y + mod : x - y; }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int qpow(int n, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = mul(ret, n);
    n = mul(n, n);
    k >>= 1;
  }
  return ret;
}
int n, k, m;
const int N = 250;
struct poly {
  int a[N + 10];
  poly() { memset(a, 0, sizeof(a)); }
  int& operator[](int x) { return a[x]; }
} f[N + 10][N + 10], g[N + 10][N + 10], fc[N + 10];
poly operator+(poly a, poly b) {
  poly ret;
  for (int i = 1; i <= m - 1; ++i) ret[i] = add(a[i], b[i]);
  return ret;
}
poly operator-(poly a, poly b) {
  poly ret;
  for (int i = 1; i <= m - 1; ++i) ret[i] = dec(a[i], b[i]);
  return ret;
}
poly operator*(poly a, int k) {
  for (int i = 1; i <= m - 1; ++i) a[i] = mul(a[i], k);
  return a;
}
void print(poly a) {
  for (int i = 1; i <= m - 1; ++i) {
    printf("%d ", a[i]);
  }
  puts("");
}
int ans[N + 10];
void gauss(int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      if (fc[j][i]) {
        for (int k = 1; k <= n + 1; ++k) {
          swap(fc[j][k], fc[i][k]);
        }
        break;
      }
    }
    if (!fc[i][i]) {
      puts("����������������ͷ�ӻ��ú�");
      return;
    }
    int div = qpow(fc[i][i], mod - 2);
    for (int j = 1; j <= n + 1; ++j) {
      fc[i][j] = mul(fc[i][j], div);
    }
    for (int j = i + 1; j <= n; ++j) {
      int sb = fc[j][i];
      for (int k = 1; k <= n + 1; ++k) {
        fc[j][k] = dec(fc[j][k], mul(sb, fc[i][k]));
      }
    }
  }
  for (int i = n; i >= 1; --i) {
    ans[i] = fc[i][n + 1];
    for (int j = i + 1; j <= n; ++j) {
      ans[i] = dec(ans[i], mul(ans[j], fc[i][j]));
    }
  }
}
int inv[N + 10];
void init() {
  inv[1] = 1;
  for (int i = 2; i <= N; ++i)
    inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
}
int main() {
  init();
  scanf("%d%d%d", &n, &k, &m);
  if (k == 1 || k == n) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 3; i <= m; ++i) {
    f[i][2][i - 2] = 1;
  }
  for (int j = 2; j <= m; ++j) {
    poly pre;
    for (int i = j + 1; i <= m; ++i) {
      poly now = f[i][j];
      now[m - 1] = dec(now[m - 1], mul(i + 1, mul(i, mul(inv[m], inv[i - 1]))));
      now = now - (pre + g[i - 1][j - 1]) * (mul(i, mul(inv[m], inv[i - 1])));
      if (i == m) {
        fc[j - 1] = now;
        fc[j - 1][m - 1] = dec(mod, fc[j - 1][m - 1]);
        break;
      }
      now = now -
            f[i + 1][j] * (mul(m - i, mul(i + 1 - j, mul(inv[i + 1], inv[m]))));
      now = now * (mul(m, mul(i + 1, mul(inv[m - i], inv[j]))));
      f[i + 1][j + 1] = now;
      pre = pre + f[i][j];
      g[i][j] = g[i - 1][j - 1] + f[i][j];
    }
  }
  gauss(m - 2);
  int Ans = 0;
  for (int i = 1; i <= m - 2; ++i) {
    Ans = add(Ans, mul(ans[i], f[n][k][i]));
  }
  Ans = add(Ans, f[n][k][m - 1]);
  printf("%d\n", Ans);
}
