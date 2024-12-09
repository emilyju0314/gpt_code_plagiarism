#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
const double Pi = acos(-1);
struct Complex {
  double x, y;
  Complex(double x = 0, double y = 0) : x(x), y(y){};
  inline Complex operator+(const Complex b) const {
    return Complex(x + b.x, y + b.y);
  }
  inline Complex operator-(const Complex b) const {
    return Complex(x - b.x, y - b.y);
  }
  inline Complex operator*(const Complex b) const {
    return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};
namespace FFT {
const double Pi = acos(-1);
const int N = 3e6 + 5;
Complex F[N], G[N];
int r[N];
void FFT(Complex *A, int limit, int type) {
  for (int i = 0; i < limit; i++)
    if (i < r[i]) swap(A[i], A[r[i]]);
  for (int mid = 1; mid < limit; mid <<= 1) {
    Complex Wn(cos(Pi / mid), type * sin(Pi / mid));
    for (int R = mid << 1, j = 0; j < limit; j += R) {
      Complex w(1, 0);
      for (int k = 0; k < mid; k++, w = w * Wn) {
        Complex x = A[j + k], y = w * A[j + mid + k];
        A[j + k] = x + y;
        A[j + mid + k] = x - y;
      }
    }
  }
}
void mul(bool *a, bool *b, int &n, int &m) {
  for (int i = 0; i <= n; i++) F[i].x = a[i];
  for (int i = 0; i <= m; i++) G[i].x = b[i];
  int l = 0;
  int limit;
  for (limit = 1; limit <= m + n; limit *= 2, l++)
    ;
  for (int i = 0; i < limit; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
  FFT(F, limit, 1);
  FFT(G, limit, 1);
  for (int i = 0; i <= limit; i++) F[i] = F[i] * G[i];
  FFT(F, limit, -1);
  for (int i = 0; i <= n + m; i++) a[i] = (int)(F[i].x / limit + 0.5);
  for (int i = 0; i <= limit; i++) F[i].y = G[i].y = F[i].x = G[i].x = 0;
}
}  // namespace FFT
bool a[N], ans[N];
int n, m;
int ansn, an;
void ksm(int x) {
  while (x) {
    if (x & 1) {
      FFT::mul(ans, a, ansn, an);
      ansn += an;
    }
    FFT::mul(a, a, an, an);
    an += an;
    x >>= 1;
  }
}
int main() {
  int N, q;
  scanf("%d%d", &N, &q);
  for (int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    a[x] = 1;
    ans[x] = 1;
    ansn = max(ansn, x);
  }
  an = ansn;
  ksm(--q);
  for (int i = q + 1; i <= ansn + 5; i++) {
    if (ans[i]) {
      printf("%d ", i);
    }
  }
  return 0;
}
